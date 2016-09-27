#include <AFMotor.h>
#include "utilities.h"

// Requires installation of the following libraries:
/*
 * https://github.com/adafruit/Adafruit-Motor-Shield-library
 * https://github.com/adafruit/Adafruit_HMC5883_Unified
 * https://github.com/adafruit/Adafruit_Sensor
 * 
 */

class BRSTbot {
  public:
    int speed;
};



void parse_command(String s) {
  
}


void setup() {
  // put your setup code here, to run once:
  init_utilities();
  BRSTbot b;
  log("Hello World!");
  log(b.speed);
  b.speed = 7;
  log(b.speed);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    log(Serial.readString());
  }
}




