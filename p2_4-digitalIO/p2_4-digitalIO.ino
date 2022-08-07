int my_button = D1;
char led_state = 0;

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(my_button, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(my_button), toggle_led, CHANGE);
}

void loop() {}

void toggle_led() {
  led_state = !led_state;
  digitalWrite(LED_BUILTIN, led_state);
}