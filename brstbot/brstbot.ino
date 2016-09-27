#include <AFMotor.h>
#include "utilities.h"
#include "BRSTbot.h"
 
/* 
 * Requires installation of the following libraries:
 * 
 * https://github.com/adafruit/Adafruit-Motor-Shield-library
 * https://github.com/adafruit/Adafruit_HMC5883_Unified
 * https://github.com/adafruit/Adafruit_Sensor
 * 
 */


BRSTbot b;

void run_command(String key, String value) {
  if (key.equals("speed")) {   // e.g., user entered  "speed:37"  in serial monitor
    log("Changing speed to: ", value);
    b.setSpeed(value.toInt());
  } else {
    log("Command '", concat(key, "' not recognized."));
  }
}

void setup() {
  init_utilities();

  b.setMotorBias(0.757);
  
  log("Hello World!");
  log(b.getSpeed());
  b.setSpeed(200);
  log(b.getSpeed());
  b.startMotors();
}

void loop() {
  parse_serial_command();
  //delay(2000);
  //b.stopMotors();
}




