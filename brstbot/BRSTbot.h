
class Point {
  public:
    float x;
    float y;

  public:
    String toString() {
      return concat("(", x) + concat(", ", y) + ")";
    }
};

class BRSTbot {
  private:
    int speed;
    float motorBias;
    AF_DCMotor motorLeft;
    AF_DCMotor motorRight;
    Point target;
    const int MOTOR_LOW_SPEED;
    const int MOTOR_HIGH_SPEED;

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
  
  
  
};
