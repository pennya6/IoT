//씨리얼 모니터에 
//입력창 a,b a:20도 증가, b:0 리셋
//출력창 rkreh qhdla 
#include <Servo.h>
Servo myservo;
char content;
int r=0;
void setup() {
  myservo.attach(9);
  Serial.begin(9600);
}

void loop() {
  while(true){
    if(Serial.available()){
    content=Serial.read();
    if(content=='a'){
      r=r+20;
      if(r>=180){
        r=180;
      }
      myservo.write(r);
      Serial.println(r);
      delay(15);
    }else {
      r=0;
      myservo.write(r);
      Serial.println(r);
      delay(15);
    }
  }
    
  }
  
//  int val=analogRead(A0);
//  int rad=map(val,0,1023,0,120); //0-1023 -> 0-120 변환
//  myservo.write(rad);
//  delay(15);
}
