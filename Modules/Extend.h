#ifndef EXTEND_H
#define EXTEND_H

#include "Globals.h"
#include "Sense.h"

#include <Arduino.h>

void Extend() {
  digitalWrite(ledGreen, HIGH);
  digitalWrite(ledRed, LOW);
  digitalWrite(ledOrange, LOW);

  Serial.println("Entering extention state");

  unsigned long extTime = 0;
  unsigned long lastTime = millis();  // get the initial time, prior to the extention beginning

  while (extTime < timeLimit) { // continue extending until the total time spent actively extending the actuators reaches the time limit
    userDistance = Sense(); // check the distance the user is from the device each time the loop runs
    unsigned long currTime = millis();  // get the current time in each loop iteration

    if (digitalRead(switchOnOff) == HIGH) { // if the device is switched off at any point, break the loop
      break;
    }
    
    if (userDistance > 20 && userDistance < 60) {    // check if user is in range
      // set LEDs
      digitalWrite(ledGreen, LOW);
      digitalWrite(ledRed, LOW);
      digitalWrite(ledOrange, HIGH);

      // extend
      digitalWrite(extPin, HIGH);
      digitalWrite(retPin, LOW);
      // Serial.println("Safety conditions met, extending...");

      extTime += (currTime - lastTime); // the time spent actively extending
    } else {    // user outside of range, pause the extension
      digitalWrite(extPin, LOW);
      digitalWrite(retPin, LOW);
      // Serial.println("Safety conditions not met, pausing extension...");

      // set LEDs
      digitalWrite(ledGreen, LOW);
      digitalWrite(ledRed, HIGH);
      digitalWrite(ledOrange, LOW);
    }

    lastTime = currTime; // set lastTime to the previous loop's time

    delay(500);
  }
  // stop actuators
  digitalWrite(extPin, LOW);
  digitalWrite(retPin, LOW);

  Serial.print(timeLimit/1000);
  Serial.println(" seconds elapsed, stopping extension");
}

#endif
