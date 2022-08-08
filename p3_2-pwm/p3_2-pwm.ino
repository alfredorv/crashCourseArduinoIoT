char red = D1;
char green = D2;
char blue = D3;
int my_delay = 5;

void setup() {}

void loop()
{
  for(int i = 0; i <= 512; i++) {
    analogWrite(red, i);
    delay(my_delay);
  }
  for(int i = 511; i > 0; i--) {
    analogWrite(red, i);
    delay(my_delay);
  }
  for(int i = 0; i <= 512; i++) {
    analogWrite(green, i);
    delay(my_delay);
  }
  for(int i = 511; i > 0; i--) {
    analogWrite(green, i);
    delay(my_delay);
  }
  for(int i = 0; i <= 512; i++) {
    analogWrite(blue, i);
    delay(my_delay);
  }
  for(int i = 511; i > 0; i--) {
    analogWrite(blue, i);
    delay(my_delay);
  }
}