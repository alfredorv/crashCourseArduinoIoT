#include <ESP8266WiFi.h>
#include <Hash.h>
#include <ESP8266WebServer.h>

String my_ssid = "ESP8266-IoT";
String my_password = "asdf1234";

int contador = 1;

ESP8266WebServer server(80);

void setup()
{
  Serial.begin(115200);
  Serial.print("Setting AP (Access Point)…");
  WiFi.softAP(my_ssid, my_password);

  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);

  server.on("/", HTTP_GET, [](){
    String html;
    html.reserve(1024);
    html = "<!DOCTYPE html><html lang=\"en\"><head><meta charset=\"UTF-8\"><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"/><link rel=\"icon\" href=\"data:image/x-icon;base64,\"><title>Contador!</title></head><body><h1>Contador!</h1><div>";
    html += contador++;
    html += "</div>";
    html += "</body></html>";
    server.send(200, "text/html", html);
  });

  server.begin();
}

void loop()
{
  server.handleClient();
}