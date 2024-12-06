#ifndef RETRACT_H
#define RETRACT_H

#include "Globals.h"
#include <Arduino.h>

void Retract() {
  // set LEDs
  digitalWrite(ledGreen, HIGH);
  digitalWrite(ledRed, LOW);
  digitalWrite(ledOrange, LOW);

  Serial.println("Entering retraction state, press the start button to begin");
  
  while (digitalRead(startButton) == HIGH) {
    // Serial.println("Waiting for start button...");
    if (digitalRead(switchOnOff) == HIGH) { // if the device is switched off at any point, break the loop
      break;
    }
    delay(100);
  }

  while (digitalRead(stopButton) == HIGH) { // continue retracting until the actuators bottom out
    userDistance = Sense();

    if (digitalRead(switchOnOff) == HIGH) { // if the device is switched off at any point, break the loop
      break;
    }

    if (userDistance > 20 && userDistance < 60 && digitalRead(checkDrawer) == HIGH) {    // check if user is in range & drawer is inserted
      // retract
      digitalWrite(extPin, LOW);
      digitalWrite(retPin, HIGH);
      // Serial.println("Safety conditions met, retracting...");

      // set LEDs
      digitalWrite(ledGreen, LOW);
      digitalWrite(ledRed, LOW);
      digitalWrite(ledOrange, HIGH);
    } else {
      // stop actuators
      digitalWrite(extPin, LOW);
      digitalWrite(retPin, LOW);
      // Serial.println("Safety conditions not met, pausing retraction...");

      // set LEDs
      digitalWrite(ledGreen, LOW);
      digitalWrite(ledRed, HIGH);
      digitalWrite(ledOrange, LOW);
    }

    delay(500);
  }
}

#endif
