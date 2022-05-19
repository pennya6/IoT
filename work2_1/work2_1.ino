int led_num[]={13,12,11,10,9};
void setup()
{
  for(int j=0;j<5;j++){
    pinMode(led_num[j],OUTPUT);
  }
  pinMode(8,INPUT);
}

void loop()
{
  int j=0;
  int ran=random(5); //랜덤
  int value=digitalRead(8);
  if (value==HIGH){
    while(j<3){
      j++;
      for (int i=9;i<14;i++){
        digitalWrite(i,HIGH);
        delay(500);
        digitalWrite(i,LOW);
    }
   }
    digitalWrite(led_num[ran],HIGH);
  }
  
}
