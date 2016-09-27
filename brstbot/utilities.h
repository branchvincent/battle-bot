void init_utilities() {
  Serial.begin(9600);
}

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
