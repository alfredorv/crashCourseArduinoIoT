#include <ESP8266WiFi.h>
#include <Hash.h>
#include <ESP8266WebServer.h>

/*
  Variables WiFi
*/
ESP8266WebServer server(80);
String my_ssid = "ESP8266-IoT";
String my_password = "asdf1234";
const String html = "<!DOCTYPE html><html lang=\"en\"><head>  <meta charset=\"UTF-8\">  <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"/>  <link rel=\"icon\" href=\"data:image/x-icon;base64,\">  <title>RGB LED</title></head><body>  <h1>Control de LED RGB</h1>  <form action=\"/rgb\">    <label for=\"red\">Rojo:</label><br>    <input type=\"text\" id=\"red\" name=\"red\" value=\"0\"><br>    <label for=\"green\">Verde:</label><br>    <input type=\"text\" id=\"green\" name=\"green\" value=\"0\"><br>    <label for=\"blue\">Azul:</label><br>    <input type=\"text\" id=\"blue\" name=\"blue\" value=\"0\"><br><br>    <input type=\"submit\" value=\"Enviar\">  </form></body></html>";


void setup()
{
  Serial.begin(115200);
  Serial.print("Setting AP (Access Point)…");
  WiFi.softAP(my_ssid, my_password);

  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);

  server.on("/", HTTP_GET, [](){
    server.send(200, "text/html", html);
  });

  server.on("/rgb", HTTP_GET, set_rgb_values);

  server.begin();
}

void loop()
{
  server.handleClient();
}

void set_rgb_values() {
  int red = server.arg("red").toInt();
  int green = server.arg("green").toInt();
  int blue = server.arg("blue").toInt();

  Serial.print("Red: " + String(red));
  Serial.print("green: " + String(green));
  Serial.print("blue: " + String(blue));

  analogWrite(D1, red);
  analogWrite(D2, green);
  analogWrite(D3, blue);

  server.send(200, "text/html", html);
}