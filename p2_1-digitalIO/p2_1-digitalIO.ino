int my_button = D1;

void setup()
{
  pinMode(my_button, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  if(digitalRead(my_button) == LOW) {
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    digitalWrite(LED_BUILTIN, LOW);
  }
}