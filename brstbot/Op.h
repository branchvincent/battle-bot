// For representing operations on the robot.
class Op {

  public:
    String label;
    long endTime = 0;
    
    Op *nextOp;
  
};


class Rotation : public Op {

  public:
    int rotationDegrees;
    int rotationDirection;

    Rotation() {
      label = "rotation";
    }
  
};

class Translation : public Op {
  
};

class ReverseABit : public Translation {

  public:
    ReverseABit() {
      label = "reverse_a_bit";
      endTime = millis() + 500;
    }

  
};










