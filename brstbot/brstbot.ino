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
// #include "Sonar.h"
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

// int triggerPin = 0;
// int echoPin = 0;
// Sonar FRONT_LEFT_SONAR(triggerPin, echoPin);
// Sonar FRONT_RIGHT_SONAR(triggerPin, echoPin);

BRSTbot b;
PrintMode p;

/****************************************************************************
*																			*
*	Function:  Setup           											    *
*																			*
****************************************************************************/

void setup() {

  Serial.begin(115200);
  b.setMotorBias(0.88);
  b.setSpeed(110);

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

    // long distance1 = FRONT_LEFT_SONAR.ping();       //  do not use raw, use objDistance
    // long distance1 = FRONT_RIGHT_SONAR.ping();

    // if (FRONT_LEFT_SONAR.objDetected())
    // if (FRONT_LEFT_SONAR.objDistance())


}
