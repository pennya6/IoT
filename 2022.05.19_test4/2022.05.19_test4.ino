#include <LiquidCrystal.h>
//객체선언
LiquidCrystal lcd(12,11,2,3,4,5); //RS, E, D4, D5, D6, D7
void setup() {
 pinMode(8,OUTPUT);
 pinMode(9,INPUT);
 lcd.begin(16,2);
}

void loop() {
  digitalWrite(8, HIGH);
  delayMicroseconds(10);
  digitalWrite(8, LOW);
  
  long duration = pulseIn(0, HIGH);

  if (duration == 0) {
    return;
    }

    long distance = duration / 58.2;
    lcd.clear();
    lcd.print("Distance");
    lcd.setCursor(0,1);
    lcd.print(distance);
    lcd.print(" cm");
    delay(500);
    
}
