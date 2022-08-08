#define WELCOME "\nBienvenido a NodeMCU!"
#define MENU "Selecciona una de las siguientes opciones:\n1 - Saludar\n2 - Parpadear LED"

String input;

void setup() {
  delay(1000);

  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(115200);

  Serial.println(WELCOME);
  Serial.println(MENU);
}

void loop()
{
  if(Serial.available()) {
    input = read_user_input();
  }

  if(input == "1") {
    say_hi();
  }
  if(input == "2") {
    blink_led();
  }

  input = "";
}

String read_user_input() {
  String user_input = Serial.readString();
  user_input.trim();
  return user_input;
}

void say_hi() {
  Serial.println("Hola desde el NodeMCU!");
}

void blink_led() {
  Serial.println("Parpadeando LED...");
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
}