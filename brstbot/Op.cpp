#include "Op.h"
#include "Globals.h"
#include <Arduino.h>

class BRSTbot;

using namespace globals;
using namespace std;

// For representing operations on the robot.

/****************************************************************************
*                                      *
* Definition of Op class                              *
*                                     *
****************************************************************************/



//long Op::endTime = 0;
//virtual bool Op::execute()=0;

/****************************************************************************
*                                     *
* Definition of Rotation class                      *
*                                     *
****************************************************************************/

Rotation::Rotation() {
  label = "rotation";
}

bool Rotation::execute() {

}

bool Translation::execute() {
  if (millis() <= endTime) {
    brstbot->setMotorSpeed(motorSpeed);
    brstbot->setMotorDirection(motorDirection);
    return false;
  } else {
    return true;
  }

}


/****************************************************************************
*                                     *
* Definition of Sonar class                         *
*                                     *
****************************************************************************/


ReverseABit::ReverseABit() {
  label = "reverse_a_bit";
  endTime = millis() + 500;
  motorDirection = BACKWARD;
  motorSpeed = 255;
}

bool ReverseABit::execute() {
  Translation::execute();
}


