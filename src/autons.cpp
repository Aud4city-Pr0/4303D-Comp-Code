#include "main.h"

/////
// For installation, upgrading, documentations, and tutorials, check out our website!
// https://ez-robotics.github.io/EZ-Template/
/////

// These are out of 127
const int DRIVE_SPEED = 110;
const int TURN_SPEED = 90;
const int SWING_SPEED = 90;

///
// Constants
///
void default_constants() {
  chassis.pid_heading_constants_set(11, 0, 20);
  chassis.pid_drive_constants_set(20, 0, 100);
  chassis.pid_turn_constants_set(3, 0.05, 20, 15);
  chassis.pid_swing_constants_set(6, 0, 65);

  chassis.pid_turn_exit_condition_set(80_ms, 3_deg, 250_ms, 7_deg, 500_ms, 500_ms);
  chassis.pid_swing_exit_condition_set(80_ms, 3_deg, 250_ms, 7_deg, 500_ms, 500_ms);
  chassis.pid_drive_exit_condition_set(80_ms, 1_in, 250_ms, 3_in, 500_ms, 500_ms);

  chassis.pid_turn_chain_constant_set(3_deg);
  chassis.pid_swing_chain_constant_set(5_deg);
  chassis.pid_drive_chain_constant_set(3_in);

  chassis.slew_drive_constants_set(7_in, 80);
}

// . . .
// Make your own autonomous functions here!
// . . .

// Mech enums
// This is where you will find enums for our mechs

// The pistion exstention staus enum
enum PistionStatus {
  RETRACT = 0,
  EXTEND = 1
};

// The intake on/off status enum
enum IntakeStatus {
  INTAKE_OFF = 0,
  INTAKE_ON = 1 
};


// Auton bot mech functions
// This section will be for our autons bot mech fucntions
// You will find functions for our Mogo, Intake and other parts of our bot that will be used in auto

// The mogo function
void set_mogo_status(PistionStatus Status) {
  if(Status == PistionStatus::EXTEND) {
    // extend the mogo
  } else if(Status == PistionStatus::RETRACT) {
    // retract the mogo
  }
}

// The intake function
void set_intake_status(IntakeStatus Status) {
  if(Status == IntakeStatus::INTAKE_ON) {
    // turn on the intake
  } else if(Status == IntakeStatus::INTAKE_OFF) {
    // turn the intake off
  }
}


// The Comp Autos
// Autonomus functions that are under the "Comp Autos" section will be used in auton.
// This will mainly contain our red and blue autos, the skills auto will be under another section.

void NormalRedAuto() {
  // This will contain our normal red auto
  chassis.pid_drive_set(48_in, DRIVE_SPEED);
  chassis.pid_wait();
  // mogo clamp down
  set_mogo_status(PistionStatus::EXTEND);
  chassis.pid_drive_set(-48_in, DRIVE_SPEED);
  // intake moves the ring onto the goal
  set_intake_status(IntakeStatus::INTAKE_ON);
  chassis.pid_wait();
  // mogo realeases the goal
  set_intake_status(IntakeStatus::INTAKE_ON);
  set_mogo_status(PistionStatus::RETRACT);
  chassis.pid_turn_set(45_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(48_in, DRIVE_SPEED);
  chassis.pid_wait();
  // the end of our normal auto

}

void OtherRedAuto() {
  // This will contain our other red auto
}