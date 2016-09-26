#include <AFMotor.h>

AF_DCMotor motorLeft(1, MOTOR12_64KHZ);  // Initialize the left motor.
AF_DCMotor motorRight(2, MOTOR12_64KHZ);  // Initialize the left motor.

const float MOTOR_BIAS_LR = 0.757;

/*
 * Calibration Data
Speed  Bias
200, 0.757

 
 * 
 */



void motorsSetSpeed(int speed) {
  log("Motor speed set to: ", speed);
  motorLeft.setSpeed(speed * MOTOR_BIAS_LR);
  motorRight.setSpeed(speed);
}

String concat(String a, int b) {
  return a + b;
}

String concat(String a, float b) {
  return a + b;
}

void log(String a, int b) {
  Serial.println(concat(a, b));
}

void log(String a, float b) {
  Serial.println(concat(a, b));
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

  //String prefix = ;
  log("Motor bias set to: ", MOTOR_BIAS_LR);
  
  Serial.println("Hello World!");

  Serial.println("Motor test!");

  motorsSetSpeed(200);


  
  motorLeft.run(FORWARD);
  motorRight.run(FORWARD);

}

void loop() {
  // put your main code here, to run repeatedly:

  delay(2500);
  motorLeft.run(RELEASE);
  motorRight.run(RELEASE);
  
  x++;
  Serial.println(x);

}



/*
 * String concatenation example: 
 *   String hello = "Setting motor speed to: ";
 *   String world = hello + speed;
 *   Serial.println(world);
 * 
 */


