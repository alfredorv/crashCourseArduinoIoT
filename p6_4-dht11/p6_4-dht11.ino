#include <DHT.h>
#include <DHT_U.h>

DHT dht(D1, DHT11);

float tempC;
float tempF;
float humidity;
float heat_index;


void setup()
{
  Serial.begin(115200);
  dht.begin();
}

void loop()
{
  tempC = dht.readTemperature();
  tempF = dht.readTemperature(true);
  humidity = dht.readHumidity();
  heat_index = dht.computeHeatIndex(tempC, humidity);

  Serial.println("Temperatura: " + String(tempC) + "°C");
  Serial.println("Temperatura: " + String(tempF) + "°F");
  Serial.println("Humedad: " + String(humidity) + "%");
  Serial.println("Sensación térmica: " + String(heat_index) + "°C");
  Serial.print("\n\n\n");
  delay(2000);
}