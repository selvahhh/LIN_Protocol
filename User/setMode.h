//#include "hal.h"
#include "stm8s.h"
//#include "Tps_Driver.h"

#define LEFT 0
#define RIGHT 1

#define ANGEL_0 0       //Angel 0
#define ANGEL_1 1       //Angel 1(Left -0.7, Right -1.4)
#define ANGEL_2 2
#define ANGEL_3 3
#define ANGEL_4 4
#define ANGEL_5 5
#define ANGEL_6 6
#define ANGEL_7 7
#define ANGEL_8 8
#define ANGEL_9 9
#define ANGEL_10 10

#define ADB_LINE_1_MIN 0        //ADB line 1
#define ADB_LINE_1_MAX 1 
#define ADB_LINE_2_MIN 2
#define ADB_LINE_2_MAX 3
#define ADB_LINE_3_MIN 4
#define ADB_LINE_4_MIN 5
#define ADB_LINE_4_MAX 6
#define ADB_LINE_5_MIN 7
#define ADB_LINE_6_MIN 8        //ADB line 6

//#define COUNTRY 0
//#define TOWN 1
//#define MOTORWAY_LB 2
//#define HIGH_BEAM 3
//#define MOTROWAY_HB 4
//#define ADB 5

typedef enum scenceMode{
  COUNTRY = 0,
  TOWN = 1,
  MOTORWAY_LB = 2,
  HIGH_BEAM = 3,
  MOTROWAY_HB = 4,
  ADB = 5,
  STREAM = 6 
}scenceMode;

void User_vidSetMode(scenceMode enumScenceMode,
                     uint16_t u8unit1,uint16_t u8unit2,uint16_t u8unit3,uint16_t u8unit4,
                     uint16_t u8unit5,uint16_t u8unit6,uint16_t u8unit7,uint16_t u8unit8,
                     uint16_t u8unit9,uint16_t u8unit10,uint16_t u8unit11,uint16_t u8unit12,
                     uint16_t u8unit13,uint16_t u8unit14,uint16_t u8unit15,uint16_t u8unit16);

void User_vidHighBeam(uint8_t u8LRselection);
void User_vidCountry(uint8_t u8LRselection, uint8_t u8AngleSelection);
void User_vidAdb(uint8_t u8LRselection, uint8_t u8AdbLineSelection);
void User_vidLedOff();

extern uint16_t TPS_u8WidthData[32];