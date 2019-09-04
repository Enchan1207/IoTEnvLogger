/*
 * HTTPリクエスト送信
*/

#include "HTTPReq.h"
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include "WiFi.ini.h"

HTTPReq::HTTPReq(){

}

//--
boolean HTTPReq::connect(int httpPort){
    return client.connect(API_HOST, httpPort) == 1;
}

//--
String HTTPReq::request(String url, String param, int timeout){
    //--サーバに送るリクエストメッセージを作成
    int datLength = param.length();
    String reqString = String("POST ") + url + " HTTP/1.1\r\n" +
    "Host: " + API_HOST + "\r\n" +
    "Connection: close\r\n" +
    "Content-Length: "+ datLength +"\r\n" +
    "User-Agent: ESP-WROOM-02 module\r\n" +
    "Content-Type: application/x-www-form-urlencoded\r\n" +
    "\r\n" +
    param + "\r\n";

    //--サーバにリクエストを送信 帰ってくるデータがないまま5秒経過したらタイムアウトとする
    client.print(reqString);
    int limit = millis() + timeout;
    while (client.available() == 0) {
        if (limit - millis() < 0) {
            client.stop();
            return "";
        }
    }

    //--HTTPヘッダを含むレスポンスをreturn
    int index = 0;
    String resp = "";
    while(client.available()){
        String line = client.readStringUntil('\r');
        //--最初の行にあるステータスコードを取得
        if(index == 0) {
            statusCode = line.substring(9, 12).toInt();
        }
        resp += line;
        index++;
    }
    return resp;
}

//--最後に投げたリクエストのステータスコードを取得
int HTTPReq::getHTTPCode(){
    return statusCode;
}