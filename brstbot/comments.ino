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


