#ifndef SONAR_H
#define SONAR_H

class Sonar {

//  Member functions

    public:
        Sonar(int tPin, int ePin) : triggerPin(tPin), echoPin(ePin) {}
        void init() {Serial.begin(11520);}
        long ping();
    private:
        long msToMM(long microseconds) {
          return microseconds / 2.9 / 2;
        }

//  Data members

    public:
        int triggerPin;
        int echoPin;
};

long Sonar::ping() {

//  Give a short LOW pulse to ensure a clean HIGH pulse

    pinMode(triggerPin, OUTPUT);
    digitalWrite(triggerPin, LOW);
    delayMicroseconds(2);

//  PING is triggered by a HIGH pulse of 2 or more microseconds

    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(5);
    digitalWrite(triggerPin, LOW);

//  Read signal from PING

    pinMode(echoPin, INPUT);
    long duration = pulseIn(echoPin, HIGH);
    return msToMM(duration);
}

#endif
