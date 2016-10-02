#include "PrintMode.h"
#include "Utilities.h"
#include "BRSTbot.h"

#include "Globals.cpp"
// using namespace globals;

// extern BRSTbot b;

void PrintMode::setPrintChar(char c) {
    log("Setting printChar to: ", String(c));
    printChar = c;
}

void PrintMode::print() {
    if (printChar == 's') {
        log("Motorspeed: ", b.getSpeed());
    } else if (printChar == 'm') {
        //log("Magnetometer: ", b.getRawHeading());
        // log(concat("Magnetometer: ", b.getRawHeadingUnaverage()), concat(", Unaverage True Magnetometer: ", b.getTrueHeadingUnaverage()));
    } else if (printChar == 't') {
//        log("Target: ", b.getTarget().toString());
    } else if (printChar == 'b') {
        log("Motor bias: ", b.getMotorBias());
    } else if (printChar == 'h') {
        // log("Bots Heading: ", print_bots());
    }
}
