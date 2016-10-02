/****************************************************************************
*																			*
*	File:		LineSensor.cpp											    *
*																			*
*	Purpose:	This file defines the LineSensor class.						*
*																			*
****************************************************************************/

#include "LineSensor.h"

LineSensor::LineSensor(int pt) : port(pt) {}

bool LineSensor::detected() {return if digitalRead(port) == 0;}
