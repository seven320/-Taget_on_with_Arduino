#include<Servo.h>

Servo servo1;
const int LED = 13;
const int BUTTON = 7;

int val = 0;

void setup() {
  // put your setup code here, to run once:
  servo1.attach(8);
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

void loop() {
  val = digitalRead(BUTTON);
  servo1.write(180);
  if (val == 1){
    digitalWrite(LED, HIGH);
    servo1.write(60);
    delay(1000);
  }else{
    digitalWrite(LED, LOW);
    delay(1000);
  }
}
