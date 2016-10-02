#ifndef UTILITIES_H
#define UTILITIES_H

#include <WString.h>
#include "BRSTbot.h"
#include "PrintMode.h"

// #include <SoftwareSerial.h>
// #include "PrintMode.h"
// #include "Arduino.h"
// #include "BRSTbot.h"
//class BRSTbot;

//  Prototypes

// void init_utilities();
void run_command(String key, String value, BRSTbot& b, PrintMode& p);
String concat(String a, int b);
String concat(String a, float b);
String concat(String a, String b);
void print_log_counter();
void log(String a);
void log(int a);
void log(long unsigned int a);
void log(float a);
void log(String a, int b);
void log(String a, float b);
void log(String a, String b);
void error(String e);
String* string_split(String s, char delim);
void run_command(String, String, BRSTbot& b, PrintMode& p);
void parse_command(String s, BRSTbot& b, PrintMode& p);
void parse_serial_command(BRSTbot& b, PrintMode& p);
void update_loop_timer();
int running_average(int buffer[], int buffer_size, int kickout_index, int new_value);
int x_true(float x);
int y_true(float y);

#endif
