void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  Serial.begin(9600);
}

int pin2[] = {0,0,0,0,1,1,1,1},
    pin3[] = {0,0,1,1,0,0,1,1},
    pin4[] = {0,1,0,1,0,1,0,1};

void loop() {
  if(Serial.available() > 0) {
    int x = Serial.read();
    x -= 'A';
    digitalWrite(2, pin2[x]);
    digitalWrite(3, pin3[x]);
    digitalWrite(4, pin4[x]);
  }
}
