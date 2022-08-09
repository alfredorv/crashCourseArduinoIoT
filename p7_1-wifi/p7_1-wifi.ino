#include <ESP8266WiFi.h>

String ssid = "TP-Link_908A";
String password = "60536006";


void setup()
{
  Serial.begin(115200);
  Serial.println();

  WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED) {
    Serial.println(".");
  }
  Serial.println("************************");
  Serial.print("Conectado a: ");
  Serial.println(WiFi.SSID());
  Serial.print("Dirección IP: ");
  Serial.println(WiFi.localIP());
  Serial.println("************************");
}

void loop()
{

}