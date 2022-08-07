void setup()
{
  Serial.begin(9600);
}

void loop()
{
  // Serial.print("Hola desde el NodeMCU!\n");
  // Serial.println("Hola desde el NodeMCU!");
  // Serial.println(10);
  // Serial.println(255, HEX);

  int i = 0;

  while(i < 100) {
    i++;
    Serial.print("i es igual a: ");
    Serial.println(i);
    delay(500);
  }
}