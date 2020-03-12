#include<Servo.h>

Servo servo1;

const int INFRARE = 2;
const int LED = 13;
int val = 0;
int old_val = 0;

void setup() {
  pinMode(INFRARE, INPUT); //赤外線センサ
  pinMode(LED, OUTPUT); //LED
  servo1.attach(8);
  
}

void loop() {
  val = digitalRead(INFRARE); //赤外が来ると0
  if(servo1.read() < 170){ // position check 
    servo1.write(180);
    delay(1000);
    digitalWrite(INFRARE, LOW);
  }
  
  
  if((val == 0) && (old_val == 1)){ //今押されたかつさっきまで押されてなかった
    digitalWrite(LED,HIGH);
    servo1.write(20);
    delay(1000);
    servo1.write(180);
    digitalWrite(INFRARE, LOW);
  }else{
    digitalWrite(LED,LOW);
  }
  old_val = val;
  delay(40);
}
