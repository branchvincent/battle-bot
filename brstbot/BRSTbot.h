

enum RotationDirection {
  ROTATE_LEFT,
  ROTATE_RIGHT,
  ROTATE_STRAIGHT
};

enum Side {
  FRONT_SIDE,
  BACK_SIDE,
  LEFT_SIDE,
  RIGHT_SIDE, 
  FRONT_LEFT_CORNER,
  FRONT_RIGHT_CORNER,
  BACK_LEFT_CORNER,
  BACK_RIGHT_CORNER
};


// Low Batt: 10.5
// Fresh Batt: 8.5

const float millis_per_degree = 4.25;
const int BOT_ROTATION_SPEED = 110;
const int BOT_EVASIVE_SPEED = 255;
const int rotation_base_time = 100;



class BRSTbot {
  private:
    int speed;
    float motorBias;
    AF_DCMotor motorLeft;
    AF_DCMotor motorRight;
    Point target;
    const int MOTOR_LOW_SPEED;
    const int MOTOR_HIGH_SPEED;
    Op* currentOp;
    int visualHeading = 0;
    int targetHeading = 0;

  public:

  BRSTbot() : motorLeft(1, MOTOR12_64KHZ), motorRight(2, MOTOR12_64KHZ) {

  }

  /* Getters and Setters */
  
  void setSpeed(int s) {
    speed = s;
    motorLeft.setSpeed(speed * motorBias);
    motorRight.setSpeed(speed);
  }

  int getSpeed() {
    return speed;
  }

  void setMotorBias(float b) {
    motorBias = b;
    setSpeed(speed);
  }

  float getMotorBias() {
    return motorBias;
  }

  void setTarget(Point t) {
    target = t;
  }

  void setTarget(float x, float y) {
    Point p;
    p.x = x;
    p.y = y;
    setTarget(p);
  }

  Point getTarget() {
    return target;
  }

  int getRawHeading() {
    return mag_sensor_heading_average;
  }

  int getTrueHeading() {
    return mag_raw_to_true(mag_sensor_heading_average);
  }

  int getTrueHeadingUnaverage() {
    return mag_raw_to_true(mag_sensor_heading_unaverage);
  }

  int getHeading() {
    return mag_sensor_heading_average;
  }

  int getRawHeadingUnaverage() {
    return mag_sensor_heading_unaverage;
  }

  int getVisualHeading() {
    return visualHeading;
  }

  int getTargetHeading() {
    return targetHeading;
  }

  /*  Non-Getters/Setters  */

  void startMotors() {
    motorLeft.run(FORWARD);
    motorRight.run(FORWARD);
  }

  void reverseMotors() {
    motorLeft.run(BACKWARD);
    motorRight.run(BACKWARD);
  }

  void stopMotors() {
    motorLeft.run(RELEASE);
    motorRight.run(RELEASE);
  }

  void rotateStraight() {
    motorLeft.run(FORWARD);
    motorRight.run(FORWARD);
  }

  void rotateLeft() {
    motorLeft.run(BACKWARD);
    motorRight.run(FORWARD);
  }

  void rotateRight() {
    motorLeft.run(FORWARD);
    motorRight.run(BACKWARD);
  }

  void setRotationDirection(int rotation) {
    if (rotation == ROTATE_LEFT) {
      rotateLeft();
    } else if (rotation = ROTATE_RIGHT) {
      rotateRight();
    } else if (rotation = ROTATE_STRAIGHT) {
      rotateStraight();
    }
  }

  // BACKWARD, FORWARD
  void setMotorDirection(int direction) {
    motorLeft.run(direction);
    motorRight.run(direction);
  }

  void customConfiguration() {
    motorLeft.run(RELEASE);
    motorRight.run(FORWARD);
  }

  void rotateToHeading(int degrees) {

    
    
  }

  void setOp(Op* o) {
    currentOp = o;
  }

  void op_check() {
    if (currentOp->label.equals("reverse_a_bit")) {

      if (currentOp->endTime == 0) {
        currentOp->endTime == millis() + 500;
      }
//
//      if

      
    }
    
  }

  void evadeBorder(int side) {
    switch (side) {
      case FRONT_SIDE:
        if (currentOp->label.equals("reverse_a_bit")) {
          log("Already reversing! yielding...");
        } else {
          ReverseABit* reverseABit = new ReverseABit();
          currentOp = reverseABit;
        }
        log("Evading front!");
        break;
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


  void update() {
    //log("Updating robot!");
  }
  
  
};


BRSTbot b;

