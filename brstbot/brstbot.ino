#include <AFMotor.h>

AF_DCMotor motorLeft(1, MOTOR12_64KHZ);  // Initialize the left motor.
AF_DCMotor motorRight(2, MOTOR12_64KHZ);  // Initialize the left motor.

const float MOTOR_BIAS_LR = 0.5;


void motorsSetSpeed(int speed) {
  String hello = "Setting motor speed to: ";
  String world = hello + speed;
  Serial.println(world);
}

// Left
// Black -> Top
// Red -> Bottom

// Right
// Black -> Top
// Red -> Bottom

int x = 0;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  Serial.println("Hello World!");

  Serial.println("Motor test!");

  motorsSetSpeed(100);

  //motorLeft.setSpeed(200);
  //motorRight.setSpeed(200);
  
  //motorLeft.run(FORWARD);
  //motorRight.run(FORWARD);

}

void loop() {
  // put your main code here, to run repeatedly:

  delay(3000);
  //motorLeft.run(RELEASE);
  //motorRight.run(RELEASE);
  
  x++;
  Serial.println(x);

}


