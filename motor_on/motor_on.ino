#include <Stepper.h>

#define MOTOR_1   (4)   // blue
#define MOTOR_2   (5)   // pink
#define MOTOR_3   (6)   // yellow
#define MOTOR_4   (7)   // orange

#define SW  (3)

#define MOTOR_STEPS (2048)

// ライブラリが想定している配線が異なるので2番、3番を入れ替える
Stepper myStepper(MOTOR_STEPS, MOTOR_1, MOTOR_3, MOTOR_2, MOTOR_4);

void setup() {
  pinMode(SW, INPUT);
  myStepper.setSpeed(10);
}

void loop() {
  // スイッチを押して離すとモーターを45°回転させる
  while (!digitalRead(SW)) { delay(50); }
  while (digitalRead(SW))  { delay(50); }
  myStepper.step(256);

  // 静止時の負荷が無く勿体無いので電流を止める
  stopMotor();
}

// モーターへの電流を止める
void stopMotor() {
  digitalWrite(MOTOR_1, LOW);
  digitalWrite(MOTOR_2, LOW);
  digitalWrite(MOTOR_3, LOW);
  digitalWrite(MOTOR_4, LOW);
}
