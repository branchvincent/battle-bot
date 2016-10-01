#ifndef OP_H
#define OP_H

#include "BRSTbot.h"




// For representing operations on the robot.
class Op {

  public:
    String label;
    long endTime = 0;
    
    Op *nextOp;

    virtual bool execute()=0;
  
};


class Rotation : public Op {

  public:
    int rotationDegrees;
    int rotationDirection;

    Rotation() {
      label = "rotation";
    }

    bool execute() {
      
    }
  
};

class Translation : public Op {

  public:
    int motorDirection;
    int motorSpeed;
    
    bool execute() {
      if (millis() <= endTime) {
        b.setMotorSpeed(motorSpeed);
        b.setMotorDirection(motorDirection);
        return false;
      } else {
        return true;
      }
      
    }
};

class ReverseABit : public Translation {

  public:
    ReverseABit() {
      label = "reverse_a_bit";
      endTime = millis() + 500;
      motorDirection = BACKWARD;
      motorSpeed = 255;
    }

    bool execute() {
      Translation::execute();
    }
    
  
};

#endif









