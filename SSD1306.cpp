/*
 * SSD1306ハードウェアベース制御クラス
*/

#include <Wire.h>
#include <Arduino.h>
#include "SSD1306.h"
#include <avr/pgmspace.h>

//--コンストラクタ ピンを指定してI2C通信を準備
SSD1306::SSD1306(int SDApin, int SCLpin, int addr){
    SDA = SDApin;
    SCL = SCLpin;
    ADDR = addr;
    Wire.begin(SDA, SCL);
}
SSD1306::SSD1306(){
}

//--ソフトウェアリセット
void SSD1306::softReset(){
    uint8_t command[] = {
        0b10000000,0xAE,0b00000000,0xA8,0b00111111,0b00000000,0xD3,0x00,0b10000000,0x40,0b10000000,0xA1,0b10000000,0xC8,0b00000000,0xDA,0b00010010,0b00000000,0x81,255,0b10000000,0xA4,0b10000000,0xA6,0b00000000,0xD5,0b10000000,0b00000000,0x20,0x10,0b00000000,0x22,0,7,0b00000000,0x21,0,127,0b00000000,0x8D,0x14,0b10000000,0xAF,0b10000000,0x2E
    };
    i2cWrite(command, 45);
}

//--I2Cコマンド分割+実行
void SSD1306::i2cWrite(uint8_t command[], int comm_length){
    Wire.beginTransmission(ADDR);
    for(int i = 0; i < comm_length; i++){
        //--30byteごと止めて実行を繰り返す
        if(i % 30 == 0){
            Wire.endTransmission();
            Wire.beginTransmission(ADDR);
        }
        Wire.write(command[i]);
    }
    Wire.endTransmission();
}

//--コントラスト調整
void SSD1306::setContrast(float val){
    if(val > 1.0) val = 1.0;
    Wire.beginTransmission(ADDR);
    Wire.write(0x00);
    Wire.write(0x81);
    Wire.write(int(val * 255.0));
    Wire.endTransmission();
}

//--画面クリア
void SSD1306::cls(){
    uint8_t i, j, k;
    for (i = 0; i < 8; i++) {
        Wire.beginTransmission(ADDR);
        Wire.write(0b10000000);
        Wire.write(0xB0 | i);
        Wire.write(0b00000000);
        Wire.write(0x21);
        Wire.write(0);
        Wire.write(127);
        Wire.endTransmission();

        for (j = 0; j < 16; j++) {
            Wire.beginTransmission(ADDR);
            Wire.write(0b01000000);
            for (k = 0; k < 8; k++) {
                Wire.write(0);
            }
            Wire.endTransmission();
        }
    }
}


//--bitmap送信 (x,y,w,hはそれぞれ8x8ブロック単位)
void SSD1306::drawBMP(int _x, int _y, int _w, int _h, uint8_t *data, int inv){
    int cnt = 0; //アドレスカウンタ
    for(int y = _y; y < (_y + _h); y++){
        //--データ開始位置設定
        Wire.beginTransmission(ADDR);
        //y
        Wire.write(0b10000000);
        Wire.write(0xB0 | y);
        //x
        Wire.write(0b00000000);
        Wire.write(0x21);
        Wire.write(_x * 8);
        uint8_t w = (_x + _w) * 8;
        if(w == 128) w = 127;
        Wire.write(w);
        Wire.endTransmission();

        //--データ送信
        Wire.beginTransmission(ADDR);
        Wire.write(0b01000000);
        for(int x = _x; x < (_x + _w * 8); x++){
            uint8_t b = pgm_read_byte_near(&data[cnt]);
            if (inv == 1)Wire.write(~b);
            else Wire.write(b);
            b = 0;
            cnt++;
        }
        Wire.endTransmission();
    }
}