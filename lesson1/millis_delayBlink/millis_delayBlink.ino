unsigned long prev;
void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  prev = millis();
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long curr = millis();
  if(curr - prev > 500) {
    digitalWrite(13, HIGH);
    while(1) {
      if(millis() - curr > 500) {
        prev = millis();
        break;
      }
    }
  }
  digitalWrite(13, LOW);
}
