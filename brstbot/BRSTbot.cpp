#include <AFMotor.h>
#include "BRSTbot.h"
#include "EnumTypes.h"
#include "Utilities.h"
#include "Globals.cpp"

// extern const int BOT_EVASIVE_SPEED;
// extern const int BOT_CRUISING_SPEED;

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
        // log(currentOp->nextOp->label);
        // Op* temp = currentOp;
        currentOp = currentOp->nextOp;
        // delete temp;
      } else {
        currentOp = NULL;
        log("No Next op!");
      }
      delete finishedOp;
    //   stopMotors();
    //  setSpeed(110);
//      setMotorDirection(FORWARD);
    }
}

void BRSTbot::followSonarResult(int r) {

    RotationOp* rotate;
    int op_label = FOLLOW_TARGET;

    // Call to here implies mode is in CRUISE_FORWARD.
    if (r == DETECT_LEFT) {
        rotate = new RotationOp(35, ROTATE_LEFT, op_label);
    } else if (r == DETECT_RIGHT) {
        rotate = new RotationOp(35, ROTATE_RIGHT, op_label);
    }

    TranslationOp* followForward = new TranslationOp(FORWARD, BOT_CRUISING_SPEED, op_label, 5000);
    TranslationOp* cruise = new TranslationOp(FORWARD, BOT_CRUISING_SPEED, CRUISE_FORWARD);

    rotate->nextOp = followForward;
    followForward->nextOp = cruise;
    setOp(rotate);


}

