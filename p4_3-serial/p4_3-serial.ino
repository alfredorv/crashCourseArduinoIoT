void setup()
{
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  if(Serial.available()) {
    String my_string = Serial.readString();
    my_string.trim();

    if(my_string == "LED_ON") {
      digitalWrite(LED_BUILTIN, LOW);
    } else if(my_string == "LED_OFF") {
      digitalWrite(LED_BUILTIN, HIGH);
    }
    Serial.println(my_string);
  }
}