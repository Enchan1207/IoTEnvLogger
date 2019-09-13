/*
 * SSD1306ハイレベル制御クラス
*/

#include "SSD1306.cpp"
#include <Arduino.h>

class Display : public SSD1306 {
    public:
        Display(SSD1306 _oled);
        void setMenuStatus(uint8_t stat);
        uint8_t getMenuStatus();
        void setTemp(float temp);
        void setHumid(float humid);
        void putDigit(int digit);
        void cls();

    private:
        SSD1306 oled;
        uint8_t status;
        void setValue(int value, int x_offset);

};