void setup()
{
  // ! Define qué pin y si será entrada o salida
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  // ! Le dice al pin LED_BUILTIN que se ponga en alto (3.3V)
  digitalWrite(LED_BUILTIN, HIGH);
  // ! Espera 500ms!
  delay(100);
  // ! Ahora pon el pin en bajo (0V)
  digitalWrite(LED_BUILTIN, LOW);
  // ! Vuelve a esperar 500ms
  delay(100);
}