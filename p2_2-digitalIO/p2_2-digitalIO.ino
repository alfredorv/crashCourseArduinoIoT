int my_button = D1;

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(my_button, INPUT_PULLUP);
}

void loop()
{
  if(digitalRead(my_button) == HIGH) {
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    digitalWrite(LED_BUILTIN, LOW);
  }
}