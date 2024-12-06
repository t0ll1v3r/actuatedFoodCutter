#ifndef PAUSE_H
#define PAUSE_H

#include "Globals.h"
#include <Arduino.h>

void Pause() {
  Serial.println("Pausing...");

  digitalWrite(extPin, LOW);
  digitalWrite(retPin, LOW);

  // set LEDs
  digitalWrite(ledGreen, HIGH);
  digitalWrite(ledRed, LOW);
  digitalWrite(ledOrange, LOW);
}

#endif
