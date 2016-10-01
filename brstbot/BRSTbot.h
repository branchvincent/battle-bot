
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


// For representing operations on the robot.
class Op {

  public:
    String label;
    int motorDirection;
    int motorSpeed;
    long timeEnd;

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
    Op currentOp;
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

  void setOp(Op o) {
    currentOp = o;
  }

  void op_check() {

    if (!currentOp.label.equals("")) {
      
      log("Performing operation: ", currentOp.label);
    }
    

    if (currentOp.label.equals("rotation")) {
      log("Rotating");
      if(getTrueHeadingUnaverage() < currentOp.getRotation()) {
        rotateLeft();
      } else {
        stopMotors();
        Op empty;
        currentOp = empty;
      }
    } else if (currentOp.label.equals("edge_escape")) {
      log("Operation: Edge Escape");

      if (millis() <= currentOp.timeEnd) {
        setMotorDirection(currentOp.motorDirection);
        setSpeed(currentOp.motorSpeed);
      } else {
        reverseMotors();
        Op empty;
        currentOp = empty;
      }
    }
    
  }


  void update() {
    //log("Updating robot!");
  }
  
  
};


BRSTbot b;

