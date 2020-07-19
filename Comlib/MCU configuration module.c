#include "hal.h"


/*************************************************
Sub Function: 


**************************************************/
void CLK_Config(void)
{
  CLK->CKDIVR = 0x00;
}

void UART1_Config(void)
{
  /* UART1 configured as follow:
          - Word Length = 8 Bits
          - 1 Stop Bit
          - No parity
          - BaudRate = 500000 baud
          - UART1 Clock enabled
          - Polarity Low
          - Phase Middle
          - Last Bit enabled
          - Receive and transmit enabled
   */
  UART1_DeInit();
  UART1_Init((uint32_t)9600, UART1_WORDLENGTH_8D, UART1_STOPBITS_1, UART1_PARITY_NO, 
              (UART1_SyncMode_TypeDef)(UART1_SYNCMODE_CLOCK_DISABLE | UART1_SYNCMODE_CPOL_LOW |UART1_SYNCMODE_CPHA_MIDDLE |UART1_SYNCMODE_LASTBIT_ENABLE),
              UART1_MODE_TXRX_ENABLE);
  UART1_Cmd(DISABLE);
}
/*************************************************
Sub Function: 


**************************************************/
void GPIO_Config(void)
{
  GPIOA->DDR =(uint8_t) 0x08;           //PA3 input for LH and RH desision
  GPIOA->CR1 =(uint8_t) 0x08;           //pull-up, push-pull
  GPIOA->CR2 =(uint8_t) 0x08;           //
  
  GPIOC->DDR =(uint8_t) 0x08;           //PC7 for input,PC6 intput,PC5 intput,PC4 AD,PC3 output for driving relay
  GPIOC->CR1 =(uint8_t) 0xE8;           //pull-up, push-pull
  GPIOC->CR2 =(uint8_t) 0xE0;           //PC7,PC6,PC5 intput Interrupt enabled
  
  GPIOD->DDR =(uint8_t) 0x20;           //PD3,PD2input,floating,PD5 output
  GPIOD->CR1 =(uint8_t) 0x20;           //pull-up
  GPIOD->CR2 =(uint8_t) 0x20;           //PD4,PD3,PD2interrupt
  //EXTI->CR1 = 0x80;                   //PD port external interrupt falling edge
  //EXTI->CR1 = 0x20;                   //PC port external interrupt falling edge
  //EXTI->CR1 = 0xa0;                     //PD and PC port external interrupt falling edge
}

/*************************************************
Sub Function: 


**************************************************/
void Mcu_vidPortIntEnable(void)
{
  GPIOC->CR2 |= 0xE0;           //PC7,PC6,PC5 intput Interrupt enabled
  GPIOD->CR2 |= 0x1C;           //PD4,PD3,PD2interrupt
  //EXTI->CR1 |= 0xa0;                     //PD and PC port external interrupt falling edge
}

/*************************************************
Sub Function: 


**************************************************/
void Mcu_vidPortIntDisable(void)
{
  GPIOC->CR2 &= 0x1F;           //PC7,PC6,PC5 intput Interrupt disabled
  GPIOD->CR2 &= 0xE3;           //PD4,PD3,PD2 interrupt disabled
  //EXTI->CR1 &= 0x5F;                     //PD and PC port external interrupt falling edge
}

/*************************************************
Sub Function: 


**************************************************/
void ADC_Config(void)
{  
  ADC1->CSR &= (uint8_t)(~ADC1_CSR_CH);
  ADC1->CSR |= ADC1_CHANNEL_2;          //AIN4
  ADC1->CR1 = 0x42;                     //fcpu/8 ,continuous mode,converter off
  ADC1->CR2 = 0x08;                     //right alignment, internal clock,no scan mode
  ADC1->CR1 |=ADC1_CR1_ADON;            //AD enable
}

/*************************************************
Sub Function: 


**************************************************/
void Timer1_Counter_Config(void)
{	
  TIM1->ARRH = (uint8_t)(TIMER1_CNT >> 8);
  TIM1->ARRL = (uint8_t)(TIMER1_CNT);
  TIM1->PSCRH = (uint8_t)(TIMER1_PRD >> 8);
  TIM1->PSCRL = (uint8_t)(TIMER1_PRD);	
  TIM1->RCR = 0x00;
  TIM1->IER =0X00;      
  TIM1->CR1 = 0x00;
  	
  
}

