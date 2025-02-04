// Includes that are needed
#include "api.h"
#include "pros/motors.hpp"
#include "subsystems.hpp"
// Importing LB functions. DO NOT REMOVE!!
#include "ladybrownglobals.hpp"

// LB variables
const int LBSates = 3;
int statesArray[LBSates] = {0, -320, -1900};
int currentState = 0;
int targetAngle = 0;

void LBControl() {
  // moves lb
 LadyBrownMech.move_absolute(targetAngle, 100);
}

void setLBState(int nextState) {
  currentState = nextState;
  targetAngle = statesArray[currentState];
}

void resetLBState() {
  currentState = 0;
  targetAngle = statesArray[currentState];
}