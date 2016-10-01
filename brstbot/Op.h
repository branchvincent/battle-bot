// For representing operations on the robot.
class Op {

  public:
    String label;
    long endTime = 0;
    
    Op *nextOp;

    virtual bool execute()=0;
  
};


class Rotation : public Op {

  public:
    int rotationDegrees;
    int rotationDirection;

    Rotation() {
      label = "rotation";
    }

    bool execute() {
      
    }
  
};

class Translation : public Op {
  bool execute() {
    
  }
};

class ReverseABit : public Translation {

  public:
    ReverseABit() {
      label = "reverse_a_bit";
      endTime = millis() + 500;
    }

    bool execute() {
      
    }

    
  
};










