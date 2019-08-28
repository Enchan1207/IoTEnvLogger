/*
 * SHT31温湿度モジュールクラス (AE-SHT31改変版)
*/

#include "SHT31.h"

SHT31::SHT31(uint8_t i2caddr) {
  _i2caddr = i2caddr;
  Wire.begin(4, 14); 
}

void SHT31::i2c_write(uint16_t data)
{
  Wire.beginTransmission(_i2caddr);
  Wire.write(data>>8); 
  Wire.write(data&0xFF);
  Wire.endTransmission();
}
void SHT31::i2c_read(uint8_t data[],uint8_t num)
{
  Wire.requestFrom(_i2caddr,(uint8_t)num);
  while (Wire.available() != num); 
  for (int i=0; i<num; i++) {
    data[i] = Wire.read();
  }
}

void SHT31::SoftReset(void)
{
  i2c_write(0x30A2);
  delay(500);
  i2c_write(0x3041);
  delay(500);

}

void SHT31::GetTempHum(void)
{
  uint8_t data[7];
    
  i2c_write(0x2400);
  delay(300);
  i2c_read(data,6);
  temperature = -45.0 + (175.0 * ((data[0] * 256.0) + data[1]) / 65535.0);
  humidity = (100.0 * ((data[3] * 256.0) + data[4])) / 65535.0;
}

float SHT31::Temperature(void)
{
 return temperature;
}

float SHT31::Humidity(void)
{
 return humidity;
}
