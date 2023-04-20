void setup(){
  Serial.begin(9600);
}

void loop(){
  while(Serial.available()){
    char data = Serial.read();
    Serial.print(data);
  }  
}