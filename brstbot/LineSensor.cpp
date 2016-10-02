/****************************************************************************
*																			*
*	File:		LineSensor.cpp											    *
*																			*
*	Purpose:	This file defines the LineSensor class.						*
*																			*
****************************************************************************/

#include "LineSensor.h"
#include "Arduino.h"

LineSensor::LineSensor(int pt) : port(pt) {}

bool LineSensor::detected() {return digitalRead(port) == 0;}
