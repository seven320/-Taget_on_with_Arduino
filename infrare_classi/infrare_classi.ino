#include <IRremoteInt.h>
#include <IRremote.h>

#include<Servo.h>

const int RECV_PIN = 2;
const int LED = 13;
const int LED2 = 12;
const int LED3 = 11;

//SWHICH
long button_power = 0xFFA25D;
long button_0 = 0xFF6897;
long button_1 = 0xFF30CF;

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup(){
  Serial.begin(9600);
  irrecv.enableIRIn(); //Start the receiver
  pinMode(LED, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);  
}

void loop(){
  if(irrecv.decode(&results)){
    Serial.println(results.value, HEX);
    if(results.value == button_power){
      digitalWrite(LED, HIGH);
    }else{
      digitalWrite(LED,LOW);
    }
    if(results.value == button_0){
      digitalWrite(LED2, HIGH);
    }else{
      digitalWrite(LED2,LOW);
    }
    if(results.value == button_1){
      digitalWrite(LED3, HIGH);
    }else{
      digitalWrite(LED3,LOW);
    }
    irrecv.resume();
  }

  delay(100);
}








//
//Servo servo1;
//
//const int INFRARE = 2;
//const int LED = 13;
//int val = 0;
//int old_val = 0;
//
//void setup() {
//  pinMode(INFRARE, INPUT); //赤外線センサ
//  pinMode(LED, OUTPUT); //LED
//  servo1.attach(8);
//}
//
//void loop() {
//  val = digitalRead(INFRARE); //赤外が来ると0
//  if(servo1.read() < 170){ // position check 
//    servo1.write(180);
//    delay(1000);
//    digitalWrite(INFRARE, LOW);
//  }
//  
//  if((val == 0) && (old_val == 1)){ //今押されたかつさっきまで押されてなかった
//    digitalWrite(LED,HIGH);
//    servo1.write(20);
//    delay(1000);
//    servo1.write(180);
//    delay(1000);
//    digitalWrite(INFRARE, LOW);
//  }else{
//    digitalWrite(LED,LOW);
//  }
//  old_val = val;
//  delay(40);
//}
