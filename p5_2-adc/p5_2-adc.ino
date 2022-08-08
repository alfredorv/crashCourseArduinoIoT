void setup()
{
  Serial.begin(115200);
}

void loop()
{
  int value = analogRead(A0);
  Serial.print("El valor del ADC es: ");
  Serial.println(value);

  float voltage = value * (3.3 / 1024);
  Serial.print("El voltaje es: ");
  Serial.println(voltage);
  delay(100);
}