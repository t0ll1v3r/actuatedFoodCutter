#ifndef FULLEXTEND_H
#define FULLEXTEND_H

#include "Globals.h"
#include <Arduino.h>

void FullExtend() {
  Serial.println("Executing full extention");
  unsigned long extTime = 0;
  unsigned long lastTime = millis();

  while (extTime < timeLimit) { // continue extending until the total time spent actively extending the actuators reaches the time limit
    if (digitalRead(switchOnOff) == HIGH) { // if the device is switched off at any point, break the loop
      break;
    }
    
    unsigned long currTime = millis();
    
    // set LEDs
    digitalWrite(ledGreen, LOW);
    digitalWrite(ledRed, LOW);
    digitalWrite(ledOrange, HIGH);

    // extend
    digitalWrite(extPin, HIGH);
    digitalWrite(retPin, LOW);

    extTime += (currTime - lastTime);

    lastTime = currTime;
    delay(500);
  }

  firstTime = false;  // ensure startup processes do not occur again

  Serial.print(timeLimit/1000);
  Serial.println(" seconds elapsed, full extension complete.");
}

#endif
