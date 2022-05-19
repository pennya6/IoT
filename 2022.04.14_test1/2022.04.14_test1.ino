void setup() {
  Serial.begin(9600);
}
void loop() {
  if(Serial.available()){
    char c = Serial.read();
    int a=0;
    if(c=='0'){
      a=0;
      analogWrite(9,a);
    } else if(c=='1'){
      a=127;
      analogWrite(9,a);
    }else if(c=='2'){
      a=255;
      analogWrite(9,a);
    }
    Serial.println(a);
  }
}
