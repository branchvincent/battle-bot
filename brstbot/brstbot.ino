#include <AFMotor.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_HMC5883_U.h>
#include <SPI.h>
#include "utilities.h"
#include "magnetometer.h"
#include "ChinaBee.h"
#include "BRSTbot.h"

const int starting_quadrant = 3;

/* 
 * Requires installation of the following libraries:
 * 
 * https://github.com/adafruit/Adafruit-Motor-Shield-library
 * https://github.com/adafruit/Adafruit_HMC5883_Unified
 * https://github.com/adafruit/Adafruit_Sensor
 * 
 */

/*
 * TODO:
 * 
 *   Print command.
 * 
 */

BRSTbot b;
String print_mode = "none";

bool print_append_mode = false;
//32+360=392

String print_bots();

class PrintMode {

  private:
    char printChar;
    bool inAppendMode;

  public:

    void setPrintChar(char c) {
      log("Setting printChar to: ", String(c));
      printChar = c;
    }

    void print() {
      if (printChar == 's') {
        log("Motorspeed: ", b.getSpeed());
      } else if (printChar == 'm') {
        //log("Magnetometer: ", b.getRawHeading());
        log(concat("Magnetometer: ", b.getRawHeadingUnaverage()), concat(", Unaverage True Magnetometer: ", b.getTrueHeadingUnaverage()));
      } else if (printChar == 't') {
        log("Target: ", b.getTarget().toString());
      } else if (printChar == 'b') {
        log("Motor bias: ", b.getMotorBias());
      } else if (printChar == 'h') {
        log("Bots Heading: ", print_bots());
      }
    }
    
  
};

PrintMode p;

void print_command() {
  
}

void run_command(String key, String value) {
  if (key.equals("speed") || key.equals("s")) {   // e.g., user entered  "speed:37"  in serial monitor
    
    b.setSpeed(value.toInt());
    log("Changing speed to: ", value);
  
  } else if (key.equals("bias") || key.equals("b")) {

    b.setMotorBias(value.toFloat());
    log("Setting bias to: ", value);
    
  } else if (key.equals("dir") || key.equals("d")) {
    
    if (value.equals("forward") || value.equals("f")) { b.startMotors(); } 
    else if (value.equals("back")) { b.reverseMotors(); }
    else if (value.equals("stop")) { b.stopMotors(); }
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
    Op rotate;
    rotate.label = "rotation";
    rotate.setRotation(value.toInt());
    b.setOp(rotate);
    log("Rotating to Heading: ", value);
  
    
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

ChinaBee bee;

void setup() {
  init_utilities();
  init_magsensor();

  b.setMotorBias(0.88);
  //b.setSpeed(200);
  //b.startMotors();
  
  log("Hello World!");

  bee.init(48, 49);
  


}


// Fastest Loop Time:
// 6240 microseconds
// With magnetometer: 22880 microseconds.

// Reguar (9600): 22880
// Baud (): 2200



// Bottom-Right: (85.00,18.00)
// Top-Right: (87.00,196.00)
// Top-Left: (265.00,194.00)
// Bottom-Left: (260.00,14.00)

int x_true(float x) {
  return -x+260;
}

int y_true(float y) {
  return y-14;
}

const int bot_position_buffer_size = 5;

class Bot {
  private:
    Point position;
    Point lastPosition;
    int visualHeading;
    Point position_buffer[bot_position_buffer_size];
    int position_kickout_index = 0;

  public:

    Point getLastPosition() {
      return lastPosition;
    }
  
    Point getPosition() {
       return position;
    }

    void setPosition(Point p) {

      if ((p.x != lastPosition.x) || (p.y != lastPosition.y)) {

        Point displacementVector((int)(p.x - lastPosition.x), (int)(p.y - lastPosition.y));
  
        // Update estimated heading.
        float headingRadians = atan2(displacementVector.y, displacementVector.x);
        float headingDegrees = headingRadians * 180/M_PI; ;
        visualHeading = headingDegrees;
        
        lastPosition = position;
        position = p;

        log("New Position for Bot: ", p.toString());
        log("New Heading for Bot: ", headingDegrees);
        
      }
    }

    int getVisualHeading() {
      return visualHeading;
    }
};

Bot bots[4];

String print_bots() {
  String result = "";
  for (int i = 0; i < 4; i++) {
    result += bots[i].getVisualHeading() + String(", ");
  }
  return result;
}



  //update_loop_timer();

  
void loop() {

  parse_serial_command();
  update_mag_running();
  p.print();


  // This must be called every loop
  bee.update();
  
  for (int i=0; i<bee.get_num_teams(); i++) {
    team_status_t* stat = bee.get_status(i);
    if (stat->haveFound || true) {
      
      
//      Serial.print("(");
//      Serial.print(x_true(stat->x));
//      Serial.print(",");
//      Serial.print(y_true(stat->y));
//      Serial.print(")   ");

      if (i == 3) {
        Point p = Point(x_true(stat->x),y_true(stat->y));
        //log("Updating bot 3!  ", p.toString());
        bots[i].setPosition(p);
      }
    }
  }
//  Serial.println();
  
}





