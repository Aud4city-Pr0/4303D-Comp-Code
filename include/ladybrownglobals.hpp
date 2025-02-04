// This file is used for storing common LadyBrown functions
#pragma once

// cycles through LB states
void nextLBState();
// controls LB pos via PID
void LBControl();
// sets the lb to its next position. USE FOR AUTON ONLY!!!
void setLBState(int nextState);
// resets lb state to zero
void resetLBState();