#include <AFMotor.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_HMC5883_U.h>
#include "utilities.h"
#include "magnetometer.h"
#include "BRSTbot.h"
 
/* 
 * Requires installation of the following libraries:
 * 
 * https://github.com/adafruit/Adafruit-Motor-Shield-library
 * https://github.com/adafruit/Adafruit_HMC5883_Unified
 * https://github.com/adafruit/Adafruit_Sensor
 * 
 */

/*
 * TODO:
 * 
 *   Print command.
 * 
 */

BRSTbot b;
String print_mode = "none";

void run_command(String key, String value) {
  if (key.equals("speed")) {   // e.g., user entered  "speed:37"  in serial monitor
    
    b.setSpeed(value.toInt());
    log("Changing speed to: ", value);
    
  } else if (key.equals("dir")) {
    
    if (value.equals("forward")) { b.startMotors(); } 
    else if (value.equals("back")) { b.reverseMotors(); }
    else if (value.equals("stop")) { b.stopMotors(); }
    log("Setting motor direction to: ", value);
    
  } else {
    
    log("Command '", concat(key, "' not recognized."));
    
  }
}

void print_command() {
  
}

void setup() {
  init_utilities();
  init_magsensor();

  b.setMotorBias(0.757);
  b.setSpeed(200);
  //b.startMotors();
  
  log("Hello World!");

  
  


}


// Fastest Loop Time:
// 6240 microseconds
// With magnetometer: 22880 microseconds.

// Reguar (9600): 22880
// Baud (): 2200

void loop() {


  
  parse_serial_command();
  update_mag_running();
  update_loop_timer();


  //log("Average: ", get_mag_heading());
  
}




