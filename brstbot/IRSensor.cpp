/****************************************************************************
*																			*
*	File:		IRSensor.cpp											    *
*																			*
*	Purpose:	This file defines the IRSensor class.						*
*																			*
****************************************************************************/

#include "IRSensor.h"
#include "Arduino.h"

IRSensor::IRSensor(int pt) : port(pt) {}

bool IRSensor::detected() {return digitalRead(port) == 0;}
