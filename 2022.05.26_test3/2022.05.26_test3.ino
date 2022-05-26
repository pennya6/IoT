//E만들기
byte digits[10][7]={
  {0,0,0,0,0,0,1},
  {1,0,0,1,1,1,1},
  {0,0,1,0,0,1,0},
  {0,0,0,0,1,1,0},
  {1,0,0,1,1,0,0},
  {0,1,0,0,1,0,0},
  {0,1,0,0,0,0,0},
  {0,0,0,1,1,1,1},
  {0,0,0,0,0,0,0},
  {0,0,0,1,1,0,0}
};
void setup() {
  for (int i=2;i<8;i++){
    pinMode(i,OUTPUT);
  }
  //digitalWrite(9,HIGH);//dp
}

void loop() {
  for(int i=2;i<10;i++){
    digitalWrite(i,0);
  }
  digitalWrite(9,1);
  
}
