const int INFRARE = 2;
const int LED = 13;
int state = 0;
int val = 0;
int old_val = 0;

void setup() {
  pinMode(INFRARE, INPUT); //赤外線センサ
  pinMode(LED, OUTPUT);
}

void loop() {
  val = digitalRead(INFRARE); //赤外が来ると0
  if((val == 0) && (old_val == 1)){ //今押されたかつさっきまで押されてなかった
    state = 1 - state;
  }
  old_val = val;
  if(state == 1){
    digitalWrite(LED,HIGH);
  }else{
    digitalWrite(LED,LOW);
  }
  delay(40);
}
