int my_button = D0;

void setup()
{
  pinMode(my_button, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  Serial.println(digitalRead(my_button));

  if(digitalRead(my_button) == HIGH) {
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    digitalWrite(LED_BUILTIN, LOW);
  }
}