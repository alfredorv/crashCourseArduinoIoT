#include <ESP8266WiFi.h>
#include <Hash.h>
#include <ESP8266WebServer.h>
#include <DHT.h>
#include <DHT_U.h>

/*
  Variables WiFi
*/
ESP8266WebServer server(80);
String my_ssid = "ESP8266-IoT";
String my_password = "asdf1234";

/*
  Variables DHT11
*/
#define INTERVAL  1000
DHT dht(D1, DHT11);
float tempC;
float tempF;
float humidity;
float heat_index;
unsigned long previous_millis = 0;


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
    html = "<!DOCTYPE html><html lang=\"en\"><head><meta http-equiv=\"refresh\" content=\"2\" charset=\"UTF-8\"><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"/><link rel=\"icon\" href=\"data:image/x-icon;base64,\"><title>DHT Web Server</title></head><body><h1>DHT Web Server</h1>";
    html += "<div><span>Temperatura en °C =</span><span>";
    html += tempC;
    html += "</span></div>";
    html += "<div><span>Temperatura en °F =</span><span>";
    html += tempF;
    html += "</span></div>";
    html += "<div><span>\% de humedad =</span><span>";
    html += humidity;
    html += "</span></div>";
    html += "<div><span>\Sensación térmica en °C=</span><span>";
    html += heat_index;
    html += "</span></div>";
    html += "</body></html>";
    server.send(200, "text/html", html);
  });

  server.begin();

  dht.begin();
}

void loop()
{
  server.handleClient();

  unsigned long current_millis = millis();
  if((current_millis - previous_millis) >= INTERVAL ) {
    previous_millis = current_millis;

    tempC = dht.readTemperature();
    tempF = dht.readTemperature(true);
    humidity = dht.readHumidity();
    heat_index = dht.computeHeatIndex(tempC, humidity);
  }
}