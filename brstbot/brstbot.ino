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


const int FRONT_LEFT_IR = 44;
const int FRONT_RIGHT_IR = 44;
const int BACK_LEFT_IR = 44;
const int BACK_RIGHT_IR = 44;



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





