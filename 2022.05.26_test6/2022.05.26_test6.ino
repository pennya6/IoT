//세그먼트 2개
//DP 세그먼트 2개 연결 , 같은 단자들 끼리 연결 -> 핀이 부족하기 떄문, 즉 동시에 켜짐
//단 11번, 12번 연결 -> low, high로 둘중 하나 키기를 조절, 컨트럴하기 위해서 디지털로 연결
//번갈아서 키는거지만 동시에 키는것처럼 보임

//0~99 하기

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
int digitMax=2; //자리수
int digitPin[]={11,12};
void setup() {
  pinMode(11,INPUT);
  pinMode(12,INPUT);
  for (int i=2;i<10;i++){
    pinMode(i,OUTPUT);
  }
  digitalWrite(9,HIGH);
}

void loop() {
  for (int i=0;i<10000;i++){
    displayNumber(i/100);
  }
}
//딜레이 없이 계속 찍어야 잔상이 남음
void displayNumber(int num){
  if(num==0)displayDigit(0,0);
  else{
    for(int i=0;i<digitMax;i++){
      if(num>0){
        displayDigit(num%10,i);
        num=num/10;
      }
      delay(10);
    }
  }
}
void displayDigit(int val,int poe){
  digitalWrite(digitPin[0],HIGH);
  digitalWrite(digitPin[1],HIGH);
 
  for(int i=0;i<7;i++){
    digitalWrite(i+2,digits[val][i]);
    digitalWrite(digitPin[poa],LOW);
  }
  
}
