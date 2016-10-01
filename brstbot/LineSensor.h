/****************************************************************************
*																			*
*	File:		LineSensor.h											    *
*																			*
*	Purpose:	This file defines the LineSensor class.						*
*																			*
****************************************************************************/

#ifndef LINESENSOR_H
#define LINESENSOR_H

/****************************************************************************
*																			*
*	Definition of LineSensor class											*
*																			*
****************************************************************************/

class LineSensor {
    public:
        LineSensor(int pt) : port(pt) {}
        bool detected() {return if digitalRead(port) == 0;}
    private:
        int port;
};

#endif
