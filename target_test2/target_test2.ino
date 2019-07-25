#include <IRremoteInt.h> //for IR receiver
#include <IRremote.h>
#include<Servo.h> // for servo motor

Servo servo1;

const int INFRARE = 2;
const int LED = 13;
const int LED2 = 12;
const int LED3 = 11;
const int LED4 = 10;
const int LED5 = 9;

int val = 0;
int old_val = 0;
int mode = 0; // mode 0:手動モード 1:一定間隔モード 2:自動復帰モード 3:ゲームモード
int reset = 0;

//button
long button_power = 0xFFA25D; //reset
long button_0 = 0xFF6897;
long button_1 = 0xFF30CF;
long button_2 = 0xFF18E7;
long button_3 = 0xFF7A85;

void setup() {
  pinMode(INFRARE, INPUT); //赤外線センサ
  pinMode(LED, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  
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
