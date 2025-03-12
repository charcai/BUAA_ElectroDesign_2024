int x;
void setup() {
  // put your setup code here, to run once:
  x = 0;
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  x = 0;
  //put your main code here, to run repeatedly:
  if(Serial.available() > 0) {
    x = Serial.read();
    x -= '0';
    for(int i = 1; i <= x; ++i) {
      digitalWrite(13, HIGH);
      delay(500);
      digitalWrite(13, LOW);
      delay(500);
    }
  }
}