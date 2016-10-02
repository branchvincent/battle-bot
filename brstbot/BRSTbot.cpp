#include "BRSTbot.h"
#include "EnumTypes.h"
#include "Utilities.h"
#include <AFMotor.h>

extern const int BOT_EVASIVE_SPEED;
extern const int BOT_CRUISING_SPEED;

BRSTbot::BRSTbot() : motorLeft(1, MOTOR12_64KHZ), motorRight(2, MOTOR12_64KHZ) {}

  /* Getters and Setters */

void BRSTbot::setSpeed(int s) {
    speed = s;
    motorLeft.setSpeed(speed * motorBias);
    motorRight.setSpeed(speed);
}

int BRSTbot::getSpeed() {
    return speed;
}

void BRSTbot::setMotorBias(float b) {
    motorBias = b;
    setSpeed(speed);
}

float BRSTbot::getMotorBias() {
    return motorBias;
}

void BRSTbot::setTarget(Point t) {
    target = t;
}

void BRSTbot::setTarget(float x, float y) {
    Point p;
    p.x = x;
    p.y = y;
    setTarget(p);
}

Point BRSTbot::getTarget() {
    return target;
}

int BRSTbot::getRawHeading() {
    return 0;//mag_sensor_heading_average;
}

int BRSTbot::getTrueHeading() {
    return 0;//mag_raw_to_true(mag_sensor_heading_average);
}

int getTrueHeadingUnaverage() {
    return 0;//mag_raw_to_true(mag_sensor_heading_unaverage);
}

int BRSTbot::getHeading() {
    return 0;//mag_sensor_heading_average;
}

int BRSTbot::getRawHeadingUnaverage() {
    return 0;//mag_sensor_heading_unaverage;
}

int BRSTbot::getVisualHeading() {
    return 0;//visualHeading;
}

int BRSTbot::getTargetHeading() {
    return 0;//targetHeading;
}

/*  Non-Getters/Setters  */

void BRSTbot::startMotors() {
    motorLeft.run(FORWARD);
    motorRight.run(FORWARD);
}

void BRSTbot::reverseMotors() {
    motorLeft.run(BACKWARD);
    motorRight.run(BACKWARD);
}

void BRSTbot::stopMotors() {
    motorLeft.run(RELEASE);
    motorRight.run(RELEASE);
}

void BRSTbot::rotateStraight() {
    motorLeft.run(FORWARD);
    motorRight.run(FORWARD);
}

void BRSTbot::rotateLeft() {
    motorLeft.run(BACKWARD);
    motorRight.run(FORWARD);
}

void BRSTbot::rotateRight() {
    motorLeft.run(FORWARD);
    motorRight.run(BACKWARD);
}

void BRSTbot::setRotationDirection(int rotation) {
    if (rotation == ROTATE_LEFT) {
      rotateLeft();
    } else if (rotation = ROTATE_RIGHT) {
      rotateRight();
    } else if (rotation = ROTATE_STRAIGHT) {
      rotateStraight();
    }
}

// BACKWARD, FORWARD
void BRSTbot::setMotorDirection(int direction) {
    motorLeft.run(direction);
    motorRight.run(direction);
}

void BRSTbot::customConfiguration() {
    motorLeft.run(RELEASE);
    motorRight.run(FORWARD);
}

//void BRSTbot::rotateToHeading(int degrees) {}

void BRSTbot::setOp(Op* o) {

    Op* curr = currentOp;
    Op* temp = curr;

    if (curr != NULL) {
        while (curr != NULL && curr->nextOp != NULL) {
            temp = curr;
            curr = curr->nextOp;
            delete temp;
        }
        delete curr;
    }

    currentOp = o;
}

void BRSTbot::op_check() {

    if (currentOp != NULL && currentOp->execute()) {
//      log(S("Executing
      // Op finished execution. Replace with next op if necessary.
      Op* finishedOp = currentOp;

      if (currentOp->nextOp != NULL) {
        log(currentOp->nextOp->label);
        currentOp = currentOp->nextOp;
      } else {
        currentOp = NULL;
        log("No Next op!");
      }
      delete finishedOp;
//      setSpeed(110);
//      setMotorDirection(FORWARD);
    }
}

