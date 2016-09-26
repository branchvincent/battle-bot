#include <AFMotor.h>

AF_DCMotor motorLeft(1, MOTOR12_64KHZ);  // Initialize the left motor.
AF_DCMotor motorRight(2, MOTOR12_64KHZ);  // Initialize the left motor.


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

  motorLeft.setSpeed(200);
  motorRight.setSpeed(200);
  
  motorLeft.run(FORWARD);
  motorRight.run(FORWARD);

}

void loop() {
  // put your main code here, to run repeatedly:

  delay(3000);
  motorLeft.run(RELEASE);
  motorRight.run(RELEASE);
  
  x++;
  Serial.println(x);

}


