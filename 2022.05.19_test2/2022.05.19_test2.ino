//가변저항
//led 3개
//신호등처럼 가변저항
//1) 모두 다 꺼짐(0) -> 가변저항 
//2) 빨(1) -> 가변저항 
//3) 노(2) -> 가변저항
//4) 녹(3) -> 가변저항 1023
//구간별로 쪼개서 하기
void setup() {
//  pinMode(9,OUTPUT);
//  pinMode(10,OUTPUT);
//  pinMode(11,OUTPUT);
}
void loop() {
  int value=analogRead(A0);
  int value2=map(value,0,1023,0,3);//0,1,2,3 값만 가지면 되니까!
  controllLED(value2);
}
//controllLED 함수
void controllLED(int control){
  //all clear ==0
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW); 
  if(control==1){
  //only red ==1
    digitalWrite(9,HIGH);
  } else if(control==2){
  //only yellow ==2
    digitalWrite(10,HIGH);
  }else if (control==3){
  //only green ==3
    digitalWrite(11,HIGH);
  }
}