/*************************************************
Sub Function: 


**************************************************/
void Timer1_PWM_Config(void)
{
  TIM1->IER =0x00;
  TIM1->PSCRH = 0x00;
  TIM1->PSCRL = 0x00;
  TIM1->ARRH = (uint8_t)(PWM_FREQ >> 8);
  TIM1->ARRL = (uint8_t)(PWM_FREQ);
  
}

/*************************************************
Sub Function: 


**************************************************/
void Timer2_Config(void)
{
  TIM2->PSCR = 0x00;
  TIM2->ARRH = (uint8_t)(TIMER2_ARR >> 8);
  TIM2->ARRL = (uint8_t)(TIMER2_ARR);
  TIM2->CCER2 = 0x03;
  TIM2->CCMR3 = 0x78;
  TIM2->CCR3H = (uint8_t)(TIMER2_ARR >> 8);     //100% duty cycle for minmum current.
  TIM2->CCR3L = (uint8_t)(TIMER2_ARR );
  TIM2->CR1 |= (uint8_t)TIM2_CR1_CEN;    
}

/*************************************************
Sub Function: 


**************************************************/
void Time4_Config(void)
{
  TIM4_TimeBaseInit(TIM4_PRESCALER_16,TIMER4_CNT_1);
  TIM4->IER|=0X01;    
}

/* -------------------------------------------------------------------------- */
/* ROUTINE NAME: void IWDG_Config(void)                                       */
/* INPUT/OUTPUT: None.                                                        */
/* DESCRIPTION:  Initialize the IWDG for 31.25ms                              */
void IWDG_Config(void)
{
  /* IWDG timeout equal to 32 ms (the timeout may varies due to LSI frequency
  dispersion) */
  /* Enable write access to IWDG_PR and IWDG_RLR registers */
  //IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);
  IWDG->KR = (uint8_t)0x55;//	
  /* IWDG counter clock: LSI/16 */
  IWDG_SetPrescaler(IWDG_Prescaler_256);
  //IWDG->PR = (uint8_t)0x05;//20140228		
  /* Set counter reload value to obtain 31.25ms IWDG TimeOut.
  Counter Reload Value = 32ms/IWDG counter clock period
  = 32ms / (LSI/32)
  = 0.032s / (LsiFreq/32)
  = LsiFreq/(32 * 31.25)
  = LsiFreq/1000												
  LsiFreq = 128000Hz ,LsiFreq/1000=128 
  */
  IWDG_SetReload(255);
  //IWDG->RLR = 255;//	
  /* Reload IWDG counter */
  //IWDG_ReloadCounter();
  IWDG->KR = (uint8_t)0xAA;//	
  /* Enable IWDG (the LSI oscillator will be enabled by hardware) */
  //IWDG_Enable();
  IWDG->KR = (uint8_t)0xCC;//20140228	
}

/*************************************************
Sub Function: 


**************************************************/
void Flash_Config(void)
{
  FLASH_DeInit();
  /* Define FLASH programming time */
  FLASH_SetProgrammingTime(FLASH_PROGRAMTIME_STANDARD);
  /* Unlock Data memory */
  FLASH_Unlock(FLASH_MEMTYPE_DATA);
		
}

/*************************************************
Sub Function: 


**************************************************/
void Write_Flash_Byte(uint32_t add, uint8_t value)
{
  FLASH_ProgramByte(add, value);
}

/*************************************************
Sub Function: 


**************************************************/
uint8_t Read_Flash_Byte(uint32_t add)
{
  return FLASH_ReadByte(add);
}

/*************************************************
Sub Function: 


**************************************************/
uint16_t get_adc_result(uint8_t adc_channel_no)
{
	
  assert_param(IS_ADC1_CHANNEL_OK(adc_channel_no));
  /* Clear the ADC1 channels */
  ADC1->CSR &= (uint8_t)(~ADC1_CSR_CH);
  /* Select the ADC1 channel */
  ADC1->CSR |= (uint8_t)(adc_channel_no);
  //ADC_Config(adc_channel_no);
  ADC1_StartConversion();
  while(!(ADC1->CSR & 0x80));    
  ADC1->CR1 &= (uint8_t)(~ADC1_CR1_ADON);       //stop conversion
  ADC1->CSR &= 0x7F;                            //clear flag// wait adc end 
  return(ADC1_GetConversionValue());
  
}