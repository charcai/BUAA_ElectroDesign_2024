#include <TimerOne.h>

void setup() {
  // put your setup code here, to run once:
  Timer1.initialize(1);
  pinMode(7, INPUT);
  pinMode(5, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(13, OUTPUT);
  Timer1.pwm(9, 512, 1);
}

void loop() {
  if(digitalRead(7)) {
    tone(5, 523);
    digitalWrite(13, HIGH);
    delay(10);
  }
  else {
    digitalWrite(13, LOW);
    noTone(5);
  }
}
