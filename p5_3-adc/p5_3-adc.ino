void setup()
{
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  int value = analogRead(A0);
  Serial.print("El valor del ADC es: ");
  Serial.println(value);

  if(value >= 0 && value <= 700) {
    digitalWrite(LED_BUILTIN, HIGH);
  } else if (value > 800) {
    digitalWrite(LED_BUILTIN, LOW);
  }

  delay(50);
}