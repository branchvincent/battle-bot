#include <SoftwareSerial.h>
#include "PrintMode.h"
#include "Arduino.h"
// #include "BRSTbot.h"
#include "Utilities.h"
//  Defintions

#include "Globals.h"
using namespace globals;

// void init_utilities() {
//   //Serial.begin(9600);
//   // Serial.begin(115200);
// }

void run_command(String key, String value, BRSTbot& b, PrintMode& p) {
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

/*  Logging Commands  */

String concat(String a, int b) {
  return a + b;
}

String concat(String a, float b) {
  return a + b;
}

String concat(String a, String b) {
  return a + b;
}


int log_counter = 100;

void print_log_counter() {
  log_counter++;
  Serial.print(log_counter);
  Serial.print(": ");
  if (log_counter >= 999) {
    log_counter = 100;
  }
}

void log(String a) {
  print_log_counter();
  Serial.println(a);
}

void log(int a) {
  log(String(a));
}

void log(long unsigned int a) {
  log(String(a));
}

void log(float a) {
  log(String(a));
}

void log(String a, int b) {
  log(concat(a, b));
}

void log(String a, float b) {
  log(concat(a, b));
}

void log(String a, String b) {
  log(concat(a, b));
}

void error(String e) {
  log(e);
  log("");
  log("");
  log("");

}


/*  String Split  */

// Returns an array of size two of the two strings separated by the first occurence of the delim.
String* string_split(String s, char delim) {
  log("Received input ", s);
  int delim_index = s.indexOf(delim);
  log("Delimeter found at index: ", delim_index);
  if (delim_index >= 0) {
    String left = s.substring(0, delim_index);
    log("Result 1: ", left);
    String right = s.substring(delim_index+1);
    log("Result 2: ", right);
    String* result = new String[2];
    result[0] = left;
    result[1] = right;
    return result;
  } else {
    log("Command not recognized");
    return {};
  }
}


/*  Command Parser  */

void parse_command(String s, BRSTbot& b, PrintMode& p) {
  int colon_index = s.indexOf(':');
  if (colon_index >= 0) {
    String key = s.substring(0, colon_index);
    String value = s.substring(colon_index+1);
    run_command(key, value, b, p);
  } else {
    log("Command not recognized");
  }
}

void parse_serial_command(BRSTbot& b, PrintMode& p) {
  if (Serial.available() > 0) {
    parse_command(Serial.readString(), b, p);
  }
}


/*  Loop Timer  */

unsigned long loop_time;
unsigned long loop_last_time;

void update_loop_timer() {
  loop_time = micros();
  log(loop_time - loop_last_time);
  loop_last_time = loop_time;

}


/*  Running Average  */

int running_average(int buffer[], int buffer_size, int kickout_index, int new_value) {
  buffer[kickout_index] = new_value;
  kickout_index++;
  kickout_index %= buffer_size;
  int sum = 0;
  for (int i = 0; i < buffer_size; i++) {
    sum += buffer[i];
  }
  return sum / buffer_size;
}


/*  Calibrate XY  */

int x_true(float x) {
  return -x+260;
}

int y_true(float y) {
  return y-14;
}

/*  String  */
String S(String s) {
  return s;
}

