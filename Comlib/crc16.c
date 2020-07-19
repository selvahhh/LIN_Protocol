#include "hal.h"

//extern uint16_t u16TempCrc16Value;
uint16_t Crc16_u16CalCrc16(uint8_t *u8Packet,uint8_t u8Number)
{
  uint8_t u8CountNumber;
  uint16_t u16CrcValue =0;
  u16CrcValue = CRC16_PRESET;
  for(u8CountNumber = 0;u8CountNumber<u8Number;u8CountNumber++)
  {
    uint8_t u8CountBit = CRC16_BITS;
    u16CrcValue ^= *(u8Packet+u8CountNumber);
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
  return u16CrcValue;
}