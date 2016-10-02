/*
 * Requires installation of the following libraries:
 *
 * https://github.com/adafruit/Adafruit-Motor-Shield-library
 * https://github.com/adafruit/Adafruit_HMC5883_Unified
 * https://github.com/adafruit/Adafruit_Sensor
 *
 */

//      Op forwardEscape;
//      forwardEscape.label = "edge_escape";
//      forwardEscape.motorDirection = FORWARD;
//      forwardEscape.motorSpeed = 200;
//      b.setOp(forwardEscape);


//      Op *rotate = new Op();
//      rotate->label = "rotation";
//      rotate->rotationDirection = ROTATE_LEFT;
//      rotate->rotationDegrees = 180;
//
//      //reverseABit->nextOp = rotate;
//


//  Op rotateAmount;
//  rotateAmount.label = "rotation";
//  rotateAmount.rotationDegrees = 90;
//  rotateAmount.rotationDirection = ROTATE_LEFT;
//  b.setOp(rotateAmount);





//  String a = "   ";
//  for (int i = 44; i <= 47; i++) {
//    int sensorPin = i;
//    int sensorValue = digitalRead(sensorPin);
//    a += String("Pin ")+ String(sensorPin) + String(": ") + sensorValue + String("     ");
//
//  }
  //log(a);





// Left
// Black -> Top
// Red -> Bottom

// Right
// Black -> Top
// Red -> Bottom



//
//AF_DCMotor motorLeft(1, MOTOR12_64KHZ);  // Initialize the left motor.
//AF_DCMotor motorRight(2, MOTOR12_64KHZ);  // Initialize the left motor.
//
//const float MOTOR_BIAS_LR = 0.757;
//






/*
 * Calibration Data
Speed  Bias
200, 0.757


 *
 */





//class Bot {
//  public:
//    int speed;
//    float motorBias;
//}

//class BRSTbot {
//
//  private:
//    int speed;
//    float motorBias;
//
//  public:
//
//    void setSpeed(int speed) {
//      this.speed = speed;
//    }
//
//}



//  Serial.begin(9600);
//
//  //String prefix = ;
//  log("Motor bias set to: ", MOTOR_BIAS_LR);
//
//  Serial.println("Hello World!");
//
//  Serial.println("Motor test!");
//
//  motorsSetSpeed(200);
//
//
//
//  motorLeft.run(FORWARD);
//  motorRight.run(FORWARD);




//void motorsSetSpeed(int speed) {
//  log("Motor speed set to: ", speed);
//  motorLeft.setSpeed(speed * MOTOR_BIAS_LR);
//  motorRight.setSpeed(speed);
//}




/*
 * String concatenation example:
 *   String hello = "Setting motor speed to: ";
 *   String world = hello + speed;
 *   Serial.println(world);
 *
 */


 // Fastest Loop Time:
// 6240 microseconds
// With magnetometer: 22880 microseconds.

// Reguar (9600): 22880
// Baud (): 2200



// Bottom-Right: (85.00,18.00)
// Top-Right: (87.00,196.00)
// Top-Left: (265.00,194.00)
// Bottom-Left: (260.00,14.00)

//    if (currentOp->label.equals("rotation")) {
//      log("Rotating");
//
//      if (currentOp->timeEnd == 0) {
//        currentOp->timeEnd = millis() + rotation_base_time + currentOp->rotationDegrees * ms_per_degree;
//        log(String("Setting TIME END to: ") + currentOp->timeEnd);
//      } else {
//        log(String("TIME END NOT EQUAL TO ZERO: ") + currentOp->timeEnd);
//      }
//
//      log(String("   ") + millis() + ",     " + currentOp->timeEnd);
//      if(millis() <= currentOp->timeEnd) {
//        setSpeed(BOT_ROTATION_SPEED);
//        setRotationDirection(currentOp->rotationDirection);
//
//      } else {
//        startMotors();
//
//      }
//
//
//    } else if (currentOp->label.equals("edge_escape")) {
//      log("Operation: Edge Escape");
//
//      if (currentOp->timeEnd == 0) {
//        currentOp->timeEnd = millis() + 500;
//      }
//
//      if (millis() <= currentOp->timeEnd) {
//        setMotorDirection(currentOp->motorDirection);
//        setSpeed(currentOp->motorSpeed);
//      } else {
////        reverseMotors();
//
//      }
//
//    } else if (currentOp->label.equals("reverse_a_bit")) {
//      log(String("Operation: Reversing a bit.  ") + millis() + "       " + currentOp->timeEnd  );
//      log("Next Op Label: ", currentOp->nextOp->label);
//      if (currentOp->timeEnd == 0) {
//        currentOp->timeEnd = millis() + 500;
//      }
//
//      if (millis() <= currentOp->timeEnd) {
//        setMotorDirection(BACKWARD);
//        setSpeed(BOT_EVASIVE_SPEED);
//      } else {
//          setMotorDirection(FORWARD);
////        reverseMotors();
//
//      }
//
//
//
//    }
//
//    if (!currentOp->label.equals("")) {
//
//      if(millis() <= currentOp->timeEnd) {
//        // Operation code common to all.
//
//      } else {
//        // Stop operation code common to all.
//        Op* next;
//        if (currentOp->nextOp != NULL) {
//          next = currentOp->nextOp;
//          log("Setting next Operation!", next->label);
//
//
//        } // Else, next is just an empty op.
//        currentOp = next;
//      }
//
//
//    }
