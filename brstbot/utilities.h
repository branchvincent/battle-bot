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




