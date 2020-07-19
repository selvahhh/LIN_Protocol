#include "setMode.h"
//#include "Tps_Driver.h"


void User_vidSetMode(scenceMode enumScenceMode,
                     uint16_t u8unit1,uint16_t u8unit2,uint16_t u8unit3,uint16_t u8unit4,
                     uint16_t u8unit5,uint16_t u8unit6,uint16_t u8unit7,uint16_t u8unit8,
                     uint16_t u8unit9,uint16_t u8unit10,uint16_t u8unit11,uint16_t u8unit12,
                     uint16_t u8unit13,uint16_t u8unit14,uint16_t u8unit15,uint16_t u8unit16)
{
    uint8_t u8UinitCount;
    
    TPS_u8WidthData[0] = u8unit1; 
    TPS_u8WidthData[1] = u8unit2;
    TPS_u8WidthData[2] = u8unit3;
    TPS_u8WidthData[3] = u8unit4;
    TPS_u8WidthData[4] = u8unit5;
    TPS_u8WidthData[5] = u8unit6;
    TPS_u8WidthData[6] = u8unit7;
    TPS_u8WidthData[7] = u8unit8;
    TPS_u8WidthData[8] = u8unit9;
    TPS_u8WidthData[9] = u8unit10;
    TPS_u8WidthData[10] = u8unit11;
    TPS_u8WidthData[11] = u8unit12;
    TPS_u8WidthData[12] = u8unit13;
    TPS_u8WidthData[13] = u8unit14;
    TPS_u8WidthData[14] = u8unit15;
    TPS_u8WidthData[15] = u8unit16;
    for(u8UinitCount=0;u8UinitCount<16;u8UinitCount++)
    {
      if(enumScenceMode<HIGH_BEAM)
      {
        TPS_u8WidthData[u8UinitCount + 16] = 0;
      }
      else
      {
        TPS_u8WidthData[u8UinitCount + 16] = TPS_u8WidthData[u8UinitCount];
      }
    }
}


/*******************
High beam mode
u8LRselection 0: Left, 1 Right
*******************/
void User_vidHighBeam(uint8_t u8LRselection)
{
  if(u8LRselection==LEFT)
  {
    User_vidSetMode(HIGH_BEAM,512,562,612,662,712,762,812,862,1023,1023,1023,862,812,762,712,662); //Left
  }
  else if(u8LRselection==RIGHT)
  {
    User_vidSetMode(HIGH_BEAM,334,388,451,564,706,1023,1023,1023,706,608,524,451,388,334,287,246); //Right
  }
}

