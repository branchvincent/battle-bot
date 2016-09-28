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


BRSTbot b;

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

void setup() {
  init_utilities();
  init_magsensor();

  b.setMotorBias(0.757);
  b.setSpeed(200);
  //b.startMotors();
  
  log("Hello World!");

  
  


}

unsigned long time;
unsigned long last_time;

// Fastest Loop Time:
// 6240 microseconds

void loop() {

  time = micros();
  print_log_counter();
  Serial.println(time - last_time);
  last_time = time;
  
  //parse_serial_command();
  //update_mag();
  //update_mag_running();



  //log("Average: ", get_mag_heading());
  
}




