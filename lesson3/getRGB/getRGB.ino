#include <Wire.h>
#include "Adafruit_TCS34725.h"

/* Example code for the Adafruit TCS34725 breakout library */

/* Connect SCL    to analog 5
   Connect SDA    to analog 4
   Connect VDD    to 3.3V DC
   Connect GROUND to common ground */

/* Initialise with default values (int time = 2.4ms, gain = 1x) */
// Adafruit_TCS34725 tcs = Adafruit_TCS34725();

/* Initialise with specific int time and gain values */
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_614MS, TCS34725_GAIN_1X);

uint16_t blr, blg, blb, whr, whg, whb, rr, gg, bb;
void setup(void) {
  Serial.begin(9600);

  if (tcs.begin()) {
    Serial.println("Found sensor");
  } else {
    Serial.println("No TCS34725 found ... check your connections");
    while (1);
  }
  pinMode(6, INPUT);
  Serial.println("Get Black");
  uint16_t c;
  while(1) {
    if(digitalRead(6) == HIGH) {
      Serial.println("Black!");
      tcs.getRawData(&blr, &blg, &blb, &c);
      break;
    }
  }
  delay(800);
  Serial.println("Get White");
  while(1) {
    if(digitalRead(6) == HIGH) {
      Serial.println("White!");
      tcs.getRawData(&whr, &whg, &whb, &c);
      break;
    }
  }
  rr = whr - blr;
  gg = whg - blg;
  bb = whb - blb;
  // Now we're ready to get readings!
}

void loop(void) {
  uint16_t r, g, b, c, colorTemp, lux;

  tcs.getRawData(&r, &g, &b, &c);
  // colorTemp = tcs.calculateColorTemperature(r, g, b);
  colorTemp = tcs.calculateColorTemperature_dn40(r, g, b, c);
  lux = tcs.calculateLux(r, g, b);

  Serial.print("Color Temp: "); Serial.print(colorTemp, DEC); Serial.print(" K - ");
  Serial.print("Lux: "); Serial.print(lux, DEC); Serial.print(" - ");
  Serial.print("R: "); Serial.print(int((r - blr) * 1.0 / rr * 255), DEC); Serial.print(" ");
  Serial.print("G: "); Serial.print(int((g - blg) * 1.0 / gg * 255), DEC); Serial.print(" ");
  Serial.print("B: "); Serial.print(int((b - blb) * 1.0 / bb * 255), DEC); Serial.print(" ");
//  Serial.print("C: "); Serial.print(c, DEC); Serial.print(" ");
  Serial.println(" ");
}
