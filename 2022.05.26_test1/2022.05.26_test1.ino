void setup() {
  pinMode(2,OUTPUT); //trig -> 전압이 HIGH가 되면 초음파 발사
  pinMode(3,INPUT);//Echo-> 이 부분을 통해 초음파가 돌아오는 곳을 감지 , 처음에는 전압이 LOW
}

void loop() {
  analogWrite(11,0);
  analogWrite(10,0);
  analogWrite(9,0);
  digitalWrite(2,HIGH);
  delayMicroseconds(10); //아두이노 보드를 일정시간 멈추는 함수
  digitalWrite(2,LOW); //멈출시간

  long duration=pulseIn(3,HIGH);
  if(duration==0){
    return;
  }
  long distance=duration/58.2;

  if(distance<10){
    analogWrite(11,255);
  }else if(distance<20){
    analogWrite(10,255);
  }else if(distance<30){
    analogWrite(9,255);
  }
  delay(100);
}
