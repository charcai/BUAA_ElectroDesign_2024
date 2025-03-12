char x = 0;
void setup() {
  Serial.begin(9600);
}
  void loop() {
  if(Serial.available() > 0) {
    x = Serial.read();
    Serial.print("I have received:");
    Serial.println(x);
  }
  delay(500);
}