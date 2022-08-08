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
  tempC = dht.readHumidity();
  Serial.println("Humedad: " + String(tempC) + "%");
  delay(2000);
}