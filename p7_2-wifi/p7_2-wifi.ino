#include <ESP8266WiFi.h>
#include <Hash.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>

String my_ssid = "ESP8266-IoT";
String my_password = "asdf1234";

AsyncWebServer server(80);

void setup()
{
  Serial.begin(115200);
  Serial.print("Setting AP (Access Point)…");
  WiFi.softAP(my_ssid, my_password);

  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);
}

void loop()
{

}