// include functions
#include "Modules/Globals.h"
#include "Modules/Extend.h"
#include "Modules/Retract.h"
#include "Modules/Sense.h"
#include "Modules/FullExtend.h"
#include "Modules/FullRetract.h"
#include "Modules/OffState.h"
// #include "Modules/Pause.h"

// define pins
const int retPin = 9;         // when high, retract
const int extPin = 12;        // when high, extend

const int enable1 = 10;       // enable pin for 1st actuator -> pin 10
const int enable2 = 11;       // enable pin for 2nd actuator -> pin 11

const int sensPin = A1;       // Sensor input pin

const int startButton = 2;    // information input from the button
const int switchOnOff = 3;    // information input from the on/off switch
const int checkDrawer = 4;    // information input from the drawer 'sensor'
const int stopButton = 5;     // stop button for retraction

const int ledGreen = 6;       // output to toggle green LED
const int ledRed = 7;         // output to toggle red LED
const int ledOrange = 8;      // output to toggle oragne LED

// define variables/constants
double userDistance;          // variable to hold the distance between the device and the user
bool firstTime = true;        // variable to check if this is the first extention since the switch has been turned on
const int timeLimit = 10000;   // constant to dictate the duration of the actuator's extention phase


void setup() {
  // set outputs
  pinMode(enable1, OUTPUT);
  pinMode(enable2, OUTPUT);

  pinMode(extPin, OUTPUT);
  pinMode(retPin, OUTPUT);

  pinMode(ledGreen, OUTPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(ledOrange, OUTPUT);

  // set inputs
  pinMode(startButton, INPUT_PULLUP);
  pinMode(switchOnOff, INPUT_PULLUP);
  pinMode(checkDrawer, INPUT_PULLUP);
  pinMode(stopButton, INPUT_PULLUP);

  // set initial states
  analogWrite(enable1, 255);
  analogWrite(enable2, 255);

  digitalWrite(extPin, LOW);
  digitalWrite(retPin, LOW);

  digitalWrite(ledGreen, LOW);
  digitalWrite(ledRed, LOW);
  digitalWrite(ledOrange, LOW);

  // serial monitor
  Serial.begin(9600);
}


void loop() {
  while (digitalRead(switchOnOff) == HIGH) {  // wait for switch to be turned on
    // Serial.println("waiting for switch...");
    delay(100);
  }
  
  while (digitalRead(switchOnOff) == LOW) { // loop continues as long as the switch is on
    if (firstTime == true) {  // startup sequence to fully extend the actuators, will only run the first time the switch is turned on
      FullExtend();
    }

    if (digitalRead(switchOnOff) == HIGH) { // if the device is switched off at any point, break the loop
      break;
    }
    Retract();

    if (digitalRead(switchOnOff) == HIGH) { // if the device is switched off at any point, break the loop
      break;
    }
    Extend();

  }

  OffState(); // the device reaches this state when it is switched off, will stay until switched on again
}
