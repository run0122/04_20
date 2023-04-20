void setup() {
  Serial.begin(9600); // 시리얼 통신 시작
}

void loop() {
  long myInt;
  if (Serial.available() > 0) {
    myInt = Serial.parseInt(SKIP_ALL, '\n');

    // prints the received integer
    Serial.print("I received: ");
    Serial.println(myInt);
    Serial.write(myInt);
    delay(1000);
  }
  // int value = 123; // 전송할 데이터
  // Serial.write(value); // 데이터 전송
  // delay(1000); // 1초 대기
}