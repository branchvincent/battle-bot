#include "Op.h"
#include "BRSTbot.h"
#include "enumTypes.h"
#include "Utilities.h"
#include "Globals.h"
using namespace globals;

extern BRSTbot b;
extern const float millis_per_degree;
extern const int BOT_ROTATION_SPEED;
extern const int BOT_EVASIVE_SPEED;
extern const int rotation_base_time;

/****************************************************************************
*																			*
*	Definition of Op class											        *
*																			*
****************************************************************************/

// Op::Op() : label(""),  duration(0), endTime(0), nextOp(NULL)  {
//     log("OP Created!");
// }

Op::Op(int lab, long dur = 0) :
    label(lab),  duration(dur), endTime(0), nextOp(NULL) {
    log("OP Created!");
}

/****************************************************************************
*																			*
*	Definition of Rotation class											*
*																			*
****************************************************************************/

RotationOp::RotationOp(int rotationDegs, int rotationDir, int lab) :
    Op(lab, rotation_base_time + millis_per_degree * rotationDegs),
    rotationDegrees(rotationDegs),
    rotationDirection(rotationDir) {
    // log(S("Rotation end time = ") + endTime);
}

bool RotationOp::execute() {
    // log(S("Starting ") + label);
    // log(S("End time = ") + endTime);

    if (endTime == 0)
        endTime = millis() + duration;
    if (millis() <= endTime) {
        b.setSpeed(BOT_ROTATION_SPEED);
        b.setRotationDirection(rotationDirection);
        return false;
    } else {
        // b.setMotorDirection(FORWARD);
        return true;
    }
}

/****************************************************************************
*																			*
*	Definition of Translation class											*
*																			*
****************************************************************************/

TranslationOp::TranslationOp(int motorDir, int motorSpd, int lab, long duration) :
    Op(lab, duration),
    motorDirection(motorDir),
    motorSpeed(motorSpd)
{
    // log(S("Translation end time = ") + endTime);
}

bool TranslationOp::execute() {
    // log(S("Starting ") + label);
    // log(S("End time = ") + endTime);

    if (endTime == 0)
        endTime = millis() + duration;
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

// ReverseABitOp::ReverseABitOp() {
//     label = "reverse_a_bit";
//     endTime = millis() + 500;
//     motorDirection = BACKWARD;
//     motorSpeed = BOT_EVASIVE_SPEED;
// }
//
// bool ReverseABitOp::execute() {
//     log("Reverse is executing!");
//     return TranslationOp::execute();
//     //log("Reverse is executing!");
//
// }
