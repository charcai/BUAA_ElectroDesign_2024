#include <TimerOne.h>

const int Trig = 13;
const int echo = 12;
const int led = 11;
double distance_cm;

const int sega = 2,
          segb = 3,
          segc = 4,
          segd = 5,
          sege = 6,
          segf = 7,
          segg = 8,
          segdp = 9;


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
  pinMode(Trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(led, OUTPUT);
  for(int i = 2; i <= 9; ++i) {
    pinMode(i, OUTPUT);
  }
  Timer1.initialize(50000);
 // Timer1.attachInterrupt(timerIsr);
}

double read() {
  double dist;
  digitalWrite(Trig, LOW);
  delay(10);
  digitalWrite(Trig, HIGH);
  delay(10);
  digitalWrite(Trig, LOW);

  dist = int(pulseIn(echo, HIGH) / 58.8 * 100) / 100.0;
  return dist;
}

int cmp(int a, int b) {
  return a < b;
}

void loop() {
//  double num[8] = { read(), read(), read(), read(), read(), read(), read() };
//  qsort(num, 7, sizeof(double), cmp);
double tm[6], sum = 0;
for(int i = 1; i <= 5; ++i) {
  tm[i] = read();
  sum += tm[i];
}
  double distance_cm = (sum) / 5.0;
  for(int i = 1; i <= 5; ++i) {
    Serial.print(tm[i]);
    Serial.print(',');
    Serial.println(distance_cm);
  }
  int dis = int((distance_cm + 0.05) * 10);
  int a = dis % 10,
      b = dis / 10 % 10,
      c = dis / 100 % 10,
      d = dis / 1000 % 10;

/*  Serial.print(d);
  Serial.print(c);
  Serial.print(b);
  Serial.print('.');
  Serial.println(a);*/
  if(distance_cm <= 10.0) {
    digitalWrite(led, HIGH);
  }
  else {
    digitalWrite(led, LOW);
  }
  for(int pin = 2; pin <= 9; ++pin) {
    digitalWrite(pin, n[0][9 - pin]);
  }
  delay(400);
  for(int pin = 2; pin <= 9; ++pin) {
    digitalWrite(pin, n[d][9 - pin]);
  }
  delay(400);
  for(int pin = 2; pin <= 9; ++pin) {
    digitalWrite(pin, n[c][9 - pin]);
  }
  delay(400);
  for(int pin = 2; pin <= 9; ++pin) {
    digitalWrite(pin, n[b][9 - pin]);
  }
  delay(400);
  for(int pin = 2; pin <= 9; ++pin) {
    digitalWrite(pin, n[10][9 - pin]);
  }
  delay(400);
  for(int pin = 2; pin <= 9; ++pin) {
    digitalWrite(pin, n[a][9 - pin]);
  }
  delay(500);
}