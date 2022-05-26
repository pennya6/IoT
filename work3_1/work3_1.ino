#include <LiquidCrystal.h>
//객체선언
LiquidCrystal lcd(12,11,2,3,4,5); //RS, E, D4, D5, D6, D7
void setup() {
  lcd.begin(16,2); //16열 2행
}
void loop() {
  int value=analogRead(A0);
  int value2=map(value,0,1023,0,1023);
  int value3=map(value,0,1023,0,100);
  
  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("up : ");
  lcd.print(value2);

  lcd.setCursor(0,1);
  lcd.print("down :");
  lcd.print(value3);
  delay(500);
}
