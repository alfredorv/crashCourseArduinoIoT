#include <DHT.h>
#include <DHT_U.h>

DHT dht(D1, DHT11);

float tempC;

void setup()
{
  Serial.begin(115200);
  dht.begin();
}

void loop()
{
  tempC = dht.readTemperature();
  Serial.println("Temperatura: " + String(tempC) + "°C");
  delay(2000);
}