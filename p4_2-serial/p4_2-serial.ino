void setup()
{
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  if(Serial.available()) {
    char my_character = Serial.read();

    if(my_character == 'o') {
      digitalWrite(LED_BUILTIN, HIGH);
    } else if(my_character == 'n') {
      digitalWrite(LED_BUILTIN, LOW);
    }
  }
}