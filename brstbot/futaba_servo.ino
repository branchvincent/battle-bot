#include <Servo.h> 
Servo myservo;

void setup() {
  // put your setup code here, to run once:
  myservo.attach(9);
  // connect servo to pin 9
}

void loop() {
  // put your main code here, to run repeatedly:
 myservo.write(170);
  delay(2000);
  //probably write position for the servo
  myservo.write(10);
  delay(2000);
}
