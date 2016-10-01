// For representing operations on the robot.
class Op {

  public:
    String label;
    long timeEnd = 0;
    
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

class ReverseABit : public Op {

  public:
    ReverseABit() {
      label = "reverse_a_bit";
    }

  
};










