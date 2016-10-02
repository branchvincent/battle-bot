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
#include "IRSensor.h"
#include "EnumTypes.h"
//#include "magnetometer.h"
//#include "ChinaBee.h"
//#include "Bot.h"
//#include "Bee.h"

const int FRONT_LEFT_IR = 46;
const int FRONT_RIGHT_IR = 47;
const int BACK_LEFT_IR = 44;
const int BACK_RIGHT_IR = 45;

//  Globals

BRSTbot b;
PrintMode p;
// IRSensor FL(46);
// IRSensor FR(47);
// IRSensor BL(44);
// IRSensor BR(45);


void setup() {
    // init_utilities();
    Serial.begin(115200);
    //  init_magsensor();
    //  init_bee();

    b.setMotorBias(0.88);
    b.setSpeed(110);

    log("Hello World!");
}

  //update_loop_timer();

void loop() {

  parse_serial_command(b, p);
  //update_mag_running();
  //update_bee();
  p.print();
  b.op_check();

  //log("Hello");


    if (digitalRead(FRONT_LEFT_IR) == 0 && digitalRead(FRONT_RIGHT_IR) == 0) {
        log("Detection condition.");
        b.evadeBorder(FRONT_SIDE);
    }

  // if (FL.detected() && FR.detected()) {
  //     b.evadeBorder(FRONT_SIDE)
  // }
  // else if (FL)


}
