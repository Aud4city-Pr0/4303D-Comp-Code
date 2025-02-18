// this lib provides our autonomus mech functions that are most commonly used in auto.
#pragma once
#include "EZ-Template/piston.hpp"

// Mech enums
// This is where you will find enums for our mechs

// The pistion exstention status enum
enum PistionStatus {
  RETRACT = 0,
  EXTEND = 1
};

// The intake on/off status enum
enum IntakeStatus {
  INTAKE_OFF = 0,
  INTAKE_ON = 1 
};

// The lady brown status enum
enum LadyBrownStatus {
  BROWN_IDLE = 0,
  BROWN_LOAD = 1,
  BROWN_SCORE = 2
};

// Auton bot mech functions
// This section will be for our autons bot mech fucntions
// You will find functions for our Mogo, Intake and other parts of our bot that will be used in auto

// the lady brown function
void set_lady_brown_status(LadyBrownStatus Status);

// The pistion controll function
void set_pistion_status(ez::Piston pistionToExtend, PistionStatus Status);

// The intake function
void set_intake_status(IntakeStatus Status);