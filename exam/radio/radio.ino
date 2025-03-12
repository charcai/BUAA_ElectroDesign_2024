#include <TimerOne.h>

void setup() {
//  Serial.begin(9600);
  Timer1.initialize(1);
  pinMode(3, OUTPUT);
  pinMode(9, OUTPUT);
  TCCR2A = 0b00000011;
  TCCR2B = 0b00000001;
  pinMode(A0, INPUT);
  Timer1.pwm(9, 512, 1);
}

void loop() {
  int r = analogRead(A0);
  int out = (r * 255.0 / 1024);
/*Serial.print(r);
  Serial.print(',');
  Serial.println(out);
  */
  analogWrite(3, out);
}
