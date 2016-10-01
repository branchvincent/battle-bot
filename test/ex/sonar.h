/****************************************************************************
*																			*
*	File:		Sonar.h													    *
*																			*
*	Purpose:	This file defines the Sonar class.						    *
*																			*
****************************************************************************/

#ifndef SONAR_H
#define SONAR_H

const int ARR_SIZE = 5;     // array size for previous distances
int CURR_INDEX = 0;         // array index of current distance

/****************************************************************************
*																			*
*	Definition of Sonar class											    *
*																			*
****************************************************************************/

class Sonar {

//  Member functions

    public:
        Sonar(int tPin, int ePin) : triggerPin(tPin), echoPin(ePin)
            {for (int i = 0; i < ARR_SIZE; i++) distances[i] = 1000;}
        void init() {Serial.begin(9600);}
        long ping();
        long objDistance() {return distances[lastIndex()]};
        bool objDetected();
        long avgDistance();
        long msToMM(long microseconds) {return microseconds / 29 / 2;}
        int lastIndex()
            {int i = CURR_INDEX - 1; if (i < 0) i += ARR_SIZE; return i;}

//  Data members

    public:
        int triggerPin;
        int echoPin;
        long distances[ARR_SIZE];
};

/****************************************************************************
*																			*
*	Function:	ping    													*
*																			*
*	Purpose:	To ping the sonar sensor and return the distance of the     *
*               detected object				                                *
*																			*
****************************************************************************/

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

//  Update distances and return lastest distance

    distances[CURR_INDEX++] = distance;
    CURR_INDEX %= ARR_SIZE;
    return distance;
}

/****************************************************************************
*																			*
*	Function:	objDetected													*
*																			*
*	Purpose:	To return whether or not a close object was detected		*
*																			*
****************************************************************************/

bool Sonar::objDetected() {

    long average = avgDistance();

    if (average >= 3 && average <= 25)
        return true;
    else
        return false;
}

/****************************************************************************
*																			*
*	Function:	avgDistance													*
*																			*
*	Purpose:	To average the distance of the previous distances			*
*																			*
****************************************************************************/

long Sonar::avgDistance() {

    long sum = 0;
    for (int i = 0; i < ARR_SIZE; i++)
        sum += distances[i];
    return sum / ARR_SIZE;
}

#endif
