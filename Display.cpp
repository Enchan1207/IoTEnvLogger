/*
 * SSD1306ハイレベル制御クラス
*/

#include "Display.h"
#include <Arduino.h>
#include <avr/pgmspace.h>
#include "Data.h"

//--コンストラクタ
Display::Display(SSD1306 _oled){
    oled = _oled;
    oled.softReset();
    oled.cls();
}

//--メニューバー描画
void Display::setMenuStatus(uint8_t stat){
    if(stat & 0b001) oled.drawBMP(0, 0, 2, 2, menuBar[1], 1); //WiFiアイコン
    else oled.drawBMP(0, 0, 2, 2, menuBar[0], 1);
    if(stat & 0b010) oled.drawBMP(2, 0, 2, 2, menuBar[2], 1); //サーバ通信アイコン
    else oled.drawBMP(2, 0, 2, 2, menuBar[0], 1);
    if(stat & 0b100) oled.drawBMP(4, 0, 2, 2, menuBar[3], 1); //ペアリングアイコン
    else oled.drawBMP(4, 0, 2, 2, menuBar[0], 1);
}

//--温湿度設定
void Display::setTemp(float temp){
    setValue(int(temp * 10), 0);
}
void Display::setHumid(float humid){
    setValue(int(humid * 10), 9);
}

//値を書き換える
void Display::setValue(int value, int x_offset){
    //各位の数値を取得
    int dg3 = value / 100;
    int dg2 = (value / 10) % 10;
    int dg1 = value % 10;

    //x_offsetの値に従ってずらして描く
    oled.drawBMP(0 + x_offset, 2, 2, 6, number_Large[dg3], 1);
    oled.drawBMP(2 + x_offset, 2, 2, 6, number_Large[dg2], 1);
    oled.drawBMP(5 + x_offset, 4, 2, 4, number_Small[dg1], 1);

    //小数点と記号も忘れずに
    oled.drawBMP(5 + x_offset, 2, 2, 2, letter[x_offset == 0], 1);
    oled.drawBMP(4 + x_offset, 7, 1, 1, point[0], 1);
}