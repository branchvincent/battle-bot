#ifndef OP_H
#define OP_H


//#include "Globals.h"

class BRSTbot;

//using namespace globals;

// For representing operations on the robot.

/****************************************************************************
*																			*
*	Definition of Op class											        *
*																			*
****************************************************************************/


class Op {

  public:
    String label;
    long endTime;
    static BRSTbot* brstbot;

    Op *nextOp;

    virtual bool execute();

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

    Rotation();

    bool execute();

};

class Translation : public Op {

  public:
    int motorDirection;
    int motorSpeed;

    bool execute();
};

/****************************************************************************
*                                     *
* Definition of Sonar class                         *
*                                     *
****************************************************************************/


class ReverseABit : public Translation {

  public:
    ReverseABit();

    bool execute();


};

#endif
