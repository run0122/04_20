#include <SPI.h>
char data2;

void setup(void) {
  // SPI 통신을 위한 핀들의 입출력 설정
  pinMode(MISO, OUTPUT);
  pinMode(MOSI, INPUT);
  pinMode(SCK, INPUT);
  pinMode(SS, INPUT);
  // 마스터의 전송 속도에 맞추어 통신 속도를 설정한다.
  SPI.setClockDivider(SPI_CLOCK_DIV16);
  // SPI 통신을 위한 레지스터를 설정
  SPCR |= _BV(SPE);    // SPI 활성화
  SPCR &= ~_BV(MSTR);  // Slave 모드 선택
  SPCR |= _BV(SPIE);   // 인터럽트 허용
  data2 = '0';         // 카운터 초기화
}
// SPI 통신으로 데이터가 수신될 때 발생하는 인터럽트 처리 루틴
ISR(SPI_STC_vect) {
  SPDR = data2;  // 카운터 값을 ASCII 값으로 전달
}
void loop(void) {
  if (Serial.available()) {  // 만약 시리얼 통신이 온다면

    data2 = Serial.read();  // 시리얼 통신 값을 문자형변수 data에 저장

    Serial.println(data2);  // 그 값을 출력
  }
}