/*
 * bitmap表示用データ
*/

#include <avr/pgmspace.h>

//メニューバー
PROGMEM uint8_t menuBar[][16 * (16 / 8)] = {
    //--(非表示時の空白データ)
    {
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xBF, 0xBF, 0xBF, 0xBF, 0xBF, 0xBF, 0xBF,
        0xBF, 0xBF, 0xBF, 0xBF, 0xBF, 0xBF, 0xBF, 0xFF
    },
    //--WiFiアイコン
    {
        0xFF, 0x9F, 0xCF, 0x67, 0x37, 0xB3, 0x9B, 0xDB,
        0xDB, 0x9B, 0xB3, 0x37, 0x67, 0xCF, 0x9F, 0xFF,
        0xFF, 0xBF, 0xBF, 0xBE, 0xBF, 0xBD, 0xB8, 0xB0,
        0xB0, 0xB8, 0xBD, 0xBF, 0xBE, 0xBF, 0xBF, 0xFF
    },
    //--サーバ通信アイコン
    {
        0xFF, 0x7F, 0x7F, 0x7F, 0x7F, 0x01, 0x01, 0xFF,
        0xFF, 0x01, 0x01, 0xC3, 0xC7, 0xCF, 0xDF, 0xFF,
        0xFF, 0xBF, 0xBE, 0xBC, 0xB8, 0xB0, 0xB0, 0xBF,
        0xBF, 0xB0, 0xB0, 0xBF, 0xBF, 0xBF, 0xBF, 0xFF
    },
    //--ペアリングアイコン
    {
        0xFF, 0x03, 0x01, 0xF9, 0xF9, 0x19, 0x09, 0xC9,
        0xC9, 0x01, 0x03, 0xCF, 0xCF, 0x0F, 0x1F, 0xFF,
        0xFF, 0xBE, 0xBC, 0xBC, 0xBC, 0xB0, 0xA0, 0xA4,
        0xA4, 0xA4, 0xA6, 0xA7, 0xA7, 0xA0, 0xB0, 0xFF
    }
};
//デジタル数字(大)
PROGMEM uint8_t number_Large[][16 * (48 / 8)]{
    //0
    {
        0xFF, 0x1F, 0x0F, 0x0F, 0x13, 0xE1, 0xE1, 0xE1,
        0xE1, 0xE1, 0xE1, 0x13, 0x0F, 0x0F, 0x1F, 0xFF,
        0xFF, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0xFF,
        0xFF, 0xC0, 0x80, 0x80, 0xC0, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xC0, 0x80, 0x80, 0xC0, 0xFF,
        0xFF, 0x03, 0x01, 0x01, 0x03, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0x03, 0x01, 0x01, 0x03, 0xFF,
        0xFF, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0xFF,
        0xFF, 0xF8, 0xF0, 0xF0, 0xC8, 0x87, 0x87, 0x87,
        0x87, 0x87, 0x87, 0xC8, 0xF0, 0xF0, 0xF8, 0xFF
    },
    //1
    {
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0x1F, 0x0F, 0x0F, 0x1F, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xC0, 0x80, 0x80, 0xC0, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0x03, 0x01, 0x01, 0x03, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xF8, 0xF0, 0xF0, 0xF8, 0xFF
    },
    //2
    {
        0xFF, 0xFF, 0xFF, 0xFF, 0xF3, 0xE1, 0xE1, 0xE1,
        0xE1, 0xE1, 0xE1, 0x13, 0x0F, 0x0F, 0x1F, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x3F, 0x3F, 0x3F,
        0x3F, 0x3F, 0x3F, 0x40, 0x80, 0x80, 0xC0, 0xFF,
        0xFF, 0x03, 0x01, 0x01, 0x02, 0xFC, 0xFC, 0xFC,
        0xFC, 0xFC, 0xFC, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xF8, 0xF0, 0xF0, 0xC8, 0x87, 0x87, 0x87,
        0x87, 0x87, 0x87, 0xCF, 0xFF, 0xFF, 0xFF, 0xFF
    },
    //3
    {
        0xFF, 0xFF, 0xFF, 0xFF, 0xF3, 0xE1, 0xE1, 0xE1,
        0xE1, 0xE1, 0xE1, 0x13, 0x0F, 0x0F, 0x1F, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x3F, 0x3F, 0x3F,
        0x3F, 0x3F, 0x3F, 0x40, 0x80, 0x80, 0xC0, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFC, 0xFC, 0xFC,
        0xFC, 0xFC, 0xFC, 0x02, 0x01, 0x01, 0x03, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xCF, 0x87, 0x87, 0x87,
        0x87, 0x87, 0x87, 0xC8, 0xF0, 0xF0, 0xF8, 0xFF
    },
    //4
    {
        0xFF, 0x1F, 0x0F, 0x0F, 0x1F, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0x1F, 0x0F, 0x0F, 0x1F, 0xFF,
        0xFF, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0xFF,
        0xFF, 0xC0, 0x80, 0x80, 0x40, 0x3F, 0x3F, 0x3F,
        0x3F, 0x3F, 0x3F, 0x40, 0x80, 0x80, 0xC0, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFC, 0xFC, 0xFC,
        0xFC, 0xFC, 0xFC, 0x02, 0x01, 0x01, 0x03, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xF8, 0xF0, 0xF0, 0xF8, 0xFF
    },
    //5
    {
        0xFF, 0x1F, 0x0F, 0x0F, 0x13, 0xE1, 0xE1, 0xE1,
        0xE1, 0xE1, 0xE1, 0xF3, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xC0, 0x80, 0x80, 0x40, 0x3F, 0x3F, 0x3F,
        0x3F, 0x3F, 0x3F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFC, 0xFC, 0xFC,
        0xFC, 0xFC, 0xFC, 0x02, 0x01, 0x01, 0x03, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xCF, 0x87, 0x87, 0x87,
        0x87, 0x87, 0x87, 0xC8, 0xF0, 0xF0, 0xF8, 0xFF
    },
    //6
    {
        0xFF, 0x1F, 0x0F, 0x0F, 0x13, 0xE1, 0xE1, 0xE1,
        0xE1, 0xE1, 0xE1, 0xF3, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xC0, 0x80, 0x80, 0x40, 0x3F, 0x3F, 0x3F,
        0x3F, 0x3F, 0x3F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0x03, 0x01, 0x01, 0x02, 0xFC, 0xFC, 0xFC,
        0xFC, 0xFC, 0xFC, 0x02, 0x01, 0x01, 0x03, 0xFF,
        0xFF, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0xFF,
        0xFF, 0xF8, 0xF0, 0xF0, 0xC8, 0x87, 0x87, 0x87,
        0x87, 0x87, 0x87, 0xC8, 0xF0, 0xF0, 0xF8, 0xFF
    },
    //7
    {
        0xFF, 0xFF, 0xFF, 0xFF, 0xF3, 0xE1, 0xE1, 0xE1,
        0xE1, 0xE1, 0xE1, 0x13, 0x0F, 0x0F, 0x1F, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xC0, 0x80, 0x80, 0xC0, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0x03, 0x01, 0x01, 0x03, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xF8, 0xF0, 0xF0, 0xF8, 0xFF
    },
    //8
    {
        0xFF, 0x1F, 0x0F, 0x0F, 0x13, 0xE1, 0xE1, 0xE1,
        0xE1, 0xE1, 0xE1, 0x13, 0x0F, 0x0F, 0x1F, 0xFF,
        0xFF, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0xFF,
        0xFF, 0xC0, 0x80, 0x80, 0x40, 0x3F, 0x3F, 0x3F,
        0x3F, 0x3F, 0x3F, 0x40, 0x80, 0x80, 0xC0, 0xFF,
        0xFF, 0x03, 0x01, 0x01, 0x02, 0xFC, 0xFC, 0xFC,
        0xFC, 0xFC, 0xFC, 0x02, 0x01, 0x01, 0x03, 0xFF,
        0xFF, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0xFF,
        0xFF, 0xF8, 0xF0, 0xF0, 0xC8, 0x87, 0x87, 0x87,
        0x87, 0x87, 0x87, 0xC8, 0xF0, 0xF0, 0xF8, 0xFF
    },
    //9
    {
        0xFF, 0x1F, 0x0F, 0x0F, 0x13, 0xE1, 0xE1, 0xE1,
        0xE1, 0xE1, 0xE1, 0x13, 0x0F, 0x0F, 0x1F, 0xFF,
        0xFF, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0xFF,
        0xFF, 0xC0, 0x80, 0x80, 0x40, 0x3F, 0x3F, 0x3F,
        0x3F, 0x3F, 0x3F, 0x40, 0x80, 0x80, 0xC0, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFC, 0xFC, 0xFC,
        0xFC, 0xFC, 0xFC, 0x02, 0x01, 0x01, 0x03, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xCF, 0x87, 0x87, 0x87,
        0x87, 0x87, 0x87, 0xC8, 0xF0, 0xF0, 0xF8, 0xFF
    }
};
//デジタル数字(小)
PROGMEM uint8_t number_Small[][16 * (32 / 8)]{
    //0
    {
        0xFF, 0x1F, 0x0F, 0x0F, 0x13, 0xE1, 0xE1, 0xE1,
        0xE1, 0xE1, 0xE1, 0x13, 0x0F, 0x0F, 0x1F, 0xFF,
        0xFF, 0xC0, 0x80, 0x80, 0xC0, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xC0, 0x80, 0x80, 0xC0, 0xFF,
        0xFF, 0x03, 0x01, 0x01, 0x03, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0x03, 0x01, 0x01, 0x03, 0xFF,
        0xFF, 0xF8, 0xF0, 0xF0, 0xC8, 0x87, 0x87, 0x87,
        0x87, 0x87, 0x87, 0xC8, 0xF0, 0xF0, 0xF8, 0xFF
    },
    //1
    {
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0x1F, 0x0F, 0x0F, 0x1F, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xC0, 0x80, 0x80, 0xC0, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0x03, 0x01, 0x01, 0x03, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xF8, 0xF0, 0xF0, 0xF8, 0xFF
    },
    //2
    {
        0xFF, 0xFF, 0xFF, 0xFF, 0xF3, 0xE1, 0xE1, 0xE1,
        0xE1, 0xE1, 0xE1, 0x13, 0x0F, 0x0F, 0x1F, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x3F, 0x3F, 0x3F,
        0x3F, 0x3F, 0x3F, 0x40, 0x80, 0x80, 0xC0, 0xFF,
        0xFF, 0x03, 0x01, 0x01, 0x02, 0xFC, 0xFC, 0xFC,
        0xFC, 0xFC, 0xFC, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xF8, 0xF0, 0xF0, 0xC8, 0x87, 0x87, 0x87,
        0x87, 0x87, 0x87, 0xCF, 0xFF, 0xFF, 0xFF, 0xFF,
    },
    //3
    {
        0xFF, 0xFF, 0xFF, 0xFF, 0xF3, 0xE1, 0xE1, 0xE1,
        0xE1, 0xE1, 0xE1, 0x13, 0x0F, 0x0F, 0x1F, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x3F, 0x3F, 0x3F,
        0x3F, 0x3F, 0x3F, 0x40, 0x80, 0x80, 0xC0, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFC, 0xFC, 0xFC,
        0xFC, 0xFC, 0xFC, 0x02, 0x01, 0x01, 0x03, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xCF, 0x87, 0x87, 0x87,
        0x87, 0x87, 0x87, 0xC8, 0xF0, 0xF0, 0xF8, 0xFF
    },
    //4
    {
        0xFF, 0x1F, 0x0F, 0x0F, 0x1F, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0x1F, 0x0F, 0x0F, 0x1F, 0xFF,
        0xFF, 0xC0, 0x80, 0x80, 0x40, 0x3F, 0x3F, 0x3F,
        0x3F, 0x3F, 0x3F, 0x40, 0x80, 0x80, 0xC0, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFC, 0xFC, 0xFC,
        0xFC, 0xFC, 0xFC, 0x02, 0x01, 0x01, 0x03, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xF8, 0xF0, 0xF0, 0xF8, 0xFF
    },
    //5
    {
        0xFF, 0x1F, 0x0F, 0x0F, 0x13, 0xE1, 0xE1, 0xE1,
        0xE1, 0xE1, 0xE1, 0xF3, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xC0, 0x80, 0x80, 0x40, 0x3F, 0x3F, 0x3F,
        0x3F, 0x3F, 0x3F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFC, 0xFC, 0xFC,
        0xFC, 0xFC, 0xFC, 0x02, 0x01, 0x01, 0x03, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xCF, 0x87, 0x87, 0x87,
        0x87, 0x87, 0x87, 0xC8, 0xF0, 0xF0, 0xF8, 0xFF
    },
    //6
    {
        0xFF, 0x1F, 0x0F, 0x0F, 0x13, 0xE1, 0xE1, 0xE1,
        0xE1, 0xE1, 0xE1, 0xF3, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xC0, 0x80, 0x80, 0x40, 0x3F, 0x3F, 0x3F,
        0x3F, 0x3F, 0x3F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0x03, 0x01, 0x01, 0x02, 0xFC, 0xFC, 0xFC,
        0xFC, 0xFC, 0xFC, 0x02, 0x01, 0x01, 0x03, 0xFF,
        0xFF, 0xF8, 0xF0, 0xF0, 0xC8, 0x87, 0x87, 0x87,
        0x87, 0x87, 0x87, 0xC8, 0xF0, 0xF0, 0xF8, 0xFF
    },
    //7
    {
        0xFF, 0xFF, 0xFF, 0xFF, 0xF3, 0xE1, 0xE1, 0xE1,
        0xE1, 0xE1, 0xE1, 0x13, 0x0F, 0x0F, 0x1F, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xC0, 0x80, 0x80, 0xC0, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0x03, 0x01, 0x01, 0x03, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xF8, 0xF0, 0xF0, 0xF8, 0xFF
    },
    //8
    {
        0xFF, 0x1F, 0x0F, 0x0F, 0x13, 0xE1, 0xE1, 0xE1,
        0xE1, 0xE1, 0xE1, 0x13, 0x0F, 0x0F, 0x1F, 0xFF,
        0xFF, 0xC0, 0x80, 0x80, 0x40, 0x3F, 0x3F, 0x3F,
        0x3F, 0x3F, 0x3F, 0x40, 0x80, 0x80, 0xC0, 0xFF,
        0xFF, 0x03, 0x01, 0x01, 0x02, 0xFC, 0xFC, 0xFC,
        0xFC, 0xFC, 0xFC, 0x02, 0x01, 0x01, 0x03, 0xFF,
        0xFF, 0xF8, 0xF0, 0xF0, 0xC8, 0x87, 0x87, 0x87,
        0x87, 0x87, 0x87, 0xC8, 0xF0, 0xF0, 0xF8, 0xFF
    },
    //9
    {
        0xFF, 0x1F, 0x0F, 0x0F, 0x13, 0xE1, 0xE1, 0xE1,
        0xE1, 0xE1, 0xE1, 0x13, 0x0F, 0x0F, 0x1F, 0xFF,
        0xFF, 0xC0, 0x80, 0x80, 0x40, 0x3F, 0x3F, 0x3F,
        0x3F, 0x3F, 0x3F, 0x40, 0x80, 0x80, 0xC0, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFC, 0xFC, 0xFC,
        0xFC, 0xFC, 0xFC, 0x02, 0x01, 0x01, 0x03, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xCF, 0x87, 0x87, 0x87,
        0x87, 0x87, 0x87, 0xC8, 0xF0, 0xF0, 0xF8, 0xFF
    }
};
//その他の固定記号
PROGMEM uint8_t letter[][16 * (16 / 8)]{
    //パーセント
    {
        0xFF, 0xFF, 0xC7, 0xBB, 0xBB, 0xBB, 0xC7, 0x7F,
        0x3F, 0x1F, 0x8F, 0xC7, 0xE7, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xE7, 0xE3, 0xF1, 0xF8, 0xFC,
        0xFE, 0xE3, 0xDD, 0xDD, 0xDD, 0xE3, 0xFF, 0xFF
    },
    //温度
    {
        0xFF, 0xFF, 0xC7, 0x93, 0x3B, 0x13, 0x87, 0xCF,
        0xCF, 0xCF, 0xCF, 0x8F, 0x1F, 0x3F, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xF0, 0xE0, 0xC7, 0xCF,
        0xCF, 0xCF, 0xCF, 0xC7, 0xE3, 0xF3, 0xFF, 0xFF
    },
};
PROGMEM uint8_t point[][8]{
    //小数点
    {
        0xFF, 0xC3, 0x81, 0x81, 0x81, 0x81, 0xC3, 0xFF
    }
};