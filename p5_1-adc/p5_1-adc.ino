void setup()
{
  Serial.begin(115200);
}

void loop()
{
  int value = analogRead(A0);
  Serial.print("El valor del ADC es: ");
  Serial.println(value);
  delay(100);
}