/*
 * SHT31温湿度モジュールクラス (AE-SHT31改変版)
*/

#include <Arduino.h>
#include <Wire.h>

class SHT31{
  public:
    SHT31(uint8_t i2caddr);
    void SoftReset(void);
    void GetTempHum(void);
    float Temperature(void);
    float Humidity(void);
  private:
  	uint8_t _i2caddr;
    void i2c_write(uint16_t data);
    void i2c_read(uint8_t data[],uint8_t num);
    float humidity, temperature;
};