/*******************
All Led off mode
*******************/
void User_vidLedOff()
{

   User_vidSetMode(HIGH_BEAM,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
}

/*******************
Country mode
u8LRselection 0: Left, 1 Right
*******************/
void User_vidCountry(uint8_t u8LRselection, uint8_t u8AngleSelection)
{
  if(u8AngleSelection==0)   //LB
  {
    User_vidSetMode(COUNTRY,0,0,360,360,247,229,196,168,144,123,105,89,75,64,54,45);
  }
  else if(u8AngleSelection==1) // DBL
  {
    //User_vidSetMode(COUNTRY,0,0,0,0,0,0,0,0,0,0,145,154,264,375,589,805);
    User_vidSetMode(COUNTRY,0,0,0,0,0,0,0,0,0,0,368,396,429,447,560,560);
  }
}


/*******************
ADB mode
u8LRselection 0: Left, 1 Right
*******************/
void User_vidAdb(uint8_t u8LRselection, uint8_t u8AdbLineSelection)
{
  if(u8AdbLineSelection == 0)
  {
    User_vidSetMode(ADB,246,287,334,388,451,524,608,706,1023,1023,1023,706,564,451,388,334);
  }
  else if(u8AdbLineSelection == 1)                               
  {
    User_vidSetMode(ADB,0,0,334,388,451,524,608,706,1023,1023,1023,706,564,451,388,334);
  }
  else if(u8AdbLineSelection == 2)
  {
    User_vidSetMode(ADB,0,0,0,388,451,524,608,706,1023,1023,1023,706,564,451,388,334);
  }
  else if(u8AdbLineSelection == 3)
  {
    User_vidSetMode(ADB,246,0,0,0,451,524,608,706,1023,1023,1023,706,564,451,388,334);
  }
  else if(u8AdbLineSelection == 4)
  {
    User_vidSetMode(ADB,246,287,0,0,0,524,608,706,1023,1023,1023,706,564,451,388,334);
  }
  else if(u8AdbLineSelection == 5)
  {
    User_vidSetMode(ADB,246,287,334,0,0,0,608,706,1023,1023,1023,706,564,451,388,334);
  }
  else if(u8AdbLineSelection == 6)
  {
    User_vidSetMode(ADB,246,287,334,388,0,0,0,706,1023,1023,1023,706,564,451,388,334);
  }
  else if(u8AdbLineSelection == 7)
  {
    User_vidSetMode(ADB,246,287,334,388,451,0,0,0,1023,1023,1023,706,564,451,388,334);
  }
  else if(u8AdbLineSelection == 8)
  {
    User_vidSetMode(ADB,246,287,334,388,451,524,0,0,0,1023,1023,706,564,451,388,334);
  }
  else if(u8AdbLineSelection == 9)
  {
    User_vidSetMode(ADB,246,287,334,388,451,524,608,0,0,0,1023,706,564,451,388,334);
  }
  else if(u8AdbLineSelection == 10)
  {
    User_vidSetMode(ADB,246,287,334,388,451,524,608,706,0,0,0,706,564,451,388,334);
  }
  else if(u8AdbLineSelection == 11)
  {
    User_vidSetMode(ADB,246,287,334,388,451,524,608,706,1023,0,0,0,564,451,388,334);
  }
  else if(u8AdbLineSelection == 12)
  {
    User_vidSetMode(ADB,246,287,334,388,451,524,608,706,1023,1023,0,0,0,451,388,334);
  }
  else if(u8AdbLineSelection == 13)
  {
    User_vidSetMode(ADB,246,287,334,388,451,524,608,706,1023,1023,1023,0,0,0,388,334);
  }
  else if(u8AdbLineSelection == 14)
  {
    User_vidSetMode(ADB,246,287,334,388,451,524,608,706,1023,1023,1023,706,0,0,0,334);
  }
  else if(u8AdbLineSelection == 15) //21
  {
    User_vidSetMode(ADB,246,287,334,388,451,524,608,706,1023,1023,1023,706,564,0,0,0);
  }
  else if(u8AdbLineSelection == 16) //20
  {
    User_vidSetMode(ADB,246,287,334,388,451,524,608,706,1023,1023,1023,706,564,451,0,0);
  }
  else if(u8AdbLineSelection == 17) //19
  {
    User_vidSetMode(ADB,246,287,334,388,451,524,608,706,1023,1023,1023,706,564,451,388,0);
  }
  else if(u8AdbLineSelection == 18)
  {
    User_vidSetMode(ADB,246,287,334,388,451,524,608,706,1023,1023,1023,706,564,451,388,334);
  }
}

/*******************
Country mode
u8LRselection 0: Left, 1 Right
*******************/
/*************************************************
void User_vidCountry(uint8_t u8LRselection, uint8_t u8AngleSelection)
{
  if(u8LRselection==LEFT)
  {
    if(u8AngleSelection == ANGEL_0)
    {
      User_vidSetMode(COUNTRY,0,0,0,0,0,0,0,0,0,0,196,212,229,247,212,182); //Left 0
    }
    else if(u8AngleSelection == ANGEL_1)
    {
      User_vidSetMode(COUNTRY,0,0,0,0,0,0,0,0,0,229,196,212,229,212,182,155); //Left -0.7
    }
    else if(u8AngleSelection == ANGEL_2)
    {
      User_vidSetMode(COUNTRY,0,0,0,0,0,0,0,0,266,229,196,212,212,182,155,133); //Left -2.3
    }
    else if(u8AngleSelection == ANGEL_3)
    {
      User_vidSetMode(COUNTRY,0,0,0,0,0,0,0,360,266,229,196,212,182,155,133,113); //Left -3.9
    }
    else if(u8AngleSelection == ANGEL_4)
    {
      User_vidSetMode(COUNTRY,0,0,0,0,0,0,360,360,266,229,196,182,155,133,113,96); //Left -5.4
    }
    else if(u8AngleSelection == ANGEL_5)
    {
      User_vidSetMode(COUNTRY,0,0,0,0,0,360,360,309,246,212,182,155,133,113,96,82); //Left -7.0
    }
    else if(u8AngleSelection == ANGEL_6)
    {
      User_vidSetMode(COUNTRY,0,0,0,0,0,0,0,0,0,0,25,212,229,310,247,212); //Left +2.4
    }
    else if(u8AngleSelection == ANGEL_7)
    {
      User_vidSetMode(COUNTRY,0,0,0,0,0,0,0,0,0,0,25,54,229,310,310,247); //Left +3.9
    }
    else if(u8AngleSelection == ANGEL_8)
    {
      User_vidSetMode(COUNTRY,0,0,0,0,0,0,0,0,0,0,25,54,75,310,334,310); //Left +5.5
    }
    else if(u8AngleSelection == ANGEL_9)
    {
      User_vidSetMode(COUNTRY,0,0,0,0,0,0,0,0,0,0,25,54,75,64,334,334); //Left +7.0
    }
    else if(u8AngleSelection == ANGEL_10)
    {
      User_vidSetMode(COUNTRY,0,0,0,0,0,0,0,0,0,0,25,54,75,64,54,334); //Left +8.5
    }
  }
  else if(u8LRselection==RIGHT)
  {
    if(u8AngleSelection == ANGEL_0)
    {
      User_vidSetMode(COUNTRY,0,0,0,0,0,0,0,196,212,229,229,196,168,144,123,105); //Right 0
    }
    else if(u8AngleSelection == ANGEL_1)
    {
      User_vidSetMode(COUNTRY,0,0,0,0,0,0,229,196,212,229,196,168,144,123,105,89); //Right -1.4
    }
    else if(u8AngleSelection == ANGEL_2)
    {
      User_vidSetMode(COUNTRY,0,0,0,0,0,266,229,196,212,196,168,144,123,105,89,75); //Right -2.9
    }
    else if(u8AngleSelection == ANGEL_3)
    {
      User_vidSetMode(COUNTRY,0,0,0,0,360,266,229,196,196,168,144,123,105,89,75,64); //Right -4.5
    }
    else if(u8AngleSelection == ANGEL_4)
    {
      User_vidSetMode(COUNTRY,0,0,0,360,360,247,229,196,168,144,123,105,89,75,64,54); //Right -6.0
    }
    else if(u8AngleSelection == ANGEL_5)
    {
      User_vidSetMode(COUNTRY,0,0,360,360,247,229,196,168,144,123,105,89,75,64,54,45); //Right -7.6
    }
    else if(u8AngleSelection == ANGEL_6)
    {
      User_vidSetMode(COUNTRY,0,0,0,0,0,0,0,25,212,229,247,229,196,168,144,123); //Right +1.7
    }
    else if(u8AngleSelection == ANGEL_7)
    {
      User_vidSetMode(COUNTRY,0,0,0,0,0,0,0,25,54,228,310,247,229,196,168,144); //Right +3.3
    }
    else if(u8AngleSelection == ANGEL_8)
    {
      User_vidSetMode(COUNTRY,0,0,0,0,0,0,0,25,54,75,310,334,247,229,196,168); //Right +4.9
    }
    else if(u8AngleSelection == ANGEL_9)
    {
      User_vidSetMode(COUNTRY,0,0,0,0,0,0,0,25,54,75,64,334,334,247,229,196); //Right +6.4
    }
    else if(u8AngleSelection == ANGEL_10)
    {
      User_vidSetMode(COUNTRY,0,0,0,0,0,0,0,25,54,75,64,54,334,360,247,229); //Right +7.9
    }
  }
}

************************************/
/*******************
ADB mode
u8LRselection 0: Left, 1 Right
*******************/
/************************************************************
void User_vidAdb(uint8_t u8LRselection, uint8_t u8AdbLineSelection)
{
  if(u8LRselection==LEFT)
  {
    if(u8AdbLineSelection == ADB_LINE_1_MIN)
    {
      User_vidSetMode(ADB,247,287,334,388,451,0,0,0,0,0,1023,706,564,451,388,334); //ADB line 1 min
    }
    else if(u8AdbLineSelection == ADB_LINE_1_MAX)                               
    {
      User_vidSetMode(ADB,246,0,0,0,0,0,0,0,0,0,1023,706,564,451,388,334); //ADB line 1 max
    }
    else if(u8AdbLineSelection == ADB_LINE_2_MIN)
    {
      User_vidSetMode(ADB,247,287,334,388,451,524,0,0,0,0,1023,706,564,451,388,334); //ADB line 2 min
    }
    else if(u8AdbLineSelection == ADB_LINE_2_MAX)
    {
      User_vidSetMode(ADB,247,287,334,388,451,0,0,0,0,0,1023,706,564,451,388,334); //ADB line 2 max
    }
    else if(u8AdbLineSelection == ADB_LINE_3_MIN)
    {
      User_vidSetMode(ADB,247,287,334,388,451,524,609,0,0,0,1023,706,564,451,388,334); //ADB line 3
    }
    else if(u8AdbLineSelection == ADB_LINE_4_MIN)
    {
      User_vidSetMode(ADB,247,287,334,388,451,524,609,0,0,0,0,0,564,451,388,334); //ADB line 4 min
    }
    else if(u8AdbLineSelection == ADB_LINE_4_MAX)
    {
      User_vidSetMode(ADB,247,287,334,388,451,524,609,0,0,0,0,0,564,451,388,334); //ADB line 4 max
    }
    else if(u8AdbLineSelection == ADB_LINE_5_MIN)
    {
      User_vidSetMode(ADB,247,287,334,388,451,524,609,0,0,0,0,706,564,451,388,334); //ADB line 5
    }
    else if(u8AdbLineSelection == ADB_LINE_6_MIN)
    {
      User_vidSetMode(ADB,247,287,334,388,451,524,609,706,0,0,0,706,564,451,388,334); //ADB line 6
    }
  }
  else if(u8LRselection==RIGHT)
  {
    if(u8AdbLineSelection == ADB_LINE_1_MIN)
    {
      User_vidSetMode(ADB,334,0,0,0,0,0,1023,1023,706,609,524,451,388,334,287,247); //ADB line 1 min
    }
    else if(u8AdbLineSelection == ADB_LINE_1_MAX)                               
    {
      User_vidSetMode(ADB,0,0,0,0,0,0,1023,1023,706,609,524,451,388,334,287,247); //ADB line 1 max
    }
    else if(u8AdbLineSelection == ADB_LINE_2_MIN)
    {
      User_vidSetMode(ADB,334,388,451,0,0,0,0,1023,706,609,524,451,388,334,287,247); //ADB line 2 min
    }
    else if(u8AdbLineSelection == ADB_LINE_2_MAX)
    {
      User_vidSetMode(ADB,334,0,0,0,0,0,0,1023,706,609,524,451,388,334,287,247); //ADB line 2 max
    }
    else if(u8AdbLineSelection == ADB_LINE_3_MIN)
    {
      User_vidSetMode(ADB,334,388,451,564,0,0,0,1023,706,609,524,451,388,334,287,247); //ADB line 3
    }
    else if(u8AdbLineSelection == ADB_LINE_4_MIN)
    {
      User_vidSetMode(ADB,334,388,451,564,0,0,0,0,0,609,524,451,388,334,287,247); //ADB line 4 min
    }
    else if(u8AdbLineSelection == ADB_LINE_4_MAX)
    {
      User_vidSetMode(ADB,334,388,451,0,0,0,0,0,0,609,524,451,388,334,287,247);  //ADB line 4 max
    }
    else if(u8AdbLineSelection == ADB_LINE_5_MIN)
    {
      User_vidSetMode(ADB,334,388,451,564,0,0,0,0,706,609,524,451,388,334,287,247); //ADB line 5
    }
    else if(u8AdbLineSelection == ADB_LINE_6_MIN)
    {
      User_vidSetMode(ADB,334,388,451,564,706,0,0,0,706,609,524,451,388,334,287,247); //ADB line 6
    }
  }
}
*************************************************************/