# IoTEnvLogger

## OverView
Environment data logger device (using ESP8266 module).

## Development Environment
 * Launguage: C++
 * Compile: Arduino 1.8.9
 * Execution: ESP-WROOM-02([K-09758](http://akizukidenshi.com/catalog/g/gK-09758/))

## Contents
 * IoTEnvLogger.ino: main source
 * Display control class
	* SSD1306.cpp/SSD1306.h: hardware control class
	* Display.cpp/Display.h: software control class(inherit SSD1306.h)
 * Temp/Humid sensor class
	* SHT31.cpp/SHT31.h: [sensor](http://akizukidenshi.com/catalog/g/gK-12125/) control class

__NOTE__  
 * The initialize part of SSD1306.cpp/SSD1306.h use [mgo-tec/OLED_SSD1306](https://github.com/mgo-tec/OLED_SSD1306) as reference.  
 * SHT31.cpp/SHT31.h are remodeling versions of [sample library from akizukidenshi](http://akizukidenshi.com/download/AE_SHT31.zip).
 
## Usage

## Open Source Licenses
* [mgo-tec/OLED_SSD1306](https://github.com/mgo-tec/OLED_SSD1306)
  > Arduino or ESP-WROOM-02(ESP8266) Library  
  >
  > Copyright (c) 2016 Mgo-tec  
  > https://github.com/mgo-tec/OLED_SSD1306/blob/master/LICENSE

## LICENCE
All files except those described in the Open Source License section are distributed under the MIT license.