const int mic = 2;
static String m[] =  {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..","-----",".----","..---","...--","....-",".....","-....","--...","---..","----.",".-.-.-","---...","--..--","-.-.-.","..--..","-.-.--"};
const int T = 80;
String a;
const int deb_delay = T * 0.9;
unsigned long p1, p2, p2_old, store_num = 0, signal_time = 0;
char store[100];

void debounce() {
  while(1) {
    while(digitalRead(mic) == HIGH) {
      long t1 = millis();
      while(digitalRead(mic) == HIGH) {
        long t2 = millis();
        long space = t2 - t1;
        if(space > deb_delay) {
          return;
        }
      }
    }
  }
}

void decode() {
  int found = 0;
  char c;
  for(int i = 0; i < 42; ++i) {
    if(m[i] == a) {
      found = 1;
      if(i <= 25) {
        c = 'a' + i;
      }
      else if(i <= 35) {
        c = '0' + i - 26;
      }
      else {
        switch(i) {
          case 36: c = '.'; break;
          case 37: c = ':'; break;
          case 38: c = ','; break;
          case 39: c = ';'; break;
          case 40: c = '?'; break;
          case 41: c = '!'; break;
        }
      }
      Serial.print(c);
      break;
    }
  }
  if(!found) {
    Serial.print("_");
  }
  a = "";
}

void setup() {
  Serial.begin(115200);
  pinMode(mic, INPUT);
}

void loop() {
  p1 = millis();
  int nosignal_time = p1-p2;
  if(nosignal_time > T * 2 && p2_old != p2){
    decode();
    p2_old = p2;
  }
  while(digitalRead(mic) == LOW){
    if(nosignal_time > T * 5) {
      if(nosignal_time < T * 15) {
        Serial.print(" ");
      }
      else {
        Serial.println("");
      }
    }
    debounce();
    p2 = millis();
    signal_time = p2 - deb_delay - p1;
    if(signal_time > T * 0.5) {
      if(signal_time <= 2.7 * T) {
        a = a + '.';
      }
      else {
        a = a + '-';
      }
    }
  }
}
