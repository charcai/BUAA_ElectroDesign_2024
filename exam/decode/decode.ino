#include <stdio.h>
#include <string.h>
#define inPin 2
String code = "";
unsigned long signal_time, p2, p1, p2_old;
unsigned long none_time, this_none, last_none;
const int duration = 100;
const int debounce_delay = duration * 0.9;
const int char_space = duration * 2;
const int word_space = duration * 5;
const int sentence_space = duration * 15;
const int min_dot_dash_threshold = duration * 0.2;
const int dot_dash_threshold = duration * 2;
char store[100];
char copy[100];
int store_num = 0;
int flag;

void decode() {
  static String morse[] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....",
                            "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...",
                            "-", "..-", "...-", ".--", "-..-", "-.--", "--..",
                            "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.",
                            ".-.-.-", "---...", "--..--", "-.-.-.", "..--..", "-.-.--" };  // A-Z,0-9,标点：.:,;?!
  int i = 0;
  while(i < 42) {
    if(morse[i] == code) {
      if(i <= 25) {
        Serial.print(char('a' + i));
      }
      else if(i <= 35) {
        i = i - 26;
        Serial.print(char('0' + i));
      }
      else {
        switch(i) {
          case 36:
            Serial.print('.');  break;
          case 37:
            Serial.print(':');  break;
          case 38:
            Serial.print(',');  break;
          case 39:
            Serial.print(';');  break;
          case 40:
            Serial.print('?');  break;
          case 41:
            Serial.print('!');  break;
        }
      }
      break;
    }
    i++;
  }
  if(i == 42) {
    Serial.print('_');
  }
  code = "";
}

char char_decide() {
  if (signal_time < (dot_dash_threshold)) {
    Serial.print('.');
    return '.';
  } else if (signal_time > (dot_dash_threshold)) {
    Serial.print('-');
    return '-';
  }
}

void debounce() {
  int l1 = 0, l2 = 0, space = 0;
  while(1) {
    while(digitalRead(inPin) == HIGH) {
      l1 = millis();
      while(digitalRead(inPin) == HIGH) {
        l2 = millis();
        space = l2 - l1;
        if(space > debounce_delay) {
          return;
        }
      }
    }
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(inPin, INPUT);
}


void loop() {
  p1 = millis();
  unsigned long nosignal_time = p1 - p2;
  if(nosignal_time > char_space && p2_old != p2) {
    decode();
  }
  p2_old = p2;
  while(digitalRead(inPin) == LOW) {
    if(flag && nosignal_time > word_space) {
      if(nosignal_time < sentence_space) {
        Serial.print(' ');
      }
      else {
        store[store_num] = char(' ');
        store_num++;
        Serial.println("");
      }
    }
    flag = 1;
    debounce();
    p2 = millis();
    signal_time = p2 - debounce_delay - p1;
    if(signal_time > min_dot_dash_threshold) {
      code = code + char_decide();
  }
  }
}
