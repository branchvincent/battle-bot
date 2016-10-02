#include "BRSTbot.h"

/****************************************************************************
*																			*
*	Definition of Op class											        *
*																			*
****************************************************************************/

Op::Op() : endTime(0) {}
virtual bool Op::execute() = 0;

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
        BRSTbot::b.setMotorSpeed(motorSpeed);
        BRSTbot::b.setMotorDirection(motorDirection);
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
    Translation::execute();
}

#endif
