int val9=LOW;
int lastButton=LOW;
void setup() {
  pinMode(2,INPUT);
  pinMode(9,OUTPUT);
}
void loop() {
  int currentButton=digitalRead(2);
  if (lastButton==LOW&&currentButton==HIGH){
    val9=!val9;
  }
  digitalWrite(9,val9);
  lastButton=currentButton;

}
