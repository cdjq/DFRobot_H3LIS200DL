/**！
 * @file getAcceleration.ino
 * @brief Get the acceleration in x, y, z directions
 * @copyright  Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @licence     The MIT License (MIT)
 * @author [fengli](li.feng@dfrobot.com)
 * @version  V1.0
 * @date  2021-01-16
 * @get from https://www.dfrobot.com
 * @https://github.com/DFRobot/DFRobot_H3LIS200DL
 */


#include <DFRobot_H3LIS200DL.h>

//当你使用I2C通信时,使用下面这段程序,使用DFRobot_H3LIS200DL_I2C构造对象
/*!
 * @brief Constructor 
 * @param pWire I2c controller
 * @param addr  I2C address(0x18/0x19)
 */
DFRobot_H3LIS200DL_I2C acce/*(&Wire,0x19)*/;


//当你使用SPI通信时,使用下面这段程序,使用DFRobot_H3LIS200DL_SPI构造对象
#if defined(ESP32) || defined(ESP8266)
#define H3LIS200DL_CS  D3

/* AVR series mainboard */
#else
#define H3LIS200DL_CS 3
#endif
/*!
 * @brief Constructor 
 * @param cs : Chip selection pinChip selection pin
 * @param spi :SPI controller
 */
//DFRobot_H3LIS200DL_SPI acce(/*cs = */H3LIS200DL_CS);

void setup(void){

  Serial.begin(9600);
  //Chip initialization
  while(acce.begin()){
     delay(1000);
     Serial.println("init failure");
  }
  //Get chip id
  Serial.print("chip id : ");
  Serial.println(acce.getID(),HEX);
  
  /**
    set range:Range(g)
          e100_g ,/<±100g>/
          e200_g ,/<±200g>/
  */
  acce.setRange(/*Range = */DFRobot_H3LIS200DL::e100_g);

  /**
    Set data measurement rate：
      ePowerDown_0HZ = 0,
      eLowPower_halfHZ,
      eLowPower_1HZ,
      eLowPower_2HZ,
      eLowPower_5HZ,
      eLowPower_10HZ,
      eNormal_50HZ,
      eNormal_100HZ,
      eNormal_400HZ,
      eNormal_1000HZ,
  */
  acce.setAcquireRate(/*Rate = */DFRobot_H3LIS200DL::eNormal_50HZ);
  delay(1000);
}

void loop(void){



    //Get the acceleration in the three directions of xyz
    Serial.print("Acceleration x: "); //print acceleration
    Serial.print(acce.readAccX());
    Serial.print(" g \ty: ");
    Serial.print(acce.readAccY());
    Serial.print(" g \tz: ");
    Serial.print(acce.readAccZ());
    Serial.println(" g");
    delay(300);
    /*
    //Get the acceleration in the three directions of xyz
    DFRobot_H3LIS200DL::sAccel_t accel = acce.getAcceFromXYZ();
    Serial.print("Acceleration x: "); //print acceleration
    Serial.print(accel.acc_x);
    Serial.print(" g \ty: ");
    Serial.print(accel.acc_y);
    Serial.print(" g \tz: ");
    Serial.print(accel.acc_z);
    Serial.println(" g");
    delay(300);
    */
}