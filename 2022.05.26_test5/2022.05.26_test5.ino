//버튼을 누르면 숫자 8을 3번 깜박인후 1~6 랜덤 출력

byte digits[10][7]={
  {0,0,0,0,0,0,1}, //0
  {1,0,0,1,1,1,1}, //1
  {0,0,1,0,0,1,0},//2
  {0,0,0,0,1,1,0},//3
  {1,0,0,1,1,0,0},//4
  {0,1,0,0,1,0,0},//5
  {0,1,0,0,0,0,0},//6
  {0,0,0,1,1,1,1},//7
  {0,0,0,0,0,0,0},//8
  {0,0,0,1,1,0,0}//9
};
void displayOff(){
  int pin=2;
  for(int i=0;i<7;i++){
    digitalWrite(pin+i,1);
  }
}
void setup() {
  randomSeed(analogRead(A3)); //고정되지 않게 함 -> 확정적이지 않은 값이 들어옴
  pinMode(12,INPUT);
  for (int i=2;i<10;i++){
    pinMode(i,OUTPUT);
  }
  digitalWrite(9,HIGH);
}

void loop() {
  int ran=random(1,7); //1이상 7미만
  if(digitalRead(12)==HIGH){
    for(int i=0;i<3;i++){
      displayDigit(8);
      delay(500);
      displayOff();
      delay(500);
    }
    displayDigit(ran);
  }
}
void displayDigit(int num){
  int pin=2;
  for(int i=0;i<7;i++){
    digitalWrite(pin+i,digits[num][i]);
  }
}
