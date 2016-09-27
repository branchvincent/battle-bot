void init_utilities() {
  Serial.begin(9600);
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

void log(String a) {
  Serial.println(a);
}

void log(int a) {
  Serial.println(a);
}

void log(float a) {
  Serial.println(a);
}

void log(String a, int b) {
  Serial.println(concat(a, b));
}

void log(String a, float b) {
  Serial.println(concat(a, b));
}

void log(String a, String b) {
  Serial.println(concat(a, b));
}


/*  Command Parser  */

void run_command(String, String);

void parse_command(String s) {
  int colon_index = s.indexOf(':');
  if (colon_index >= 0) {
    String key = s.substring(0, colon_index);
    String value = s.substring(colon_index+1);
    run_command(key, value);
  } else {
    log("Command not recognized");
  }
}

void parse_serial_command() {
  if (Serial.available() > 0) {
    parse_command(Serial.readString());
  }
}



 
