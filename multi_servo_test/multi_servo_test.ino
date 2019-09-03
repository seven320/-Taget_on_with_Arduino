#include<Servo.h> // for servo motor

Servo servo1;
Servo servo2;
Servo servo3;



void setup() {
  // put your setup code here, to run once:
  servo2.attach(6);
  servo3.attach(8);
  servo1.attach(9);



}
void loop() {
  for (int i = 0; i < 180; i++) {
    servo1.write(i);             
    servo2.write(i);    
    servo3.write(i);       
    delay(10);                     
  }
  for (int i = 180; i > 0; i--) {
    servo1.write(i);               
    servo2.write(i);    
    servo3.write(i);        
    delay(10);                  
  }
  delay(10000);
}
