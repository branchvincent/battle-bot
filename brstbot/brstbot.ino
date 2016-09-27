#include <AFMotor.h>
#include "utilities.h"

 
/* 
 * Requires installation of the following libraries:
 * 
 * https://github.com/adafruit/Adafruit-Motor-Shield-library
 * https://github.com/adafruit/Adafruit_HMC5883_Unified
 * https://github.com/adafruit/Adafruit_Sensor
 * 
 */

class BRSTbot {
  public:
    int speed;
};




void run_command(String key, String value) {
  if (key.equals("speed")) {
    log("Changing speed to: ", value);
  } else {
    log("Command '", concat(key, "' not recognized."));
  }
}

void setup() {
  init_utilities();
  
  BRSTbot b;
  log("Hello World!");
  log(b.speed);
  b.speed = 7;
  log(b.speed);
}

void loop() {
  parse_serial_command();

}




