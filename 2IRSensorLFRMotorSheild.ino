#include <AFMotor.h>

#define lefts A0
#define rights A1

AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ);

int forwardSpeed = 90;
int turnSpeed = 150;

void setup() {

  pinMode(lefts, INPUT);
  pinMode(rights, INPUT);

  Serial.begin(9600);
}

void loop() {

  int L = analogRead(lefts);
  int R = analogRead(rights);

  Serial.print("L = ");
  Serial.print(L);
  Serial.print("   R = ");
  Serial.println(R);

  // BLACK ≈ 1017
  // WHITE ≈ 38

  if (L > 500 && R > 500) {

    // both black -> stop
    motor1.run(RELEASE);
    motor2.run(RELEASE);
  }

  else if (L > 500 && R < 500) {

    // sharper right turn
    motor1.setSpeed(turnSpeed);
    motor2.setSpeed(turnSpeed);

    motor1.run(BACKWARD);
    motor2.run(FORWARD);
  }

  else if (L < 500 && R > 500) {

    // sharper left turn
    motor1.setSpeed(turnSpeed);
    motor2.setSpeed(turnSpeed);

    motor1.run(FORWARD);
    motor2.run(BACKWARD);
  }

  else {

    // move straight
    motor1.setSpeed(forwardSpeed);
    motor2.setSpeed(forwardSpeed);

    motor1.run(FORWARD);
    motor2.run(FORWARD);
  }
}