void BRSTbot::evadeBorder(int side) {

    switch (side) {

        case FRONT_SIDE: {
            int op_label = EVADE_FRONT;

            if (currentOp != NULL && currentOp->label == op_label) {
                log("Already evading front! Yielding...");
            } else {
                log("Creating front evasion...");
                TranslationOp* reverse = new TranslationOp(BACKWARD, BOT_EVASIVE_SPEED, op_label);
                RotationOp* rotate = new RotationOp(180, ROTATE_LEFT, op_label);
                TranslationOp* forward = new TranslationOp(FORWARD, BOT_CRUISING_SPEED, op_label);

                reverse->nextOp = rotate;
                rotate->nextOp = forward;
                setOp(reverse);
            }
            break;
        }

        case BACK_SIDE: {
            int op_label = EVADE_BACK;

            if (currentOp != NULL && currentOp->label == op_label) {
                log("Already evading back! Yielding...");
            } else {
                log("Creating front evasion...");
                TranslationOp* forward = new TranslationOp(FORWARD, BOT_CRUISING_SPEED, op_label);
                setOp(forward);
            }
            break;
        }

        case LEFT_SIDE:{
            int op_label = EVADE_LEFT;

            if (currentOp != NULL && currentOp->label == op_label) {
                log("Already evading left! Yielding...");
            } else {
                log("Creating front evasion...");
                RotationOp* rotate = new RotationOp(90, ROTATE_RIGHT, op_label);
                TranslationOp* forward = new TranslationOp(FORWARD, BOT_CRUISING_SPEED, op_label);
                rotate->nextOp = forward;
                setOp(rotate);
            }
            break;
        }

        case RIGHT_SIDE: {
            int op_label = EVADE_RIGHT;

            if (currentOp != NULL && currentOp->label == op_label) {
                log("Already evading right! Yielding...");
            } else {
                log("Creating front evasion...");
                RotationOp* rotate = new RotationOp(90, ROTATE_LEFT, op_label);
                TranslationOp* forward = new TranslationOp(FORWARD, BOT_CRUISING_SPEED, op_label);
                rotate->nextOp = forward;
                setOp(rotate);
            }
            break;
        }

        case FRONT_LEFT_CORNER: {
            int op_label = EVADE_FRONT_LEFT;

            if (currentOp != NULL && currentOp->label == op_label) {
                log("Already evading front left! Yielding...");
            } else {
                log("Creating front evasion...");
                RotationOp* rotate = new RotationOp(90, ROTATE_RIGHT, op_label);
                TranslationOp* forward = new TranslationOp(FORWARD, BOT_CRUISING_SPEED, op_label);
                rotate->nextOp = forward;
                setOp(rotate);
            }
            break;
        }

        case FRONT_RIGHT_CORNER: {
            int op_label = EVADE_FRONT_RIGHT;

            if (currentOp != NULL && currentOp->label == op_label) {
                log("Already evading front right! Yielding...");
            } else {
                log("Creating front evasion...");
                RotationOp* rotate = new RotationOp(90, ROTATE_LEFT, op_label);
                TranslationOp* forward = new TranslationOp(FORWARD, BOT_CRUISING_SPEED, op_label);
                rotate->nextOp = forward;
                setOp(rotate);
            }
            break;
        }
        case BACK_LEFT_CORNER: {
            int op_label = EVADE_BACK_LEFT;

            if (currentOp != NULL && currentOp->label == op_label) {
                log("Already evading back left! Yielding...");
            } else {
                log("Creating front evasion...");
                RotationOp* rotate = new RotationOp(90, ROTATE_RIGHT, op_label);
                TranslationOp* forward = new TranslationOp(FORWARD, BOT_CRUISING_SPEED, op_label);
                rotate->nextOp = forward;
                setOp(rotate);
            }
            break;
        }
        case BACK_RIGHT_CORNER: {
            int op_label = EVADE_BACK_RIGHT;

            if (currentOp != NULL && currentOp->label == op_label) {
                log("Already evading back right! Yielding...");
            } else {
                log("Creating front evasion...");
                RotationOp* rotate = new RotationOp(90, ROTATE_LEFT, op_label);
                TranslationOp* forward = new TranslationOp(FORWARD, BOT_CRUISING_SPEED, op_label);
                rotate->nextOp = forward;
                setOp(rotate);
            }
            break;
        }
        default:
            break;
    }
}
