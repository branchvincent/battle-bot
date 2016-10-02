#ifndef OP_H
#define OP_H

#include <WString.h>
using namespace std;

/****************************************************************************
*																			*
*	Definition of Op class											        *
*																			*
****************************************************************************/

class Op {
    public:
        Op();
        virtual bool execute();
    public:
        String label;
        long endTime;
        Op *nextOp;
};

/****************************************************************************
*																			*
*	Definition of Rotation class											*
*																			*
****************************************************************************/

class Rotation : public Op {

    public:
        Rotation();
        bool execute();
    public:
        int rotationDegrees;
        int rotationDirection;
};

/****************************************************************************
*																			*
*	Definition of Translation class											*
*																			*
****************************************************************************/

class Translation : public Op {
    public:
        bool execute();
    public:
        int motorDirection;
        int motorSpeed;
};

/****************************************************************************
*                                                                           *
*   Definition of ReverseABit class                                         *
*                                                                           *
****************************************************************************/

class ReverseABit : public Translation {

  public:
    ReverseABit();
    bool execute();
};

#endif
