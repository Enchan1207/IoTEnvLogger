/*
 * SSD1306ハイレベル制御クラス
*/

#include "Display.h"
#include <Arduino.h>
#include <avr/pgmspace.h>
#include "Data.h"
#include <stdio.h>

//--コンストラクタ
Display::Display(SSD1306 _oled){
    oled = _oled;
    status = 0;
    oled.softReset();
    oled.cls();
}

//--メニューバー描画
void Display::setMenuStatus(uint8_t stat){
    status = stat;
    oled.drawBMP(0, 0, 2, 2, menuBar[1 * (status & 0b001)], 1); //WiFiアイコン
    oled.drawBMP(2, 0, 2, 2, menuBar[2 * ((status & 0b010) != 0)], 1); //サーバ通信アイコン
    oled.drawBMP(4, 0, 2, 2, menuBar[3 * ((status & 0b100) != 0)], 1); //ペアリングアイコン
}
uint8_t Display::getMenuStatus(){
    return status;
}


//--温湿度設定
void Display::setTemp(float temp){
    setValue(int(temp * 10), 0);
}
void Display::setHumid(float humid){
    setValue(int(humid * 10), 9);
}

//--純粋に6桁の数値を表示(ワンタイムパス用)
void Display::putDigit(int digit){
    //--一回きれいにしよっか
    cls();
    //--digitを3桁ずつ分割
    char dgchar[6] = "";
    sprintf(dgchar, "%06d", digit);
    oled.drawBMP(0 + 0, 2, 2, 6, number_Large[String(dgchar[0]).toInt()], 1);
    oled.drawBMP(2 + 0, 2, 2, 6, number_Large[String(dgchar[1]).toInt()], 1);
    oled.drawBMP(5 + 0, 2, 2, 6, number_Large[String(dgchar[2]).toInt()], 1);
    oled.drawBMP(0 + 8, 2, 2, 6, number_Large[String(dgchar[3]).toInt()], 1);
    oled.drawBMP(2 + 8, 2, 2, 6, number_Large[String(dgchar[4]).toInt()], 1);
    oled.drawBMP(5 + 8, 2, 2, 6, number_Large[String(dgchar[5]).toInt()], 1);
}

//--cls
void Display::cls(){
    oled.cls();
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