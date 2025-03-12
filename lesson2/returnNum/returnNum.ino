void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  int x;
  while(Serial.available() > 0) {
    x = Serial.parseInt();
    Serial.print(x);
  }
  // put your main code here, to run repeatedly:
}
