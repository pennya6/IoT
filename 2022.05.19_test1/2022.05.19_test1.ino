//2022.05.19
//가변저항 실습
//아날로그 입력
void setup() {
  Serial.begin(9600);
}
void loop() {
  int value=analogRead(A0); //아날로그 읽기, 0~1023값 들어올 예정
  Serial.println(value); //모니터 출력
  delay(1000);
  //analogWrite(9,value); //안됨 ,0~255값을 줘야하기 때문
  int value2=map(value,0,1023,0,255); //0~1023값을 0~255로 바꿈
  analogWrite(9,value2);
  
}
