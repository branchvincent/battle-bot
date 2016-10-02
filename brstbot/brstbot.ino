//  External
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
#include "EnumTypes.h"
//#include "magnetometer.h"
//#include "ChinaBee.h"
//#include "Bot.h"
//#include "Bee.h"

// #include "Globals.h"
// using namespace globals;

const int FRONT_LEFT_IR = 46;
const int FRONT_RIGHT_IR = 47;
const int BACK_LEFT_IR = 44;
const int BACK_RIGHT_IR = 45;

BRSTbot b;
PrintMode p;

void setup() {
  Serial.begin(115200);

//  b.setMotorBias(0.88);
//  b.setSpeed(110);

  log("Hello World!");
  log("Hello 2");

}

  //update_loop_timer();

void loop() {

  parse_serial_command(b, p);
  p.print();
//  b.op_check();

  //log("Hello");

//
//  if (digitalRead(FRONT_LEFT_IR) == 0 && digitalRead(FRONT_RIGHT_IR) == 0) {
//    log("Detection condition.");
//    b.evadeBorder(FRONT_SIDE);
//  }

}
