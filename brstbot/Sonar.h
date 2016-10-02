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
        Sonar(int tPin, int ePin);
        void init();
        long ping();
        long objDistance();
        bool objDetected();
        long avgDistance();
    private:
        long msToMM(long microseconds);
        int lastIndex();

//  Data members

    public:
        int triggerPin;
        int echoPin;
        long distances[ARR_SIZE];
};

#endif
