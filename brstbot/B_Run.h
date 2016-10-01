#ifndef B_RUN_H
#define B_RUN_H

#include "Globals.h"

using namespace globals;

PrintMode p;

void run_command(String key, String value) {
  if (key.equals("speed") || key.equals("s")) {   // e.g., user entered  "speed:37"  in serial monitor

    b.setSpeed(value.toInt());
    log("Changing speed to: ", value);

  } else if (key.equals("bias") || key.equals("b")) {

    b.setMotorBias(value.toFloat());
    log("Setting bias to: ", value);

  } else if (key.equals("dir") || key.equals("d")) {

    if (value.equals("forward") || value.equals("f")) { b.startMotors(); }
    else if (value.equals("back") || value.equals("r") || value.equals("b")) { b.reverseMotors(); }
    else if (value.equals("stop") || value.equals("s")) { b.stopMotors(); }
    log("Setting motor direction to: ", value);

  } else if (key.equals("rotate") || key.equals("r")) {

    if (value.equals("left") || value.equals("l")) { b.rotateLeft(); }
    else if (value.equals("right") || value.equals("r")) { b.rotateRight(); }
    else if (value.equals("straight") || value.equals("s")) { b.rotateStraight(); }
    log("Setting bot body rotation to: ", value);

  } else if (key.equals("target") || key.equals("t")) {

    String* coords = string_split(value, ',');
    log("Prefix: ", coords[0] );
    int x = coords[0].toInt();
    int y = coords[1].toInt();
    log("Setting x target to: ", x);
    log("Setting y target to: ", y);
    b.setTarget(x, y);

  } else if (key.equals("heading") || key.equals("h")) {

    //b.rotateToHeading(value.toInt());
//    Op rotate;
//    rotate.label = "rotation";
//    rotate.setRotation(value.toInt());
//    b.setOp(rotate);
//    log("Rotating to Heading: ", value);
//

  } else if (key.equals("print") || key.equals("p")) {

    char printchar = value.charAt(0);
    p.setPrintChar(printchar);
    log("Setting print mode to: ", String(printchar));

  } else if (key.equals("custom") || key.equals("c")) {

    b.customConfiguration();
    log("Running custom motor configuration now...");

  } else {

    log("Command '", concat(key, "' not recognized."));

  }
}

#endif
