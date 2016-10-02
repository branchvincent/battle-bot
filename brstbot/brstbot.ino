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

  parse_serial_command(b, p);
  p.print();
  b.op_check();

  //log("Hello");
  if (FRONT_LEFT_IR.detected() && FRONT_RIGHT_IR.detected()) {
    log("Detection condition.");
    b.evadeBorder(FRONT_SIDE);
  }
}
