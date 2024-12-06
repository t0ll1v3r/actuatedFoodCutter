#ifndef OFFSTATE_H
#define OFFSTATE_H

#include "Globals.h"
#include "FullRetract.h"

#include <Arduino.h>

void OffState() {
  FullRetract();  // fully retract the arduinos

  Serial.println("Device is switched off");
  
  // set LEDs
  digitalWrite(ledGreen, LOW);
  digitalWrite(ledRed, LOW);
  digitalWrite(ledOrange, LOW);

  while (digitalRead(switchOnOff) == HIGH) {  // do nothing until the switch is turned back on
    delay(100);
  }
}

#endif
