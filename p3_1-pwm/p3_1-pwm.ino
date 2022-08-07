char red = D1;

void setup()
{
}

void loop()
{
  for(int i = 0; i <= 512; i++) {
    analogWrite(red, i);
    delay(10);
  }
}