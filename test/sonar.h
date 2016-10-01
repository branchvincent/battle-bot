// #ifndef SONAR_H
// #define SONAR_H

const int SIZE = 5;
int CURR_INDEX = 0;

//  Class definition

class Sonar {

//  Member functions

    public:
        Sonar(int tPin, int ePin) : triggerPin(tPin), echoPin(ePin)
            {for (int i = 0; i < SIZE; i++) distances[i] = 1000;}
        void init() {Serial.begin(9600);}
        long ping();
        bool objDetected();
        long avgDistance();
        // long distance() {return distances[getLastIndex()];}
    private:
        long msToMM(long microseconds) {return microseconds / 29 / 2;}
        // int getLastIndex() {int i = CURR_INDEX - 1;
        //     if (i < 0) i = SIZE; return i;}

//  Data members

    public:
        int triggerPin;
        int echoPin;
        long distances[SIZE];
};

// Function definitions

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
    long distance = msToMM(duration);
//  Update distances

    distances[CURR_INDEX++] = distance;
    CURR_INDEX %= SIZE;
    return distance;
}

bool Sonar::objDetected() {

    long average = avgDistance();

    if (average >= 3 && average <= 25)
        return true;
    else
        return false;
}

long Sonar::avgDistance() {

    long sum = 0;
    for (int i = 0; i < SIZE; i++)
        sum += distances[i];
    return sum / SIZE;
}

// #endif
