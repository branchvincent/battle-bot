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


class Rotation : public Op {
  
};

class ReverseABit : public Op {
  
};










