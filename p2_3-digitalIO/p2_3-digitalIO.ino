int my_button = D1;
char led_status = LOW;
bool prev_button_state;
bool curr_button_state;

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(my_button, INPUT_PULLUP);
}

void loop()
{
  prev_button_state = curr_button_state;
  curr_button_state = digitalRead(my_button);

  if(prev_button_state == HIGH && curr_button_state == LOW) {
    led_status = !led_status;
    digitalWrite(LED_BUILTIN, led_status);
  }
}