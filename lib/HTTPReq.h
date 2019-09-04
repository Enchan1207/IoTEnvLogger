/*
 * HTTPリクエスト送信
*/

#include <ESP8266WiFi.h>
#include <Arduino.h>

class HTTPReq{
    public:
        HTTPReq();
        boolean connect(int httpPort);
        String request(String url, String param, int timeout);
        int getHTTPCode();
        
    private:
        WiFiClient client;
        int statusCode;
};