#include "Op.h"
#include "BRSTbot.h"
#include "Arduino.h"

#include "Utilities.h"
#include "Globals.h"
using namespace globals;

extern BRSTbot b;

/****************************************************************************
*																			*
*	Definition of Op class											        *
*																			*
****************************************************************************/

Op::Op() : endTime(0) {}

/****************************************************************************
*																			*
*	Definition of Rotation class											*
*																			*
****************************************************************************/

Rotation::Rotation() {
  label = "rotation";
}

bool Rotation::execute() {

}

/****************************************************************************
*																			*
*	Definition of Translation class											*
*																			*
****************************************************************************/

bool Translation::execute() {
    if (millis() <= endTime) {
        b.setSpeed(motorSpeed);
        b.setMotorDirection(motorDirection);
        return false;
    } else {
        return true;
    }
}

/****************************************************************************
*                                                                           *
*   Definition of ReverseABit class                                         *
*                                                                           *
****************************************************************************/

ReverseABit::ReverseABit() {
    label = "reverse_a_bit";
    endTime = millis() + 500;
    motorDirection = BACKWARD;
    motorSpeed = 255;
}

bool ReverseABit::execute() {
    log("Reverse is executing!");
    return Translation::execute();
    //log("Reverse is executing!");
    
}


