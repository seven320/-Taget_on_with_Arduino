// 製作者　電電 Part time Soldiers 隊員

#include <IRremoteInt.h> //for IR receiver
#include <IRremote.h>
#include<Servo.h> // for servo motor

Servo servo1;

const int RECV_PIN = 7;
const int LED0 = 13;
const int LED1 = 12;
const int LED2 = 11;
const int LED3 = 10;

const int SERVO = 3;
const int SWITCH = 4;


// mode 0:手動モード 
// mode 1:一定間隔モード 
// mode 2:自動復帰モード ハードを未実装
// mode 3:ゲームモード　未実装
int mode = -1; 
bool power = false;

//ir
//long ir_power = 0xFFA25D; //reset
//long ir_0 = 0xFF6897;
//long ir_1 = 0xFF30CF;
//long ir_2 = 0xFF18E7;
//long ir_3 = 0xFF7A85;

//tv remote controller
long ir_power = 0x81C750AF;
long ir_0 = 0x81C7807F;
long ir_1 = 0x81C740BF;
long ir_2 = 0x81C7C03F;
long ir_3 = 0x81C720DF;
long ir_con = 0xFFFFFFFF;

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn(); //Start the receiver
  pinMode(RECV_PIN, INPUT_PULLUP); //赤外線センサ　pullupにより抵抗いらない

  pinMode(LED0, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  
  servo1.attach(SERVO);
}

void target_on(){
  Serial.println("target on!");
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
//  スイッチを押したらターゲットが上がるモード
  bool cont = true;
  while(cont){
    if(irrecv.decode(&results)){
      Serial.println(results.value, HEX);
      long ir_signal = results.value;
      if(ir_signal == ir_0 | ir_signal == ir_1 | ir_signal == ir_power){
        if(ir_signal == ir_0){
          target_on();
        }else{
          Serial.println("change mode");
          cont = false;
        }
      }
      irrecv.resume();
    }
    delay(40);
  }
}

void mode1(){
//  時間で自動的に動作
  bool cont = true;
  unsigned long prev = millis();
  while(cont){
    if(irrecv.decode(&results)){
      Serial.println(results.value, HEX);
      long ir_signal = results.value;
      if(ir_signal == ir_0 | ir_signal == ir_1 | ir_signal == ir_power){
        if(ir_signal == ir_1){
          Serial.println("mode2");
        }else{
          cont = false;
          Serial.println("change mode");
        }
      }
      irrecv.resume();
    }
    if(cont && millis()-prev > 5000){
      target_on();
      prev = millis();
    }
    delay(40);
  }
}

//void mode2(){
//  bool cont = true;
//  while(cont){
////    スイッチが押されると上がる
//    if(irrecv.decode(&results)){
//      if(results.value != ir_2){
//        cont = false;
//      }else{
//        irrecv.resume();
//      }
//    }
//    if(digitalRead(SWITCH) == false){ 
////      常にスイッチはHIGHで，接点を持つと電圧が０になる
//      target_on();
//    }
//    delay(40);
//  }
//}

void loop(){
  mode = -1;
  if(irrecv.decode(&results)){
    Serial.println(results.value, HEX);
    long ir_signal = results.value;
    if(ir_signal == ir_power){
      if(power == false){ // power on 
        LED_all(HIGH);
        power = true;
      }else{
        LED_all(LOW);
        power = false;
      }
    }
    if(power & (ir_signal == ir_0 | ir_signal == ir_1)){
      LED_all(LOW);
      if(ir_signal == ir_0){
        digitalWrite(LED0, HIGH);
        mode = 0;
      }else if(ir_signal == ir_1){
        digitalWrite(LED1, HIGH);
        mode = 1;
      }
//      }else if(results.value == ir_2){
//        digitalWrite(LED2, HIGH);
//        mode = 2;
//      }
    }
    irrecv.resume();
  }
  if(power){
    if(mode == 0){
      mode0();
    }else if(mode == 1){
      mode1();
    }
//    }else if(mode == 2){
//      mode2();
//    }
  }
  check_motor();
  delay(40);
}
