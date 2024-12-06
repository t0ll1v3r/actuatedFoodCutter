#ifndef SENSE_H
#define SENSE_H

#include "Globals.h"
#include <Arduino.h>

double Sense() {
  double val = analogRead(A1);

  // function to convert the analog input to distance (cm)
  double V = (val*5)/1024;
  double distance = 59.4611*pow(V, -1.03199);

  // Serial.print(distance);
  // Serial.println(" cm");

  return distance;
}

#endif
