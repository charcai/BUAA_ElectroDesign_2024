void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(12, OUTPUT);
}

void loop() {
  int signal = analogRead(A0);
  Serial.println(signal);
  if(signal > 500) {
    digitalWrite(12, LOW);
  }
  else {
    digitalWrite(12, HIGH);
    }
  // put your main code here, to run repeatedly:

}
