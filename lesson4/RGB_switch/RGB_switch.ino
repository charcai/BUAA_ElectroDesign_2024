const int led_red = 9, led_green = 10, led_blue = 11;
void setup() {
  pinMode(led_red, OUTPUT);
  pinMode(led_green, OUTPUT);
  pinMode(led_blue, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int signal = analogRead(A0);
  int temp = signal / 1024.0 * 9700;
  Serial.println(temp);
  int RED, GREEN, BLUE;
  if(temp <= 6600) {
    RED = 255;
    GREEN = (int)(min(255, max(0, 99.5 * log(temp / 100.0) - 161.1)));
  }
  else {
    RED = (int)(min(255, 329.7 * pow((temp / 100.0) - 60.0, -0.13)));
    GREEN = (int)(min(255, 288.1 * pow(((temp / 100.0) - 60.0), -0.08)));
  }
  if(temp <= 1900) {
    BLUE = 0;
  }
  else if(temp < 6600) {
    BLUE = (int)(max(0, 138.5 * log((temp / 100.0) - 10.0) - 305.0));
  }
  else {
    BLUE = 255;
  }
  analogWrite(led_red, RED);
  analogWrite(led_green, GREEN);
  analogWrite(led_blue, BLUE);
}
