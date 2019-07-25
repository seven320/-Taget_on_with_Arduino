#include <IRremoteInt.h> //for IR receiver
#include <IRremote.h>
#include<Servo.h> // for servo motor

Servo servo1;

const int RECV_PIN = 2;
const int LED0 = 13;
const int LED1 = 12;
const int LED2 = 11;
const int LED3 = 10;
const int SERVO = 8;
const int TARGET0 = 7;

int mode = -1; // mode 0:手動モード 1:一定間隔モード 2:自動復帰モード 3:ゲームモード
bool power = false;

//button
long button_power = 0xFFA25D; //reset
long button_0 = 0xFF6897;
long button_1 = 0xFF30CF;
long button_2 = 0xFF18E7;
long button_3 = 0xFF7A85;



IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn(); //Start the receiver
  pinMode(RECV_PIN, INPUT); //赤外線センサ
  pinMode(TARGET0, INPUT);
  
  pinMode(LED0, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  

  servo1.attach(SERVO);
}

void target_on(){
  servo1.write(20);
  delay(1000);
  servo1.write(180);
  delay(1000);
  digitalWrite(SERVO,LOW); // stop servo motor 
}

void check_motor(){
  if(servo1.read() < 170){ // position check 
    servo1.write(180);
    delay(1000);
    digitalWrite(SERVO,LOW); // stop servo motor 
  }
}

void LED_all(bool voltage){
  digitalWrite(LED0, voltage);
  digitalWrite(LED1, voltage);
  digitalWrite(LED2, voltage);
  digitalWrite(LED3, voltage);
}

void mode0(){ // 手動
  bool cont = true;
  int old_val = 1;
  while(cont){
    if(irrecv.decode(&results)){
      if(results.value == button_0){
        if(old_val == 1){
          target_on();
          old_val = 0;
          irrecv.resume();
        }
      }else{
        cont = false;
      }
    }else{
      old_val = 1;
    }
  check_motor();
  delay(20);
  }
}

void mode1(){
  bool cont = true;
  unsigned long prev = millis();
  while(cont){
    if(irrecv.decode(&results)){
      if(results.value != button_1){
        cont = false;
      }else{ // button_1 が押されたときは赤外をリセットしないと止まる
        irrecv.resume();
      }
    }
    if(millis()-prev > 3000){
      target_on();
      prev = millis();
    }
    delay(40);
  }
}

void mode2(){
  bool cont = true;
  while(cont){
    if(irrecv.decode(&results)){
      if(results.value != button_2){
        cont = false;
      }else{
        irrecv.resume();
      }
    }
    if(digitalRead(TARGET0)){
      delay(1000);
      target_on();
    }
    delay(40);
  }
}


void loop(){
  mode = -1;
  if(irrecv.decode(&results)){
    Serial.println(results.value, HEX);
    if(results.value == button_power){
      if(power == false){ // power on 
        LED_all(HIGH);
        power = true;
      }else{
        LED_all(LOW);
        power = false;
      }
    }
    if(power & results.value == button_0 | results.value == button_1 | results.value == button_2 | results.value == button_3){
      LED_all(LOW);
      if(results.value == button_0){
        digitalWrite(LED0, HIGH);
        mode = 0;
      }else if(results.value == button_1){
        digitalWrite(LED1, HIGH);
        mode = 1;
      }else if(results.value == button_2){
        digitalWrite(LED2, HIGH);
        mode = 2;
      }else if(results.value == button_3){
        digitalWrite(LED3, HIGH);
        mode = 3;
      }
    }
    irrecv.resume();
  }
  if(power){
    if(mode == 0){
      mode0();
    }else if(mode == 1){
      mode1();
    }else if(mode == 2){
      mode2();
    }
  }
  check_motor();
  delay(40);
}
