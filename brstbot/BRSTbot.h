#ifndef BRSTBOT_H
#define BRSTBOT_H

#include <AFMotor.h>
#include "Point.h"
#include "Op.h"
#include "EnumTypes.h"
#include "Globals.h"

// Low Batt: 10.5
// Fresh Batt: 8.5

// const float ms_per_degree = 4.25;
// const int BOT_ROTATION_SPEED = 110;
// const int BOT_EVASIVE_SPEED = 255;
// const int BOT_CRUISING_SPEED = 110;
// const int rotation_base_time = 100;

class BRSTbot {

    public:
        BRSTbot();
        void setSpeed(int s);
        int getSpeed();
        void setMotorBias(float b);
        float getMotorBias();
        void setTarget(Point t);
        void setTarget(float x, float y);
        Point getTarget();
        int getRawHeading();
        int getTrueHeading();
        int getTrueHeadingUnaverage();
        int getHeading();
        int getRawHeadingUnaverage();
        int getVisualHeading();
        int getTargetHeading();
        void startMotors();
        void reverseMotors();
        void stopMotors();
        void rotateStraight();
        void rotateLeft();
        void rotateRight();
        void setRotationDirection(int rotation);
        void setMotorDirection(int direction);
        void customConfiguration();
        void setOp(Op* o);
        void op_check();
        void followSonarResult(int r);
        void evadeBorder(int side);
        // static const int MOTOR_LOW_SPEED = 110;
        // static const int MOTOR_HIGH_SPEED = 255;

      public:
        Op* currentOp;

      private:
          int speed;
          float motorBias;
          AF_DCMotor motorLeft;
          AF_DCMotor motorRight;
          Point target;
          int visualHeading = 0;
          int targetHeading = 0;
 };

#endif
