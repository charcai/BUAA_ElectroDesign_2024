#include"TimerOne.h"
#define speakerPin 3 //PWM输出引脚
#define audioPin A0 //模拟读取A0
int val;
void setup() {
  Serial.begin(9600); 
  // TimerOne库生成载波
  Timer1.initialize(1);
  Timer1.pwm(9,512,1);
  /*
  // 计时器1 CTC模式生成载波
  uint32_t fTransmit = 1000; //KHz
  pinMode(9, OUTPUT); //载波输出引脚 pin9
  TCCR1A = 0b01000000;  
  TCCR1B = 0b00001001; 
  OCR1A = F_CPU / (2000 * fTransmit) - 1;
  char strbuf[255];
  sprintf(strbuf, " 设置载波频率：%d kHz", (F_CPU / (2 * (1 + OCR1A)) / 1000));
  Serial.println(strbuf);
    */
  //PWM频率62.5KHz，PWM周期16µs
  //Fast PWM, Mode3, Top=255
  TCCR2A = 0b00000011; 
  TCCR2B = 0b00000001; 
}
void loop() { 
  val = analogRead(audioPin);
  val = map(val, 0, 1023, 0, 255);  // PWN占空比范围0~255
  analogWrite(speakerPin, val); 
}