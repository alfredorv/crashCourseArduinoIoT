#include <DHT.h>
#include <DHT_U.h>

DHT dht(D1, DHT11);

float humidity;

void setup()
{
  Serial.begin(115200);
  dht.begin();
}

void loop()
{
  humidity = dht.readHumidity();
  Serial.println("Humedad: " + String(humidity) + "%");
  delay(2000);
}