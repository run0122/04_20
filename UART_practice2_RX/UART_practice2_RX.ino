void setup() {
  Serial.begin(9600); // 시리얼 통신 시작
}

void loop() {
  if (Serial.available()) { // 데이터가 수신되었는지 확인
    int value = Serial.read(); // 데이터 수신
    Serial.println(value); // 수신된 데이터 출력
  }
}