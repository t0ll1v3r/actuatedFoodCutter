#ifndef FULLRETRACT_H
#define FULLRETRACT_H

#include "Globals.h"
#include "Sense.h"

#include <Arduino.h>

void FullRetract() {
  Serial.println("Executing Full Retraction");

  while (digitalRead(stopButton) == HIGH) {
    userDistance = Sense();

    if (userDistance > 20 && userDistance < 60 && digitalRead(checkDrawer) == HIGH) {    // check if user is in range & drawer is inserted
      // retract actuators
      digitalWrite(extPin, LOW);
      digitalWrite(retPin, HIGH);
      // Serial.println("Safety conditions met, retracting...");

      // set LEDs
      digitalWrite(ledGreen, LOW);
      digitalWrite(ledRed, LOW);
      digitalWrite(ledOrange, HIGH);
    } else {
      // stop
      digitalWrite(extPin, LOW);
      digitalWrite(retPin, LOW);
      Serial.println("Safety conditions not met, pausing retraction...");

      // set LEDs
      digitalWrite(ledGreen, LOW);
      digitalWrite(ledRed, HIGH);
      digitalWrite(ledOrange, LOW);
    }

    delay(100);

  }

  firstTime = true; // device is now switched off, so when its switched back on we want the startup sequence to run again

}

#endif
