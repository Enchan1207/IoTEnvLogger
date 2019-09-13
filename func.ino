/*
 * 関数
*/

//--APIにアクセスし、データを送信
void sendEnvData(){
    //--送信前にデータ通信アイコンをオンにする
    disp.setMenuStatus(disp.getMenuStatus() | 0b010);

    String url = "/Enchan/api/IoTEnvLogger/"; 
    String param = "deviceID=" + String(deviceID) + "&temp=" + String(temp) + "&humid=" + String(humid);
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

//--起動時にデバイスIDを表示する設定になっているかチェック
int canIDShow(){
    //--送信前にデータ通信アイコンをオンにする
    disp.setMenuStatus(disp.getMenuStatus() | 0b010);
    String url = "/Enchan/api/IoTEnvLogger/config.php"; 
    String param = "type=showID&deviceID=" + String(deviceID);
    httpreq.connect(80);
    String responce = httpreq.request(url, param, 5000);
    statusCode = httpreq.getHTTPCode();
    //--ステータスコードが返ってきたら通信アイコンをオフにする
    disp.setMenuStatus(disp.getMenuStatus() & 0b101);

    //--ステータスコードで分岐
    if(statusCode == 200) return true;
    return false;
}