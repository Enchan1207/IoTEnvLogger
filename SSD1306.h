/*
 * SSD1306ハードウェアベース制御クラス
*/

#include <Arduino.h>

class SSD1306{
    public:
        SSD1306(int SDApin, int SCLpin, int addr);
        SSD1306();
        void drawBMP(int _x, int _y, int _w, int _h, uint8_t *data, int inv);
        void setContrast(float val);
        void softReset();
        void cls();

    private:
        void i2cWrite(uint8_t command[], int comm_length);
        int ADDR, SCL, SDA;
};