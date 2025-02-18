#include "autons.hpp"
#include "main.h"
#include "pros/rtos.hpp"
#include "autonglobals.hpp"

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

// The Comp Autos
// Autonomus functions that are under the "Comp Autos" section will be used in auton.
// This will mainly contain our red and blue autos, the skills auto will be under another section.

void RightRedAuto() {
  set_pistion_status(MogoMech, PistionStatus::EXTEND);
  // This will contain our normal red auto
  chassis.pid_drive_set(-34_in, 75);
  chassis.pid_wait();
  // mogo clamp down
  set_pistion_status(MogoMech, PistionStatus::RETRACT);
  pros::delay(1000);
  // intake moves the ring onto the goal
  set_intake_status(IntakeStatus::INTAKE_ON);
  pros::delay(1000);
  chassis.pid_turn_set(100_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(27_in, 75);
  chassis.pid_wait();
  chassis.pid_turn_set(89_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-27_in, 75);
  chassis.pid_speed_max_set(DRIVE_SPEED);
  chassis.pid_wait();
  chassis.pid_turn_set(-150_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(12_in, DRIVE_SPEED);
  set_lady_brown_status(LadyBrownStatus::BROWN_SCORE);
  chassis.pid_wait();
  set_intake_status(IntakeStatus::INTAKE_OFF);
  // the end of our normal auto

}

// The other red
void LeftRedAuto() {
  // This will contain our other red auto
  set_pistion_status(MogoMech, PistionStatus::EXTEND);
  chassis.pid_drive_set(-34_in, 75);
  chassis.pid_speed_max_set(DRIVE_SPEED);
  chassis.pid_wait();
  // mogo clamp down
  set_pistion_status(MogoMech, PistionStatus::RETRACT);
  pros::delay(1000);
  // intake turns on
  set_intake_status(IntakeStatus::INTAKE_ON);
  pros::delay(1000);
  chassis.pid_drive_set(24_in, 75);
  chassis.pid_speed_max_set(DRIVE_SPEED);
  chassis.pid_wait();
  // intake turns off
  set_intake_status(IntakeStatus::INTAKE_OFF);
  // rectract mogo pistion
  set_pistion_status(MogoMech, PistionStatus::RETRACT);
  // end of auto

}

// the normal blue auto
void RightBlueAuto() {
  set_pistion_status(MogoMech, PistionStatus::EXTEND);
  // This will contain our normal red auto
  chassis.pid_drive_set(-36_in, 75);
  chassis.pid_wait();
  // mogo clamp down
  set_pistion_status(MogoMech, PistionStatus::RETRACT);
  pros::delay(1000);
  // intake moves the ring onto the goal
  set_intake_status(IntakeStatus::INTAKE_ON);
  pros::delay(1000);
  chassis.pid_turn_set(-95_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(24_in, 75);
  chassis.pid_wait();
  chassis.pid_turn_set(-95_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(-24_in, 75);
  chassis.pid_speed_max_set(DRIVE_SPEED);
  chassis.pid_wait();
  chassis.pid_turn_set(-197_deg, TURN_SPEED);
  chassis.pid_wait();
  chassis.pid_drive_set(12_in, DRIVE_SPEED);
  set_lady_brown_status(LadyBrownStatus::BROWN_SCORE);
  chassis.pid_wait();
  set_intake_status(IntakeStatus::INTAKE_OFF);
  // the end of our normal auto
}

void LeftBlueAuto() {
  set_pistion_status(MogoMech, PistionStatus::EXTEND);
  // This will contain our normal blue auto
  chassis.pid_drive_set(-34_in, 75);
  chassis.pid_wait();
  // mogo clamp down
  set_pistion_status(MogoMech, PistionStatus::RETRACT);
  pros::delay(1000);
  // intake turns on
  set_intake_status(IntakeStatus::INTAKE_ON);
  pros::delay(1000);
  chassis.pid_drive_set(24_in, 75);
  chassis.pid_speed_max_set(DRIVE_SPEED);
  chassis.pid_wait();
  // intake turns off
  set_intake_status(IntakeStatus::INTAKE_OFF);
  // rectract mogo pistion
  set_pistion_status(MogoMech, PistionStatus::RETRACT);
  // end of auto
}

// The Skills Auto Section
// This is the section that will contain our skills auto for our bot.

void MainSkillsAuto() {
  // This is the function that will contain skills auto
  // puts preload on aliance stake for 3 points
 set_intake_status(IntakeStatus::INTAKE_ON);
 pros::delay(990);
 set_intake_status(IntakeStatus::INTAKE_OFF);
 chassis.pid_drive_set(12_in, 55);
 chassis.pid_wait();
 chassis.pid_turn_set(90_deg, TURN_SPEED);
 set_pistion_status(MogoMech, EXTEND);
 chassis.pid_wait();
 chassis.pid_drive_set(-25_in, 55);
 chassis.pid_wait();
 // clamp down mogo
 set_pistion_status(MogoMech, PistionStatus::RETRACT);
 pros::delay(1000);
 set_intake_status(IntakeStatus::INTAKE_ON);
 chassis.pid_turn_set(0_deg, TURN_SPEED);
 chassis.pid_wait();
 chassis.pid_drive_set(25_in, 55);
 chassis.pid_wait();
 chassis.pid_turn_set(-100_deg, TURN_SPEED);
 chassis.pid_wait();
 chassis.pid_drive_set(25_in, 55);
 chassis.pid_wait();
 chassis.pid_turn_set(180_deg, TURN_SPEED);
 chassis.pid_wait();
 chassis.pid_drive_set(25_in, 55);
 chassis.pid_wait();
 chassis.pid_turn_set(45_deg, TURN_SPEED);
 chassis.pid_wait();
 chassis.pid_drive_set(-12_in, 55);
 set_pistion_status(MogoMech, PistionStatus::EXTEND);
 chassis.pid_wait();
 chassis.pid_drive_set(12_in, 55);
 chassis.pid_wait();
 chassis.pid_turn_set(90_deg, TURN_SPEED);
 chassis.pid_speed_max_set(DRIVE_SPEED);
 chassis.pid_wait();
 set_intake_status(IntakeStatus::INTAKE_OFF);
 chassis.pid_drive_set(35_in, DRIVE_SPEED);
 chassis.pid_wait();
 chassis.pid_turn_set(-95_deg, TURN_SPEED);
 chassis.pid_speed_max_set(55);
 chassis.pid_wait();
 chassis.pid_drive_set(-40_in, 55);
 chassis.pid_wait();
 set_pistion_status(MogoMech, PistionStatus::RETRACT);
 pros::delay(1000);
 set_intake_status(IntakeStatus::INTAKE_ON);
 chassis.pid_turn_set(0_deg, TURN_SPEED);
 chassis.pid_wait();
 chassis.pid_drive_set(26_in, 55);
 chassis.pid_wait();
 chassis.pid_turn_set(100_deg, TURN_SPEED);
 chassis.pid_wait();
 chassis.pid_drive_set(26_in, 55);
 chassis.pid_wait();
 chassis.pid_turn_set(-180_deg, TURN_SPEED);
 chassis.pid_wait();
 chassis.pid_drive_set(26_in, 55);
 chassis.pid_wait();
 chassis.pid_turn_set(-45_deg, TURN_SPEED);
 chassis.pid_wait();
 chassis.pid_drive_set(-12_in, 55);
 set_pistion_status(MogoMech, PistionStatus::EXTEND);
 chassis.pid_wait();
 chassis.pid_drive_set(12_in, 55);
 chassis.pid_wait();
}