#include <ESP8266WiFi.h>
#include <Hash.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>

String my_ssid = "ESP8266-IoT";
String my_password = "asdf1234";

AsyncWebServer server(80);

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0"/>
  <link rel="icon" href="data:image/x-icon;base64,">
  <title>Hello world!</title>
</head>
<body>
  <h1>Hola desde el NodeMCU!</h1>
</body>
</html>
)rawliteral";

void setup()
{
  Serial.begin(115200);
  Serial.print("Setting AP (Access Point)…");
  WiFi.softAP(my_ssid, my_password);

  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", index_html);
  });

  server.begin();
}

void loop()
{

}