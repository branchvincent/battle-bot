#include "ex/sonar.h"
#include <SPI.h>

Sonar snr(30, 32);

void setup() {
    snr.init();
    Serial.println("Starting...");
}

void loop() {
    long distance = snr.ping();
    // Serial.println("Distance = " + distance + " cm");
    // Serial.println("\tAvg distance = " + snr.avgDistance() + " cm");
    Serial.println(snr.avgDistance());
    if (snr.objDetected())
        Serial.println("\tObject detected!!!");
}
