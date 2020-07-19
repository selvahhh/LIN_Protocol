/**
******************************************************************************
* @file    main.c
* @author  Selva He
* @version V0.1
* @date    7-Dec-2017
* @brief   Three versions:NFC only, U4C only, NFC with U4C. each version can be enabled in hal.h file.
*          
******************************************************************************
*/ 

//#include "stm8s.h"
//#include "hal.h"
//#include "paj7620u2.h"
#include "Lin_Driver.h"
//#include "setMode.h"


event mode;
LRtype lrTypeSel;
uint8_t u8TempVar = 0;
uint16_t u16TempCrc16Value = 0;

uint8_t TPS_u8TpsInitHeader[3] = {TPS_WRITE_CMD_ONE_BYTE,TPS_BRODCAST_WRITE_ID,TPS_SYSCFG_ADDR};
uint8_t TPS_u8SysCfg[1] = {0x84};
uint8_t TPS_u8Data[2] = {0,0};
uint8_t TPS_u8DataInit[4] = {0x00,0x00,0x00,0x02}; //Phase + Width
uint8_t TPS_u8InfoFrame[9]={0,0,0,0,0,0,0,0,0}; //Header:3, Data:4, CRC16:2

uint8_t *CRC16_u8Value=NULL;
uint8_t *Tps_u8LedPosDeviceId=NULL;
uint8_t Tps_u8LedMatrixI = 0;

uint16_t u16AdcValue=0;
uint16_t u16AdcValueStore=0;
bool     bRelayTrigger = false;
bool     bButtonControlTrigger = false;
uint8_t u8UartMessage[8]={0xff};
uint8_t u8UartIcounter = 0;



void delay_nms(uint16_t n)
{
  TIM1->ARRH = (uint8_t)(DELAY_TIMER1_CNT >> 8);
  TIM1->ARRL = (uint8_t)(DELAY_TIMER1_CNT);
  TIM1->PSCRH = (uint8_t)(DELAY_TIMER1_PRD >> 8);
  TIM1->PSCRL = (uint8_t)(DELAY_TIMER1_PRD);	
  TIM1->IER &=0x00;
  TIM1->CR1 |= 0x01;
  TIM1->SR1 = 0x00;
  while(n)
  {
    while(!(TIM1->SR1&0x01))   WDG_RLOAD;
    TIM1->SR1&=(~(0x01));
    n--;
  }
  TIM1->CR1 &= 0x00;            //Disable timer1 counter function
  
}

void main( void )
{ 
  Mcu_init();
  delay_nms(200);
  Uart_vidResetUart();
  //Timer2_Config(); 
  //IWDG_Config();
  delay_nms(800);
  Tps_RunMode();
  UART1_ITConfig(UART1_IT_RXNE_OR,ENABLE);
  while(1)
  {
    //WDG_RLOAD;
    //Mcu_AdcRun();
    //Tps_RunMode();
    //delay_nms(50);
    GPIO_WriteHigh(GPIOC,GPIO_PIN_3);                    
  }   
}
#ifdef USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param file: pointer to the source file name
  * @param line: assert_param error line source number
  * @retval : None
  */
void assert_failed(u8* file, u32 line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}

#endif
