int i = 0;
int j = 0;
int k = 0;
int T1 = 2;
int T2 = 4;

void setup() {
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
}
void loop() {
  for (i = 0; i <= 510; i += 1) {
    if(i < 255)
      analogWrite(3, i);
    else
      analogWrite(3, 510-i);
    j = T1*i/255;
    if(j%2 == 0)
      analogWrite(5, T1*i%255);
    else
      analogWrite(5, 255-T1*i%255);
    k = T2*i/255;
    if (k % 2 == 0)
      analogWrite(6, T2*i%255);
    else
      analogWrite(6, 255-T2*i%255);
    delay(10);
  }
  delay(10); // Delay a little bit to improve simulation performance
}