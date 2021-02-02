# DFRobot_H3LIS200DL
The H3LIS200DL is a low-power high performance 3-axis linear accelerometer <br>
belonging to the “nano” family, with digital I2C/SPI <br>
serial interface standard output. <br>
The device features ultra-low-power operational <br>
modes that allow advanced power saving and <br>
smart sleep-to-wakeup functions.<br>
The H3LIS200DL has dynamically user selectable full scales of ±100g/±200g and is <br>
capable of measuring accelerations with output <br>
data rates from 0.5 Hz to 1 kHz.<br>
The H3LIS200DL is available in a small thin <br>
plastic land grid array package (LGA) and is <br>
guaranteed to operate over an extended <br>
temperature range from -40 °C to +85 °C.<br>


## DFRobot_H3LIS200DL Library for Arduino
---------------------------------------------------------

Provide an Arduino library to get Three-axis acceleration by reading data from H3LIS200DL.

## Table of Contents

* [Summary](#summary)
* [Installation](#installation)
* [Methods](#methods)
* [Compatibility](#compatibility)
* [History](#history)
* [Credits](#credits)

## Summary

Provide an Arduino library to get Three-axis acceleration by reading data from H3LIS200DL.

## Installation

To use this library, first download the library file, paste it into the \Arduino\libraries directory, then open the examples folder and run the demo in the folder.

## Methods

```C++
  DFRobot_H3LIS200DL();
  
  /**
   * @brief Initialize the function
   * @return Return 0 indicates a successful initialization, while other values indicates failure and return to error code.
   */
  int begin(void);
 
  /**
   * @brief Get chip id
   * @return Returns the 8 bit serial number
   */
  uint8_t getID();
  
  /**
   * @brief Enable interrupt
   * @ source Interrupt pin selection
              eINT1 = 0,/<int1 >/
              eINT2,/<int2>/
   * @param event Interrupt event selection
                   eXLowThanTh = 0,/<The acceleration in the x direction is less than the threshold>/
                   eXhigherThanTh ,/<The acceleration in the x direction is greater than the threshold>/
                   eYLowThanTh,/<The acceleration in the y direction is less than the threshold>/
                   eYhigherThanTh,/<The acceleration in the y direction is greater than the threshold>/
                   eZLowThanTh,/<The acceleration in the z direction is less than the threshold>/
                   eZhigherThanTh,/<The acceleration in the z direction is greater than the threshold>/
   */
  void enableInterruptEvent(eInterruptSource_t source, eInterruptEvent_t event);
  
  /**
   * @brief Set the measurement range
   * @param range Range(g)
            e100_g =  ±100g
            e200_g = ±200g
   */
  void setRange(eRange_t range);
  
  /**
   * @brief Set data measurement rate
   * @param range rate(HZ)
                  ePowerDown_0HZ = 0,测量关闭
                  eLowPower_halfHZ,0.5 hz
                  eLowPower_1HZ,
                  eLowPower_2HZ,
                  eLowPower_5HZ,
                  eLowPower_10HZ,
                  eNormal_50HZ,
                  eNormal_100HZ,
                  eNormal_400HZ,
                  eNormal_1000HZ,
   */
  void setAcquireRate(ePowerMode_t rate);
  
  /**
   * @brief Set data filtering mode
   * @param mode Four modes
                 eCutoffMode1 = 0,
                 eCutoffMode2,
                 eCutoffMode3,
                 eCutoffMode4,
                 eShutDown,  无过滤
   *|---------------------------High-pass filter cut-off frequency configuration-----------------------------|
   *|--------------------------------------------------------------------------------------------------------|
   *|                |    ft [Hz]      |        ft [Hz]       |       ft [Hz]        |        ft [Hz]        |
   *|   mode         |Data rate = 50 Hz|   Data rate = 100 Hz |  Data rate = 400 Hz  |   Data rate = 1000 Hz |
   *|--------------------------------------------------------------------------------------------------------|
   *|  eCutoffMode1  |     1           |         2            |            8         |             20        |
   *|--------------------------------------------------------------------------------------------------------|
   *|  eCutoffMode2  |    0.5          |         1            |            4         |             10        |
   *|--------------------------------------------------------------------------------------------------------|
   *|  eCutoffMode3  |    0.25         |         0.5          |            2         |             5         |
   *|--------------------------------------------------------------------------------------------------------|
   *|  eCutoffMode4  |    0.125        |         0.25         |            1         |             2.5       |
   *|--------------------------------------------------------------------------------------------------------|
   */
  void setHFilterMode(eHighPassFilter_t mode);

  /**
   * @brief Set the threshold of interrupt source 1 interrupt
   * @param threshold 范围是量程的范围(unit:g)
   */
  void setInt1Th(uint8_t threshold);

  /**
   * @brief Set interrupt source 2 interrupt generation threshold
   * @param threshold 范围是量程的范围(unit:g）
   */
  void setInt2Th(uint8_t threshold);

  /**
   * @brief Enable sleep wake function
   * @param enable true(enable)\false(disable)
   * @return 1:表示使能失败/0：表示使能成功
   */
  int enableSleep(bool enable);
  
  /**
   * @brief Get the acceleration in the three directions of xyz
   * @return Three-axis acceleration 
             acc_x;
             acc_y;
             acc_z;
   */
  sAccel_t getAcceFromXYZ();

  /**
   * @brief Check whether the interrupt event'source' is generated in interrupt 1
   * @param source Interrupt event
                   eXLowThanTh = 0,/<The acceleration in the x direction is less than the threshold>/
                   eXhigherThanTh ,/<The acceleration in the x direction is greater than the threshold>/
                   eYLowThanTh,/<The acceleration in the y direction is less than the threshold>/
                   eYhigherThanTh,/<The acceleration in the y direction is greater than the threshold>/
                   eZLowThanTh,/<The acceleration in the z direction is less than the threshold>/
                   eZhigherThanTh,/<The acceleration in the z direction is greater than the threshold>/
   * @return true ：produce
             false：Interrupt event
   */
  bool getInt1Event(eInterruptEvent_t source);

  /**
   * @brief Check whether the interrupt event'source' is generated in interrupt 2
   * @param source Interrupt event
                   eXLowThanTh = 0,/<The acceleration in the x direction is less than the threshold>/
                   eXhigherThanTh ,/<The acceleration in the x direction is greater than the threshold>/
                   eYLowThanTh,/<The acceleration in the y direction is less than the threshold>/
                   eYhigherThanTh,/<The acceleration in the y direction is greater than the threshold>/
                   eZLowThanTh,/<The acceleration in the z direction is less than the threshold>/
                   eZhigherThanTh,/<The acceleration in the z direction is greater than the threshold>/
   * @return true ：produce
             false：Interrupt event
   */
  bool getInt2Event(eInterruptEvent_t source);
  
  /**
   * @brief Get the acceleration in the x direction
   * @return acceleration (unit:g)

   */
  float readAccX();
  
  /**
   * @brief Get the acceleration in the y direction
   * @return acceleration (unit:g)

   */
  float readAccY();
  
  /**
   * @brief Get the acceleration in the z direction
   * @return acceleration (unit:g)

   */
  float readAccZ();

```

## Compatibility

MCU                | Work Well    | Work Wrong   | Untested    | Remarks
------------------ | :----------: | :----------: | :---------: | -----
Arduino uno        |      √       |              |             | 
FireBeetle-ESP8266        |      √       |              |             | 
FireBeetle-ESP32        |      √       |              |             | 
Arduino MEGA2560        |      √       |              |             | 
Arduino Leonardo|      √       |              |             | 
microbit        |      √       |              |             | 
FireBeetle-M0        |      √       |              |             | 


## History

- data 2021-2-1
- version V1.0


## Credits

Written by(li.feng@dfrobot.com), 2020. (Welcome to our [website](https://www.dfrobot.com/))
