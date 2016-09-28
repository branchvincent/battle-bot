void init_utilities() {
  //Serial.begin(9600);
  Serial.begin(115200);
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


/*  Loop Timer  */

unsigned long loop_time;
unsigned long loop_last_time;

update_loop_timer() {
  loop_time = micros();
  log(loop_time - loop_last_time);
  loop_last_time = loop_time;

}


