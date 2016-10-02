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
        LineSensor(int pt);
        bool detected();
    private:
        int port;
};

#endif
