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


const int FRONT_LEFT_IR = 46;
const int FRONT_RIGHT_IR = 47;
const int BACK_LEFT_IR = 44;
const int BACK_RIGHT_IR = 45;



void setup() {
  init_utilities();
  init_magsensor();
  init_bee();

  b.setMotorBias(0.88);
  b.setSpeed(110);
  
  log("Hello World!");
  log("Hello 2");
  

}

  //update_loop_timer();

  
void loop() {

  parse_serial_command();
  //update_mag_running();
  //update_bee();
  p.print();
  b.op_check();

//  log("Hello");

  String a = "   ";

  if (digitalRead(BACK_LEFT_IR) == 0 && digitalRead(BACK_RIGHT_IR) == 0) {
    Op forwardEscape;
    forwardEscape.label = "edge_escape";
    forwardEscape.motorDirection = FORWARD;
    forwardEscape.motorSpeed = 200;
    forwardEscape.timeEnd = millis() + 1000;
    b.setOp(forwardEscape);
  } else if (digitalRead(FRONT_LEFT_IR) == 0 && digitalRead(FRONT_RIGHT_IR) == 0) {
    Op backEscape;
    backEscape.label = "edge_escape";
    backEscape.motorDirection = BACKWARD;
    backEscape.motorSpeed = 200;
    backEscape.timeEnd = millis() + 1000;
    b.setOp(backEscape);
  }
  
  
  
  for (int i = 44; i <= 47; i++) {
    int sensorPin = i;
    int sensorValue = digitalRead(sensorPin);
    a += String("Pin ")+ String(sensorPin) + String(": ") + sensorValue + String("     ");
    
  }
  //log(a);


  

}





