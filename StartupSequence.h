#ifndef STARTUPSEQUENCE_H
#define STARTUPSEQUENCE_H

#include "Globals.h"
//#include "Sense/Sense.h"
#include "FullExtend.h"

#include <Arduino.h>

bool StartupSequence() {
    if (digitalRead(switchOnOff) == HIGH) {
        return true; // indicate to break out of the loop
    }
    
    if (firstTime == true) {  // startup sequence to fully extend the actuators, will only run the first time the switch is turned on
      FullExtend();
    }
    
    return false;
}

#endif
