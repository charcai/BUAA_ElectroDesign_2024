const int n[11][8] = {
  { 0,1,1,1,1,0,1,1 },
  { 0,1,0,0,1,0,0,0 },
  { 0,0,1,1,1,1,0,1 },
  { 0,1,1,0,1,1,0,1 },
  { 0,1,0,0,1,1,1,0 },
  { 0,1,1,0,0,1,1,1 },
  { 0,1,1,1,0,1,1,1 },
  { 0,1,0,0,1,0,0,1 },
  { 0,1,1,1,1,1,1,1 },
  { 0,1,1,0,1,1,1,1 },
  { 1,0,0,0,0,0,0,0 }
};

void setup() {
  Serial.begin(115200);
   for(int i = 2; i <= 9; ++i) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  if(Serial.available()) {
    int a = Serial.read() - '0';
  for(int pin = 2; pin <= 9; ++pin) {
    digitalWrite(pin, n[a][9 - pin]);
  }
  }
}
