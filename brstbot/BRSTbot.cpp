#include "BRSTbot.h"
#include "EnumTypes.h"
#include "Utilities.h"
#include <AFMotor.h>

extern const int BOT_EVASIVE_SPEED;


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
    //   delete finishedOp;
//      setSpeed(110);
//      setMotorDirection(FORWARD);
    }
}

void BRSTbot::evadeBorder(int side) {

    switch (side) {

        case FRONT_SIDE: {
            if (currentOp != NULL && currentOp->label.equals("evade_front")) {
                log("Already evading front! Yielding...");
            } else {
                TranslationOp* reverse = new TranslationOp(BACKWARD, BOT_EVASIVE_SPEED, "evade_front");
                TranslationOp* forward = new TranslationOp(FORWARD, BOT_EVASIVE_SPEED, "evade_front2");
                RotationOp* rotate = new RotationOp(180, ROTATE_LEFT, "evade_front2");

                reverse->nextOp = rotate;
                rotate->nextOp = forward;

                currentOp = reverse;
            }
            break;
        }

      case BACK_SIDE:
        break;
      case LEFT_SIDE:
        break;
      case RIGHT_SIDE:
        break;
      case FRONT_LEFT_CORNER:
        break;
      case FRONT_RIGHT_CORNER:
        break;
      case BACK_LEFT_CORNER:
        break;
      case BACK_RIGHT_CORNER:
        break;
      default:
        break;
    }
}
