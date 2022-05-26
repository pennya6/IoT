void setup() {
  pinMode(2,OUTPUT); //trig -> 전압이 HIGH가 되면 초음파 발사
  pinMode(3,INPUT);//Echo-> 이 부분을 통해 초음파가 돌아오는 곳을 감지 , 처음에는 전압이 LOW
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);

}

void loop() {
  digitalWrite(2,HIGH);
  delayMicroseconds(10); //아두이노 보드를 일정시간 멈추는 함수
  digitalWrite(2,LOW);

  long duration=pulseIn(3,HIGH);
  if(duration==0){
    return;
  }
  long distance=duration/58.2;

  if(distance<10){
    digitalWrite(8,1);
    digitalWrite(9,1);
  }else if(distance<25){
    digitalWrite(8,1);
    digitalWrite(9,0);
  }else{
    digitalWrite(8,0);
    digitalWrite(9,0);
  }

}
