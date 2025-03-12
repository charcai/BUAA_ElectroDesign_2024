String str = "";
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  while(Serial.available() > 0) {
    char ch;
    ch = Serial.read();
    if(ch == '\n') {
      break;
    }
    str = str + ch;
  }
  Serial.print(str);
  if(str != "") {
    Serial.print("\n");
  }
  str = "";
  // put your main code here, to run repeatedly:
  delay(200);
}
