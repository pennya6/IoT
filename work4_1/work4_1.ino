int cur_state=1;
int before_state=0;
byte digits[4][8]={
  {0,0,0,0,0,0,1,1}, //0
  {0,1,1,0,0,0,1,1}, //C
  {0,1,1,0,1,0,0,1}, //F
  {1,1,1,1,1,1,1,1} //everything off
};
void setup() {
  //버튼 input
  pinMode(2,INPUT);

  //segment
  for(int i=3;i<11;i++){
    pinMode(i,OUTPUT);
  }
  digitalWrite(10,LOW);
  //초음파
  pinMode(12,OUTPUT); //trig
  pinMode(11,INPUT); //echo
}
void loop() {

    digitalWrite(12,HIGH);
    delayMicroseconds(11);
    digitalWrite(12,LOW);
    long duration = pulseIn(11,HIGH);
    if(duration ==0){
      return;
    }
    long distance=duration/58.2;

    cur_state=digitalRead(2);
    if((cur_state==HIGH)&&(before_state==LOW)){
      if (distance<10){
        displayDigit(1);
      }else if(distance>60){
        displayDigit(2);
      }else{
        displayDigit(0);
      }
    }else{
      displayDigit(3);
    }
}
void displayDigit(int num){
  int pin=3;
  for (int i=0;i<8;i++){
    digitalWrite(pin+i,digits[num][i]);
  }
}
int debounceButton(int last){
  int current=digitalRead(2);
  if(last!=current){
    delay(10);
    current=digitalRead(2);
  }
  return current;
}
