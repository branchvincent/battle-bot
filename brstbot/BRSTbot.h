
class BRSTbot {
  private:
    int speed;
    AF_DCMotor motorLeft;
    AF_DCMotor motorRight;

  public:

  BRSTbot() : motorLeft(1, MOTOR12_64KHZ), motorRight(2, MOTOR12_64KHZ) {

  }

  /* Getters and Setters */
  
  void setSpeed(int s) {
    speed = s;
  }

  int getSpeed() {
    return speed;
  }

  /*  Non-Getters/Setters  */

  void startMotors() {
    
  }

  void stopMotors() {
    
  }
  
  
};
