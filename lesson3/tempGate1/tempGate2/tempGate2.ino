#include "DHT.h"
#define DHTPIN 12
#define DHTTYPE DHT11
int tmpH = 30;
int tmpL = 20;
DHT dht(DHTPIN, DHTTYPE);

void setHigh() {
  Serial.println("Set HighLimit:");
  Serial.println(tmpH);
  while(digitalRead(10) == LOW) {
    int changed = 0;
    if(digitalRead(6)) {
      tmpH++;
      changed = 1;
    }
    if(digitalRead(7)) {
      tmpH--;
      changed = 1;
    }
    if(changed) {
      Serial.println(tmpH);
      delay(250);
    }
  }
  Serial.println("HighLimit Set!");
}
void setLow() {
  Serial.println("Set LowLimit:");
  Serial.println(tmpL);
  while(digitalRead(10) == LOW) {
    int changed = 0;
    if(digitalRead(6)) {
      tmpL++;
      changed = 1;
    }
    if(digitalRead(7)) {
      tmpL--;
      changed = 1;
    }
    if(changed) {
      Serial.println(tmpL);
      delay(250);
    }
  }
  Serial.println("LowLimit Set!");
}
void setup() {
  Serial.begin(9600);
  Serial.println("DHT Start!");
  pinMode(2, OUTPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(10, INPUT);
  dht.begin();
  setHigh();
  delay(1000);
  setLow();
}

void loop() {
  int tmp = dht.readTemperature();
  if(tmp < tmpL) {
    digitalWrite(2, HIGH);
  }
  else if(tmp > tmpH) {
    digitalWrite(2, LOW);
  }
}
