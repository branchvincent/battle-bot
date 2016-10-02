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
        Op(String lab, long end);
        virtual bool execute() = 0;
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

class RotationOp : public Op {

    public:
        RotationOp(int rotationDegs, int rotationDir);
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

class TranslationOp : public Op {
    public:
        TranslationOp(int motorDir, int motorSpd);
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

// class ReverseABitOp : public TranslationOp {
//
//   public:
//     ReverseABitOp();
//     bool execute();
// };

#endif
