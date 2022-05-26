//가변저항으로 조절해서 값 조절
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

void setup() {
  pinMode(11,INPUT);
  pinMode(12,INPUT);
  for (int i=2;i<10;i++){
    pinMode(i,OUTPUT);
  }
  digitalWrite(9,HIGH);
}

void loop() {
  int value=analogRead(A0);
  int value2=map(value,0,1023,0,9);
  displayDigit(value2);
  delay(1000);
}
void displayDigit(int num){
  int pin=2;
  for(int i=0;i<7;i++){
    digitalWrite(pin+i,digits[num][i]);
  }
}
