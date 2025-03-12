#include "DHT.h"
#define DHTPIN 12
#define DHTTYPE DHT11
int tmp = 30;
DHT dht(DHTPIN, DHTTYPE);
void setup() {
  Serial.begin(9600);
  Serial.println("DHT Start!");
  pinMode(2, OUTPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  dht.begin();
}

void loop() {
  int changed = 0;
  if(digitalRead(6) == HIGH) {
    tmp--;
    changed = 1;
  }
  else if(digitalRead(7) == HIGH) {
    tmp++;
    changed = 1;
  }
  if(tmp > dht.readTemperature()) {
    digitalWrite(2, HIGH);
  }
  else {
    digitalWrite(2, LOW);
  }
  if(changed) {
    Serial.println(tmp);
    delay(250);
  }
}
