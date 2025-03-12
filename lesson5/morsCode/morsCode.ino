#include <TimerOne.h>

void setup() {
  Serial.begin(9600);
  Timer1.initialize(1);
  pinMode(7, INPUT);
  pinMode(5, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(13, OUTPUT);
  Timer1.pwm(9, 512, 1);
}

  int duration = 200;

void dash() {
  tone(5, 523);
  digitalWrite(13, HIGH);
  delay(3 * duration);
  noTone(5);
   digitalWrite(13, LOW);
  delay(duration);
}

void dot() {
  tone(5, 523);
  digitalWrite(13, HIGH);
  delay(duration);
  noTone(5);
  digitalWrite(13, LOW);
  delay(duration);
}

void loop() {
  if(Serial.available()) {
  char read_now = Serial.read();
  		switch (read_now) {
          case 'A':
            Serial.println(".-");
            dot(); dash();
            delay(2*duration);
            break;
          case 'B':
            Serial.println("-...");
            dash();dot(); dot(); dot();   
            delay(2*duration);    
            break;
          case 'C':
            Serial.println("-.-.");
            dash();dot();dash();dot();
            delay(2*duration);
            break;
          case 'D':
            Serial.println("-..");
            dash();dot();dot();
            delay(2*duration);
            break;
          case 'E':
            Serial.println(".");
            dot();
            delay(2*duration);
            break;
          case 'F':
            Serial.println("..-.");
            dot();dot();dash();dot();
            delay(2*duration);
            break;
          case 'G':
            Serial.println("--."); 
            dash();dash();dot();
            delay(2*duration);
            break; 
          case 'H':
            Serial.println("....");
            dot();dot();dot();dot();
            delay(2*duration);
            break;
          case 'I':
            Serial.println("..");
            dot();dot();
            delay(2*duration);
            break;
          case 'J':
            Serial.println(".---");
            dot();dash();dash();dash();
            delay(2*duration);
            break;
          case 'K':
            Serial.println("-.-");
            dash();dot();dash();
            delay(2*duration);
            break;
          case 'L':
            Serial.println(".-..");
            dot();dash();dot();dot();
            delay(2*duration);            
            break;
          case 'M':
            Serial.println("--");
            dash();dash();
            delay(2*duration);            
            break;
          case 'N':
            Serial.println("-.");
            dash();dot();
            delay(2*duration);            
            break;
          case 'O':
            Serial.println("---");
            dash();dash();dash();
            delay(2*duration);            
            break;
          case 'P':
            Serial.println(".--.");
            dot();dash();dash();dot();
            delay(2*duration);            
            break;
          case 'Q':
            Serial.println("--.-");
            dash();dash();dot();dash();
            delay(2*duration);            
            break;
          case 'R':
            Serial.println(".-.");
            dot();dash();dot();
            delay(2*duration);            
            break;
          case 'S':
            Serial.println("...");
            dot();dot();dot();
            delay(2*duration);            
            break;
          case 'T':
            Serial.println("-");
            dash();
            delay(2*duration);            
            break;
          case 'U':
            Serial.println("..-");
            dot();dot();dash();
            delay(2*duration);            
            break;            
          case 'V':
            Serial.println("...-");
            dot();dot();dot();dash();
            delay(2*duration);            
            break;
          case 'W':
            Serial.println(".--");
            dot();dash();dash();
            delay(2*duration);            
            break;
          case 'X':
            Serial.println("-..-");
            dash();dot();dot();dash();
            delay(2*duration);            
            break;
          case 'Y':
            Serial.println("-.--");
            dash();dot();dash();dash();
            delay(2*duration);            
            break;
          case 'Z':
            Serial.println("--..");
            dash();dash();dot();dot();
            delay(2*duration);            
            break;
          case '0':
            Serial.println("-----");
            dash();dash();dash();dash();dash();
            delay(2*duration);            
            break;
          case '1':
            Serial.println(".----");
            dot();dash();dash();dash();dash();
            delay(2*duration);            
            break;
          case '2':
            Serial.println("..---");
            dot();dot();dash();dash();dash();
            delay(2*duration);            
            break;
          case '3':
            Serial.println("...--");
            dot();dot();dot();dash();dash();
            delay(2*duration);            
            break;
          case '4':
            Serial.println("....-");
            dot();dot();dot();dot();dash();
            delay(2*duration);            
            break;
          case '5':
            Serial.println(".....");
            dot();dot();dot();dot();dot();
            delay(2*duration);            
            break;
          case '6':
            Serial.println("-....");
            dash();dot();dot();dot();dot();
            delay(2*duration);            
            break;
          case '7':
            Serial.println("--...");
            dash();dash();dot();dot();dot();
            delay(2*duration);            
            break;
          case '8':
            Serial.println("---..");
            dash();dash();dash();dot();dot();
            delay(2*duration);            
            break;          
          case '9':
            Serial.println("----.");
            dash();dash();dash();dash();dot();
            delay(2*duration);            
            break;
          case ' ':
            delay(6*duration);            
            break;
          default:
            Serial.print(read_now);
            Serial.println(" is not a normal char!");           
        }
  }
}
