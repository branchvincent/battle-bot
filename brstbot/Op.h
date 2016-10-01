/****************************************************************************
*																			*
*	Definition of Op class											        *
*																			*
****************************************************************************/

class Op {

  public:
    String label;
    long timeEnd = 0;

    Op *nextOp;

};

/****************************************************************************
*																			*
*	Definition of Rotation class											*
*																			*
****************************************************************************/

class Rotation : public Op {

  public:
    int rotationDegrees;
    int rotationDirection;

    Rotation() {
      label = "rotation";
    }

};

/****************************************************************************
*																			*
*	Definition of Sonar class											    *
*																			*
****************************************************************************/

class ReverseABit : public Op {

  public:
    ReverseABit() {
      label = "reverse_a_bit";
    }
};
