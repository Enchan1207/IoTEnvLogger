/*
 * 温湿度計
*/

#include <ESP8266WiFi.h>
#include "lib/WiFi.ini.h"
#include "lib/HTTPReq.cpp"

#include "lib/Display.cpp"
#include "lib/SHT31.cpp"

//--SSD1306
SSD1306 oled = SSD1306(4, 14, 0x3C);
Display disp = Display(oled);

//--SHT31
SHT31 sht31 = SHT31(0x44);
float temp = 0.0, humid = 0.0;

//--APIリクエスト
const String deviceID = "EnchanESP02";
HTTPReq httpreq = HTTPReq();
int statusCode;
boolean isConnected = false; //WiFi接続状態

//--
boolean isPairingTrialed = false; //ペアリング試行済み?

int lcnt = 0, gm = 0; //ループカウンタ、動作モード

void setup(){
    Serial.begin(115200);
    sht31.SoftReset(); //SHT31初期化
    WiFi.begin(WiFi_SSID, WiFi_PASSWORD); //WiFi接続
}

void loop(){
    //--WiFiの接続状態を表示
    showWiFiInfo();

    //--ペアリングリクエストを確認、リクエストが来ていればワンタイムパスを出力してリセットまで待機
    if(!isPairingTrialed && isConnected){
        isPairingTrialed = true;
        int onetime_pass = checkPairingReq();
        if(onetime_pass != 0){
            disp.putDigit(onetime_pass);
            while(true){
                delay(1e3);
            }
        }
    }

    //--指定間隔ごとにAPIを叩き、データを送信
    if((lcnt % 15) == 0 && isConnected) sendEnvData();

    //--温湿度データは毎秒更新する
    updateDisplay();

    delay(1e3);
    lcnt++;
    if(lcnt > INT_MAX) lcnt = 0; //オーバーフロー対策
}