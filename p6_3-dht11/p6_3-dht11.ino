#include <DHT.h>
#include <DHT_U.h>

DHT dht(D1, DHT11);

float tempF;

void setup()
{
  Serial.begin(115200);
  dht.begin();
}

void loop()
{
  tempF = dht.readTemperature(true);
  Serial.println("Temperatura: " + String(tempF) + "°F");
  delay(2000);
}