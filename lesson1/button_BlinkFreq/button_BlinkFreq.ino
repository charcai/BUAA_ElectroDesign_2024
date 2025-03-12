int button = 9,
    led = 13;
void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
}

void loop() {
  if(digitalRead(button) == HIGH) {
    while(1) {
      digitalWrite(led, HIGH);
      delay(300);
      digitalWrite(led, LOW);
      delay(300);
      if(digitalRead(button) == LOW) {
        break;
      }
    }
  }
  if(digitalRead(button) == LOW) {
    while(1) {
      digitalWrite(led, HIGH);
      delay(100);
      digitalWrite(led, LOW);
      delay(100);
      if(digitalRead(button) == HIGH) {
        break;
      }
    }
  }
}
