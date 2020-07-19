#include "stm8s.h"
#include "hal.h"
#include "setMode.h"
//#include "paj7620u2.h"

#define TPS_LED_POSTION_MAX_ID_000      31
#define PHASE_REG_DEVIDE_POINT         0

#define TPS_LED0_PWM_WIDTH      307     //(int(0.3*1023)) //U001 8
#define TPS_LED1_PWM_WIDTH      378     //(int(0.37*1023)) //U001 9   
#define TPS_LED2_PWM_WIDTH      501     //(int(0.49*1023)) //U001 10
#define TPS_LED3_PWM_WIDTH      573     //(int(0.56*1023)) //U001 11
#define TPS_LED4_PWM_WIDTH      716     //(int(0.70*1023)) //U010 0
#define TPS_LED5_PWM_WIDTH      1023    //(int(1*1023)) //U010 1
#define TPS_LED6_PWM_WIDTH      1023    //(int(1*1023)) //U010 2
#define TPS_LED7_PWM_WIDTH      1023    //(int(1*1023)) //U010 3
#define TPS_LED8_PWM_WIDTH      880     //(int(0.86*1023)) //U010 4
#define TPS_LED9_PWM_WIDTH      736     //(int(0.72*1023)) //U010 5
#define TPS_LED10_PWM_WIDTH      614    //(int(0.60*1023)) //U010 6
#define TPS_LED11_PWM_WIDTH      532    //(int(0.52*1023)) //U010 7
#define TPS_LED12_PWM_WIDTH      491    //(int(0.48*1023)) //U010 8
#define TPS_LED13_PWM_WIDTH      399    //(int(0.39*1023)) //U010 9
#define TPS_LED14_PWM_WIDTH      440    //(int(0.43*1023)) //U010 10
#define TPS_LED15_PWM_WIDTH      338    //(int(0.33*1023)) //U010 11
#define TPS_LED16_PWM_WIDTH      307    //(int(0.30*1023)) //U001 7
#define TPS_LED17_PWM_WIDTH      379    //(int(0.37*1023)) //U001 6
#define TPS_LED18_PWM_WIDTH      501    //(int(0.49*1023)) //U001 5
#define TPS_LED19_PWM_WIDTH      573    //(int(0.56*1023)) //U001 4
#define TPS_LED20_PWM_WIDTH      716    //(int(0.70*1023)) //U000 11
#define TPS_LED21_PWM_WIDTH      1023   //(int(1*1023)) //U000 10
#define TPS_LED22_PWM_WIDTH      1023   //(int(1*1023)) //U000 9
#define TPS_LED23_PWM_WIDTH      1023   //(int(1*1023)) //U000 8
#define TPS_LED24_PWM_WIDTH      880    //(int(0.86*1023)) //U000 7
#define TPS_LED25_PWM_WIDTH      737    //(int(0.72*1023)) //U000 6
#define TPS_LED26_PWM_WIDTH      614    //(int(0.60*1023)) //U000 5
#define TPS_LED27_PWM_WIDTH      532    //(int(0.52*1023)) //U000 4
#define TPS_LED28_PWM_WIDTH      491    //(int(0.48*1023)) //U000 3
#define TPS_LED29_PWM_WIDTH      399    //(int(0.39*1023)) //U000 2
#define TPS_LED30_PWM_WIDTH      440    //(int(0.43*1023)) //U000 1
#define TPS_LED31_PWM_WIDTH      338    //(int(0.33*1023)) //U000 0

void Tps_vidSendBytes(uint8_t u8Bytes,uint8_t *pu8SendByes);
extern uint32_t u32Obj;
