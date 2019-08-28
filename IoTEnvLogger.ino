/*
 * 温湿度計
*/

#include "Display.h"
#include "SHT31.h"

//--
SSD1306 oled = SSD1306(4, 14, 0x3C);
Display disp = Display(oled);

//--
SHT31 sht31 = SHT31(0x45);
float temp = 0.0, humid = 0.0;

void setup(){
    disp.setMenuStatus(0b0111);
    sht31.SoftReset();
}

void loop(){
    //--温湿度取得
    sht31.GetTempHum();
    temp = sht31.Temperature();
    humid = sht31.Humidity();

    //--画面に反映
    disp.setTemp(temp);
    disp.setHumid(humid);

    delay(2000);
}