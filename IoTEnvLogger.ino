/*
 * 温湿度計
*/

#include <ESP8266WiFi.h>
#include "WiFi.ini.h"
#include "HTTPReq.h"

#include "Display.h"
#include "SHT31.h"

//--SSD1306
SSD1306 oled = SSD1306(4, 14, 0x3C);
Display disp = Display(oled);

//--SHT31
SHT31 sht31 = SHT31(0x45);
float temp = 0.0, humid = 0.0;

//--APIリクエスト
const String deviceID = "EnchanESP02";
HTTPReq httpreq = HTTPReq();
int statusCode;

int lcnt = 0;

//--APIにアクセスし、データを送信
void sendEnvData(){
    String url = "/Enchan/api/IoTEnvLogger/"; 
    String param = "deviceID=" + deviceID + "&temp=" + temp + "&humid=" + humid;
    httpreq.connect(80);
    httpreq.request(url, param, 5000);
    statusCode = httpreq.getHTTPCode();
}

void setup(){
    sht31.SoftReset(); //SHT31初期化
    //--WiFi接続
    disp.setMenuStatus(disp.getMenuStatus() | 0b000); //元のステータスとORとらないと書き換えられちゃう
    WiFi.begin(WiFi_SSID, WiFi_PASSWORD);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    disp.setMenuStatus(disp.getMenuStatus() | 0b001);
}

void loop(){
    //--温湿度取得
    sht31.GetTempHum();
    temp = sht31.Temperature();
    humid = sht31.Humidity();

    //--画面に反映
    disp.setTemp(temp);
    disp.setHumid(humid);

    //--指定インターバルでデータを送信
    if((lcnt % 2) == 0) {
        sendEnvData();
        disp.setMenuStatus(disp.getMenuStatus() | (statusCode == 200) << 1);
    }

    delay(10e3); //30sec
    lcnt++;
}