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
  if (key.equals("speed")) {
    log("Changing speed to: ", value);
    b.setSpeed(value.toInt());
  } else {
    log("Command '", concat(key, "' not recognized."));
  }
}

void setup() {
  init_utilities();
  
  log("Hello World!");
  log(b.getSpeed());
  b.setSpeed(7);
  log(b.getSpeed());
}

void loop() {
  parse_serial_command();

}




