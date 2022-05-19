int val9=LOW;
int lastButton=LOW;
void setup()
{
  pinMode(12, OUTPUT);
  pinMode(2,INPUT);
}

void loop()
{
  int currentButton=debounceButton(lastButton);
  if(lastButton==LOW&&currentButton==HIGH){
    val9=!val9;
  }
  digitalWrite(12,val9);
  lastButton=currentButton;
}
int debounceButton(int last){
  int current=digitalRead(2);
  if(last!=current){
    delay(10);
    current=digitalRead(2);
  }
  return current;
}
