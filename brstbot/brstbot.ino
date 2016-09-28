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

void loop() {
  parse_serial_command();
  //delay(2000);
  //b.stopMotors();

  sensors_event_t event;
  mag.getEvent(&event);

//  log("X: ", event.magnetic.x); 
//  log("Y: ", event.magnetic.y);
//  log("Z: ", event.magnetic.z);

  // Hold the module so that Z is pointing 'up' and you can measure the heading with x&y
  // Calculate heading when the magnetometer is level, then correct for signs of axis.
  float heading = atan2(event.magnetic.y, event.magnetic.x);
  
  // Once you have your heading, you must then add your 'Declination Angle', which is the 'Error' of the magnetic field in your location.
  // Find yours here: http://www.magnetic-declination.com/
  // Mine is: -13* 2' W, which is ~13 Degrees, or (which we need) 0.22 radians
  // If you cannot find your Declination, comment out these two lines, your compass will be slightly off.
  float declinationAngle = 0.22;
  heading += declinationAngle;
  
  // Correct for when signs are reversed.
  if(heading < 0)
    heading += 2*PI;
    
  // Check for wrap due to addition of declination.
  if(heading > 2*PI)
    heading -= 2*PI;
   
  // Convert radians to degrees for readability.
  float headingDegrees = heading * 180/M_PI; 
  
  Serial.print("Heading (degrees): "); Serial.println(headingDegrees); //log("");

  
  
  
}




