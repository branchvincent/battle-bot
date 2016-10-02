#ifndef OP_H
#define OP_H

<<<<<<< HEAD
#include "BRSTbot.h"
#include "Globals.h"
=======
>>>>>>> newbrstbot

//#include "Globals.h"

class BRSTbot;

//using namespace globals;

// For representing operations on the robot.

/****************************************************************************
*																			*
*	Definition of Op class											        *
*																			*
****************************************************************************/

class BRSTbot;

class Op {

  public:
    String label;
    long endTime;
    static BRSTbot* brstbot;

    Op *nextOp;

<<<<<<< HEAD
    virtual bool execute(BRSTbot& a)=0;
=======
    virtual bool execute();
>>>>>>> newbrstbot

};

/****************************************************************************
*																			*
*	Definition of Rotation class											*
*																			*
****************************************************************************/

class Rotation : public Op {

  public:
    int rotationDegrees;
    int rotationDirection;

<<<<<<< HEAD
    Rotation() {
      label = "rotation";
    }

    bool execute(BRSTbot& a) {
=======
    Rotation();
>>>>>>> newbrstbot

    bool execute();

};

class Translation : public Op {

  public:
    int motorDirection;
    int motorSpeed;

<<<<<<< HEAD
    bool execute(BRSTbot& b) {
      if (millis() <= endTime) {
        b.setMotorSpeed(motorSpeed);
        b.setMotorDirection(motorDirection);
        return false;
      } else {
        return true;
      }

    }
=======
    bool execute();
>>>>>>> newbrstbot
};

/****************************************************************************
*                                     *
* Definition of Sonar class                         *
*                                     *
****************************************************************************/


class ReverseABit : public Translation {

  public:
<<<<<<< HEAD
    ReverseABit() {
      label = "reverse_a_bit";
      endTime = millis() + 500;
      motorDirection = BACKWARD;
      motorSpeed = 255;
    }

    bool execute(BRSTbot& a) {
      Translation::execute(a);
    }
=======
    ReverseABit();

    bool execute();
>>>>>>> newbrstbot


};

#endif
