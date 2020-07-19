
#include "Lin_Driver.h"


uint8_t u8LedPosDeviceId[2] = {0,0};    //0: uinitLEDpOS, 1: deviceid
uint8_t u8LedPostionId001[8] = {19,18,17,16,0,1,2,3};
uint8_t u8StoreCrc[2] = {0,0};
//extern uint8_t *Tps_u8LedPosDeviceId;
uint8_t u8CountGestture = 0;
uint8_t u8TransmitData;

uint16_t TPS_u8WidthData[32] = {0};


extern uint8_t TPS_u8TpsInitHeader[3];
extern uint8_t TPS_u8SysCfg[1];


/**********************
u8Header TPS header(lmm + device id + regaddr)
u8Packet TPS data
************************/
uint8_t *Tps_u8CalCrc16(uint8_t *u8Header,uint8_t *u8Packet,uint8_t u8NumberHeader,uint8_t u8NumberPacket)
{
  uint8_t u8CountNumber;
  uint16_t u16CrcValue = 0;
  u16CrcValue = CRC16_PRESET;
  for(u8CountNumber = 0;u8CountNumber<(u8NumberHeader+u8NumberPacket);u8CountNumber++)
  {
    uint8_t u8CountBit = CRC16_BITS;
    if(u8CountNumber<u8NumberHeader)
    {
      u16CrcValue ^= *(u8Header+u8CountNumber);
    }
    else
    {
      u16CrcValue ^= *(u8Packet+u8CountNumber-u8NumberHeader);
    }
    while(u8CountBit)
    {
      u8CountBit--;
      if(u16CrcValue & 0x01)
      {
        u16CrcValue = (u16CrcValue>>1)^CRC16_POLYNOM;
      }
      else
      {
        u16CrcValue = (u16CrcValue>>1)^0;
      }
    }
  }
  u8StoreCrc[0] = (uint8_t)u16CrcValue;
  u8StoreCrc[1] = (uint8_t)(u16CrcValue>>8);
  return u8StoreCrc;
}

void Tps_vidSendBytes(uint8_t u8Bytes,uint8_t *pu8SendByes)
{
  uint8_t u8CountBytes;
  //uint8_t u8TransmitData;
  for(u8CountBytes=0;u8CountBytes<u8Bytes;u8CountBytes++)
  {
    while(UART1_GetFlagStatus(UART1_FLAG_TXE) == RESET)
    {
    }
    u8TransmitData = *(pu8SendByes+u8CountBytes);
    UART1_SendData8(u8TransmitData);

  }
}





void Tps_RelayContol(void)
{
  GPIO_WriteLow(GPIOC,GPIO_PIN_3);                          //Relay working to cut off power supply
  delay_nms(200);
  GPIO_WriteHigh(GPIOC,GPIO_PIN_3);                          //Relay no working to switch on power supply
  delay_nms(600);
}

void Tps_RunMode()
{ 
  
  Tps_vidSendBytes(8,u8LedPostionId001);
  

}