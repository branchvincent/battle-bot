#include <AFMotor.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_HMC5883_U.h>
#include <SPI.h>
#include "utilities.h"
#include "magnetometer.h"
#include "ChinaBee.h"
#include "BRSTbot.h"
#include "Print.h"
#include "Bot.h"
#include "Bee.h"
#include "B_Run.h"


/* 
 * Requires installation of the following libraries:
 * 
 * https://github.com/adafruit/Adafruit-Motor-Shield-library
 * https://github.com/adafruit/Adafruit_HMC5883_Unified
 * https://github.com/adafruit/Adafruit_Sensor
 * 
 */

void setup() {
  init_utilities();
  init_magsensor();
  init_bee();

  b.setMotorBias(0.88);
  
  log("Hello World!");

}

  //update_loop_timer();

  
void loop() {

  parse_serial_command();
  update_mag_running();
  update_bee();
  p.print();

}





