/*
 * SSD1306ハイレベル制御クラス
*/

#include "SSD1306.h"
#include <Arduino.h>

class Display : public SSD1306 {
    public:
        Display(SSD1306 _oled);
        void setMenuStatus(uint8_t stat);
        void setTemp(float temp);
        void setHumid(float humid);

    private:
        SSD1306 oled;
        void setValue(int value, int x_offset);

};