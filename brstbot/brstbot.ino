//  External
#include "EnumTypes.h"
#include <AFMotor.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_HMC5883_U.h>
#include <SPI.h>
//  Internal
#include "BRSTbot.h"
// #include "Globals.h"
#include "Op.h"
#include "PrintMode.h"
#include "Point.h"
#include "Utilities.h"
#include "IRSensor.h"
#include "Sonar.h"
#include <Servo.h>
//#include "magnetometer.h"
//#include "ChinaBee.h"
//#include "Bot.h"
//#include "Bee.h"

// #include "Globals.h"
// using namespace globals;

// Conventions questionable.
IRSensor FRONT_LEFT_IR(46);
IRSensor FRONT_RIGHT_IR(47);
IRSensor BACK_LEFT_IR(44);
IRSensor BACK_RIGHT_IR(45);

// int left_sonar_trigger_pin = 0;
// int left_sonar_echo_pin = 0;
Sonar FRONT_SONAR(40, 38);
Sonar LEFT_SONAR(30, 32);
Sonar RIGHT_SONAR(36, 34);


BRSTbot b;
PrintMode p;
Servo myServo;
int servoPos;

/****************************************************************************
*																			*
*	Function:  Setup           											    *
*																			*
****************************************************************************/


void setup() {

  Serial.begin(115200);
  b.setMotorBias(0.88);
  b.setSpeed(BOT_CRUISING_SPEED);
  b.startMotors();

  myServo.attach(9);
  myServo.write(0);

  // RotationOp* r = new RotationOp(90, ROTATE_LEFT, EVADE_RIGHT);
  // b.setOp(r);

  //b.startMotors();

  log("Hello World!");
  log("Hello 5");
}
  //update_loop_timer();

/****************************************************************************
*																			*
*	Function:  Loop           											    *
*																			*
****************************************************************************/

void loop() {

  parse_serial_command();
  p.print();

  b.op_check();

  // log(S("Curr time = " + millis()));
  //log("Hello");

    if (FRONT_LEFT_IR.detected() && FRONT_RIGHT_IR.detected()) {
        log("Detection condition.");
        b.evadeBorder(FRONT_SIDE);
    }
    else if (BACK_LEFT_IR.detected() && BACK_RIGHT_IR.detected())
        b.evadeBorder(BACK_SIDE);
    else if (FRONT_LEFT_IR.detected() && BACK_LEFT_IR.detected())
        b.evadeBorder(LEFT_SIDE);
    else if (FRONT_RIGHT_IR.detected() && BACK_RIGHT_IR.detected())
        b.evadeBorder(RIGHT_SIDE);
    else if (FRONT_LEFT_IR.detected())
        b.evadeBorder(FRONT_LEFT_CORNER);
    else if (FRONT_RIGHT_IR.detected())
        b.evadeBorder(FRONT_RIGHT_CORNER);
    else if (BACK_LEFT_IR.detected())
        b.evadeBorder(BACK_LEFT_CORNER);
    else if (BACK_RIGHT_IR.detected())
        b.evadeBorder(BACK_RIGHT_CORNER);

//  Sonar sensor




    //
    //
    // // SONAR CODE
    //
    // FRONT_SONAR.ping();
    // LEFT_SONAR.ping();
    // RIGHT_SONAR.ping();
    // if (b.currentOp == NULL || (b.currentOp != NULL && b.currentOp->label == CRUISE_FORWARD)) {
    //
    //   // Only initiate seek-follow behavior
    //
    //   int distances[3];
    //   distances[0] = 500;  // FRONT
    //   distances[1] = 500;  // LEFT
    //   distances[2] = 500;  // RIGHT
    //
    //
    //   if (FRONT_SONAR.objDetected()) { distances[0] = FRONT_SONAR.objDistance(); }
    //   if (LEFT_SONAR.objDetected()) { distances[1] = LEFT_SONAR.objDistance(); }
    //   if (RIGHT_SONAR.objDetected()) { distances[2] = RIGHT_SONAR.objDistance(); }
    //
    //   int minDistance = 500;
    //   int minIndex = -1;
    //
    //   for (int i = 0; i < 3; i++) {
    //     if (distances[i] < minDistance) {
    //       minDistance = distances[i];
    //       minIndex = i;
    //     }
    //   }
    //
    //   if (minIndex >= 0) {
    //     log("COMMENCING SONAR FOLLOWING...", minIndex);
    //     b.followSonarResult(minIndex); // SONAR RESULT;
    //   }
    //
    //
    //
    //
    // }
    // if (LEFT_SONAR.objDetected()) {
    //   log(S("LEFT Object detected!  ") + LEFT_SONAR.objDistance());
    // }
    // if (RIGHT_SONAR.objDetected()) {
    //   log(S("RIGHT Object detected!  ") + RIGHT_SONAR.objDistance());
    // }
    // // if (FRONT_LEFT_SONAR.objDistance())
    //
    //
    //




}
