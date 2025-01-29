// Includes that are needed
#include "api.h"
#include "pros/motors.hpp"
#include "pros/rotation.hpp"
#include "subsystems.hpp"
// Importing LB functions. DO NOT REMOVE!!
#include "ladybrownglobals.hpp"

// LB variables
const int LBSates = 3;
int statesArray[LBSates] = {0, 100, 200};
int currentState = 0;
int targetAngle = 0;

void nextLBState() {
  currentState += 1;
  if(currentState == LBSates) {
    currentState = 0;
  }
  targetAngle = statesArray[currentState];
  LBControl();
}

void LBControl() {
  // PID Values. DO NOT CHANGE UNLESS YOU KNOW WHAT YOU ARE DOING!!!!
  double kp = 0.5;
  double err = targetAngle - LBRotationSensor.get_angle();
  double motorVeloctiy = kp * err;
  LadyBrownMech.move(motorVeloctiy);
}