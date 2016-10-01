
class Point {
  public:
    float x;
    float y;

  public:
    String toString() {
      return concat("(", x) + concat(", ", y) + ")";
    }

    Point(int x_in, int y_in) {
      x = x_in;
      y = y_in;
    }

    Point() {
      x = 0;
      y = 0;
    }
};


const int ROTATE_LEFT = 1;
const int ROTATE_RIGHT = 2;
const int ROTATE_STRAIGHT = 3;
// Low Batt: 10.5
// Fresh Batt: 8.5
const float millis_per_degree = 4.25;
const int BOT_ROTATION_SPEED = 110;
const int BOT_EVASIVE_SPEED = 255;
const int rotation_base_time = 100;

// For representing operations on the robot.
class Op {

  public:
    String label;
    long timeEnd = 0;

    
    int motorDirection;
    int motorSpeed;
    
    
    int rotationDegrees;
    int rotationDirection;
    Op *nextOp;

  private:
    int rotation;

  public:

    int setRotation(int degrees) {
      rotation = degrees;
    }
  
    int getRotation() {
      return rotation;
    }

  
};

void error(String e) {
  log(e);
  log("");
  log("");
  log("");
  
}

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

    if (currentOp->label.equals("rotation")) {
      log("Rotating");

      if (currentOp->timeEnd == 0) {
        currentOp->timeEnd = millis() + rotation_base_time + currentOp->rotationDegrees * millis_per_degree;
        log(String("Setting TIME END to: ") + currentOp->timeEnd);
      } else {
        log(String("TIME END NOT EQUAL TO ZERO: ") + currentOp->timeEnd);
      }

      log(String("   ") + millis() + ",     " + currentOp->timeEnd);
      if(millis() <= currentOp->timeEnd) {
        setSpeed(BOT_ROTATION_SPEED);
        setRotationDirection(currentOp->rotationDirection);
        
      } else {
        startMotors();

      }

      
    } else if (currentOp->label.equals("edge_escape")) {
      log("Operation: Edge Escape");

      if (currentOp->timeEnd == 0) {
        currentOp->timeEnd = millis() + 500;
      }

      if (millis() <= currentOp->timeEnd) {
        setMotorDirection(currentOp->motorDirection);
        setSpeed(currentOp->motorSpeed);
      } else {
//        reverseMotors();

      }
      
    } else if (currentOp->label.equals("reverse_a_bit")) {
      log(String("Operation: Reversing a bit.  ") + millis() + "       " + currentOp->timeEnd  );
      log("Next Op Label: ", currentOp->nextOp->label);
      if (currentOp->timeEnd == 0) {
        currentOp->timeEnd = millis() + 500;
      }

      if (millis() <= currentOp->timeEnd) {
        setMotorDirection(BACKWARD);
        setSpeed(BOT_EVASIVE_SPEED);
      } else {
          setMotorDirection(FORWARD);
//        reverseMotors();

      }
      

      
    }

    if (!currentOp->label.equals("")) {

      if(millis() <= currentOp->timeEnd) {
        // Operation code common to all.
        
      } else {
        // Stop operation code common to all.
        Op* next;
        if (currentOp->nextOp != NULL) {
          next = currentOp->nextOp;
          log("Setting next Operation!", next->label);

          
        } // Else, next is just an empty op.
        currentOp = next;
      }


    }
    
  }


  void update() {
    //log("Updating robot!");
  }
  
  
};


BRSTbot b;

