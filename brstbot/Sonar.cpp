/****************************************************************************
*																			*
*	File:		Sonar.h													    *
*																			*
*	Purpose:	This file defines the Sonar class.						    *
*																			*
****************************************************************************/

#include "Sonar.h"
#include "Arduino.h"

Sonar::Sonar(int tPin, int ePin) : triggerPin(tPin), echoPin(ePin), currIndex(0) {
    for (int i = 0; i < ARR_SIZE; i++)
        distances[i] = 1000;
}

// void Sonar::init() {Serial.begin(9600);}

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

    distances[currIndex++] = distance;
    currIndex %= ARR_SIZE;
    return distance;
}

long Sonar::objDistance() {
    return distances[lastIndex()];
}

bool Sonar::objDetected() {
    long average = avgDistance();

    if (average >= 3 && average <= 35)
        return true;
    else
        return false;
}

long Sonar::avgDistance() {
    long sum = 0;
    for (int i = 0; i < ARR_SIZE; i++)
        sum += distances[i];
    return sum / ARR_SIZE;
}

long Sonar::msToMM(long microseconds) {return microseconds / 29 / 2;}

int Sonar::lastIndex() {
    int i = currIndex - 1;
    if (i < 0)
        i += ARR_SIZE;
    return i;
}
