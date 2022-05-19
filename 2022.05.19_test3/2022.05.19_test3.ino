//LCD 표시하기

#include <LiquidCrystal.h>

//객체선언
LiquidCrystal lcd(12,11,2,3,4,5); //RS, E, D4, D5, D6, D7

void setup() {
  lcd.begin(16,2); //16열 2행
}
void loop() {
  int light=analogRead(A0); //조도센서 아날로그 읽기

  lcd.clear();
  lcd.print("Light: ");
  lcd.print(light);
  delay(500);
}