void BRSTbot::evadeBorder(int side) {

    switch (side) {

        case FRONT_SIDE: {
            int op_label = EVADE_FRONT;

            if (currentOp != NULL && currentOp->label == op_label) {
                // log("Already evading front! Yielding...");
            } else {
                log("Creating front evasion...");
                TranslationOp* reverse = new TranslationOp(BACKWARD, BOT_EVASIVE_SPEED, op_label, 500);
                RotationOp* rotate = new RandRotationOp(180, 20, ROTATE_LEFT, op_label);
                TranslationOp* forward = new TranslationOp(FORWARD, BOT_EVASIVE_SPEED, op_label, 500);
                TranslationOp* cruise = new TranslationOp(FORWARD, BOT_CRUISING_SPEED, CRUISE_FORWARD);

                reverse->nextOp = rotate;
                rotate->nextOp = forward;
                forward->nextOp = cruise;
                setOp(reverse);
            }
            break;
        }

        case BACK_SIDE: {
            int op_label = EVADE_BACK;

            if (currentOp != NULL && currentOp->label == op_label) {
                // log("Already evading back! Yielding...");
            } else {
                log("Creating front evasion...");
                TranslationOp* forward = new TranslationOp(FORWARD, BOT_EVASIVE_SPEED, op_label, 500);
                TranslationOp* cruise = new TranslationOp(FORWARD, BOT_CRUISING_SPEED, CRUISE_FORWARD);
                forward->nextOp = cruise;
                setOp(forward);
            }
            break;
        }

        case LEFT_SIDE:{
            int op_label = EVADE_LEFT;

            if (currentOp != NULL && currentOp->label == op_label) {
                // log("Already evading left! Yielding...");
            } else {
                log("Creating front evasion...");
                RotationOp* rotate = new RandRotationOp(90, 20, ROTATE_RIGHT, op_label);
                TranslationOp* forward = new TranslationOp(FORWARD, BOT_EVASIVE_SPEED, op_label, 500);
                TranslationOp* cruise = new TranslationOp(FORWARD, BOT_CRUISING_SPEED, CRUISE_FORWARD);
                rotate->nextOp = forward;
                forward->nextOp = cruise;
                setOp(rotate);
            }
            break;
        }

        case RIGHT_SIDE: {
            int op_label = EVADE_RIGHT;

            if (currentOp != NULL && currentOp->label == op_label) {
                // log("Already evading right! Yielding...");
            } else {
                log("Creating front evasion...");
                RotationOp* rotate = new RandRotationOp(90, 20, ROTATE_LEFT, op_label);
                TranslationOp* forward = new TranslationOp(FORWARD, BOT_EVASIVE_SPEED, op_label, 500);
                TranslationOp* cruise = new TranslationOp(FORWARD, BOT_CRUISING_SPEED, CRUISE_FORWARD);
                rotate->nextOp = forward;
                forward->nextOp = cruise;
                setOp(rotate);
            }
            break;
        }

        case FRONT_LEFT_CORNER: {
            int op_label = EVADE_FRONT_LEFT;

            if (currentOp != NULL && (currentOp->label == op_label || currentOp->label == EVADE_FRONT || currentOp->label == EVADE_LEFT)) {
                // log("Already evading front left! Yielding...");
            } else {
                log("Creating front evasion...");
                RotationOp* rotate = new RandRotationOp(90, 20, ROTATE_RIGHT, op_label);
                TranslationOp* forward = new TranslationOp(FORWARD, BOT_EVASIVE_SPEED, op_label, 500);
                TranslationOp* cruise = new TranslationOp(FORWARD, BOT_CRUISING_SPEED, CRUISE_FORWARD);
                rotate->nextOp = forward;
                forward->nextOp = cruise;
                setOp(rotate);
            }
            break;
        }

        case FRONT_RIGHT_CORNER: {
            int op_label = EVADE_FRONT_RIGHT;

            if (currentOp != NULL && (currentOp->label == op_label || currentOp->label == EVADE_FRONT || currentOp->label == EVADE_RIGHT)) {
                // log("Already evading front right! Yielding...");
            } else {
                log("Creating front evasion...");
                RotationOp* rotate = new RandRotationOp(90, 20, ROTATE_LEFT, op_label);
                TranslationOp* forward = new TranslationOp(FORWARD, BOT_EVASIVE_SPEED, op_label, 500);
                TranslationOp* cruise = new TranslationOp(FORWARD, BOT_CRUISING_SPEED, CRUISE_FORWARD);
                rotate->nextOp = forward;
                forward->nextOp = cruise;
                setOp(rotate);
            }
            break;
        }
        case BACK_LEFT_CORNER: {
            int op_label = EVADE_BACK_LEFT;

            if (currentOp != NULL && (currentOp->label == op_label || currentOp->label == EVADE_LEFT || currentOp->label == EVADE_BACK || currentOp->label == EVADE_BACK_RIGHT)) {
                // log("Already evading back left! Yielding...");
            } else {
                log("Creating front evasion...");
                RotationOp* rotate = new RandRotationOp(90, 20, ROTATE_RIGHT, op_label);
                TranslationOp* forward = new TranslationOp(FORWARD, BOT_EVASIVE_SPEED, op_label, 500);
                TranslationOp* cruise = new TranslationOp(FORWARD, BOT_CRUISING_SPEED, CRUISE_FORWARD);
                rotate->nextOp = forward;
                rotate->nextOp = cruise;
                setOp(rotate);
            }
            break;
        }
        case BACK_RIGHT_CORNER: {
            int op_label = EVADE_BACK_RIGHT;

            if (currentOp != NULL && (currentOp->label == op_label || currentOp->label == EVADE_BACK || currentOp->label == EVADE_RIGHT) || currentOp->label == EVADE_BACK_LEFT) {
                // log("Already evading back right! Yielding...");
            } else {
                log("Creating front evasion...");
                RotationOp* rotate = new RandRotationOp(90, 20, ROTATE_LEFT, op_label);
                TranslationOp* forward = new TranslationOp(FORWARD, BOT_EVASIVE_SPEED, op_label, 500);
                TranslationOp* cruise = new TranslationOp(FORWARD, BOT_CRUISING_SPEED, CRUISE_FORWARD);
                rotate->nextOp = forward;
                forward->nextOp = cruise;
                setOp(rotate);
            }
            break;
        }
        default:
            break;
    }
}
