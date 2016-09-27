

String concat(String a, int b) {
  return a + b;
}

String concat(String a, float b) {
  return a + b;
}

void log(String a, int b) {
  Serial.println(concat(a, b));
}

void log(String a, float b) {
  Serial.println(concat(a, b));
}
