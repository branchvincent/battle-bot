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


//  Op rotateAmount;
//  rotateAmount.label = "rotation";
//  rotateAmount.rotationDegrees = 90;
//  rotateAmount.rotationDirection = ROTATE_LEFT;
//  b.setOp(rotateAmount);
}

  //update_loop_timer();


void loop() {

  parse_serial_command();
  //update_mag_running();
  //update_bee();
  p.print();
  b.op_check();

//  log("Hello");




  if (true) {
    if (digitalRead(BACK_LEFT_IR) == 0 && digitalRead(BACK_RIGHT_IR) == 0) {
//      Op forwardEscape;
//      forwardEscape.label = "edge_escape";
//      forwardEscape.motorDirection = FORWARD;
//      forwardEscape.motorSpeed = 200;
//      b.setOp(forwardEscape);
    } else if (digitalRead(FRONT_LEFT_IR) == 0 && digitalRead(FRONT_RIGHT_IR) == 0) {
      Op *reverseABit = new Op();
      reverseABit->label = "reverse_a_bit";

      Op *rotate = new Op();
      rotate->label = "rotation";
      rotate->rotationDirection = ROTATE_LEFT;
      rotate->rotationDegrees = 180;

      //reverseABit->nextOp = rotate;
      
      b.setOp(reverseABit);
    }
  }




  String a = "   ";
  for (int i = 44; i <= 47; i++) {
    int sensorPin = i;
    int sensorValue = digitalRead(sensorPin);
    a += String("Pin ")+ String(sensorPin) + String(": ") + sensorValue + String("     ");

  }
  //log(a);




}
