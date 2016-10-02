#include "PrintMode.h"
#include "Utilities.h"

void PrintMode::setPrintChar(char c) {
    log("Setting printChar to: ", String(c));
    printChar = c;
}

void PrintMode::print() {
    if (printChar == 's') {
        log("Motorspeed: ", BRSTbot::b.getSpeed());
    } else if (printChar == 'm') {
        //log("Magnetometer: ", BRSTbot::b.getRawHeading());
        // log(concat("Magnetometer: ", BRSTbot::b.getRawHeadingUnaverage()), concat(", Unaverage True Magnetometer: ", BRSTbot::b.getTrueHeadingUnaverage()));
    } else if (printChar == 't') {
        log("Target: ", BRSTbot::b.getTarget().toString());
    } else if (printChar == 'b') {
        log("Motor bias: ", BRSTbot::b.getMotorBias());
    } else if (printChar == 'h') {
        // log("Bots Heading: ", print_bots());
    }
}
