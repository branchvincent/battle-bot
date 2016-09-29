#include <AFMotor.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_HMC5883_U.h>
#include <SPI.h>
#include "utilities.h"
#include "magnetometer.h"
#include "ChinaBee.h"
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

ChinaBee bee;

void setup() {
  init_utilities();
  init_magsensor();

  b.setMotorBias(0.757);
  b.setSpeed(200);
  //b.startMotors();
  
  log("Hello World!");

  bee.init(48, 49);
  


}


// Fastest Loop Time:
// 6240 microseconds
// With magnetometer: 22880 microseconds.

// Reguar (9600): 22880
// Baud (): 2200



// Bottom-Right: (85.00,18.00)
// Top-Right: (87.00,196.00)
// Top-Left: (265.00,194.00)
// Bottom-Left: (260.00,14.00)

int x_true(float x) {
  return -x+260;
}

int y_true(float y) {
  return y-14;
}

void loop() {

  parse_serial_command();
  //update_mag_running();
  //update_loop_timer();

  bee.update();

  for (int i = 0; i < bee.get_num_teams(); i++) {
    team_status_t* stat = bee.get_status(i);
    if (stat->haveFound || true) {
      //Serial.print("Team ");
      //Serial.print(i);
      Serial.print("(");
      Serial.print(x_true(stat->x));
      Serial.print(",");
      Serial.print(y_true(stat->y));
      Serial.print(")");
      //Serial.print(" time since (ms): ");
      //Serial.print(millis() - stat->timestamp);
    }
  }
  Serial.println("");
  
  
}





