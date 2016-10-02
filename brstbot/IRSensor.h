/****************************************************************************
*																			*
*	File:		IRSensor.h											    *
*																			*
*	Purpose:	This file defines the IRSensor class.						*
*																			*
****************************************************************************/

#ifndef IRSENSOR_H
#define IRSENSOR_H

/****************************************************************************
*																			*
*	Definition of IRSensor class											*
*																			*
****************************************************************************/

class IRSensor {
    public:
        IRSensor(int pt);
        bool detected();
    private:
        int port;
};

#endif
