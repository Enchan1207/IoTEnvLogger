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
SHT31 sht31 = SHT31(0x45);
float temp = 0.0, humid = 0.0;

//--APIリクエスト
const String deviceID = "EnchanESP02";
HTTPReq httpreq = HTTPReq();
int statusCode;
boolean isConnected = false; //WiFi接続状態

int lcnt = 0, gm = 0; //ループカウンタ、動作モード

//--APIにアクセスし、データを送信
void sendEnvData(){
    //--送信前にデータ通信アイコンをオンにする
    disp.setMenuStatus(disp.getMenuStatus() | 0b010);

    String url = "/Enchan/api/IoTEnvLogger/"; 
    String param = "deviceID=" + deviceID + "&temp=" + temp + "&humid=" + humid;
    httpreq.connect(80);
    httpreq.request(url, param, 5000);
    statusCode = httpreq.getHTTPCode();
    //--ステータスコードが返ってきたら通信アイコンをオフにする
    disp.setMenuStatus(disp.getMenuStatus() & 0b101);
}

//--温湿度データを取得し、ディスプレイに反映
void updateDisplay(){
    //--温湿度取得
    sht31.GetTempHum();
    temp = sht31.Temperature();
    humid = sht31.Humidity();
    //--画面に反映
    disp.setTemp(temp);
    disp.setHumid(humid);
}

//--WiFi接続状態を表示
void showWiFiInfo(){
    if(WiFi.status() == WL_CONNECTED) {
        isConnected = true;
        disp.setMenuStatus(disp.getMenuStatus() | 0b001);
    }else {
        isConnected = false;
        disp.setMenuStatus(disp.getMenuStatus() & 0b110);
    }
}

void setup(){
    sht31.SoftReset(); //SHT31初期化
    WiFi.begin(WiFi_SSID, WiFi_PASSWORD); //WiFi接続
}

void loop(){
    //--WiFiの接続状態を表示
    showWiFiInfo();

    //--指定間隔ごとにAPIを叩き、データを送信
    if((lcnt % 15) == 0 && isConnected) sendEnvData();

    //--温湿度データは毎秒更新する
    updateDisplay();

    delay(1e3);
    lcnt++;
    if(lcnt > INT_MAX) lcnt = 0; //オーバーフロー対策
}