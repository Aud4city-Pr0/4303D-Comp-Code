// auton global functions code
#include "autonglobals.hpp"
#include "ladybrownglobals.hpp"
#include "subsystems.hpp"

void set_lady_brown_status(LadyBrownStatus Status) {
    if(Status == LadyBrownStatus::BROWN_SCORE) {
      setLBState(2);
    } else if(Status == LadyBrownStatus::BROWN_IDLE) {
      setLBState(0);
    } else if(Status == LadyBrownStatus::BROWN_LOAD) {
      setLBState(1);
    }
}

void set_pistion_status(ez::Piston pistionToExtend, PistionStatus Status) {
    if(Status == PistionStatus::EXTEND) {
      // extend the mogo or doinker
      pistionToExtend.set(true);
    } else if(Status == PistionStatus::RETRACT) {
      // retract the mogo or doinker
      pistionToExtend.set(false);
    }
}

void set_intake_status(IntakeStatus Status) {
    if(Status == IntakeStatus::INTAKE_ON) {
      // turn on the intake
      IntakeMotor.move_voltage(-12000);
    } else if(Status == IntakeStatus::INTAKE_OFF) {
      // turn the intake off
      IntakeMotor.brake();
    }
}