#pragma once

#include "EZ-Template/drive/drive.hpp"
#include "EZ-Template/piston.hpp"
#include "pros/motors.hpp"
#include "pros/rotation.hpp"
#include "subsystems.hpp"

extern Drive chassis;
extern ez::Piston MogoMech;
extern ez::Piston DoinkerMech;
extern pros::Motor IntakeMotor;
extern pros::Motor LadyBrownMech;
extern pros::Rotation LBRotationSensor;

// The function defs for the autons in autons.cpp
// DO NOT REMOVE OR CODE WON'T WORK!!!!!

// The function def for normal red auto
void RightRedAuto();
// The function def for other red auto
void LeftRedAuto();
// The function def for normal blue auto
void RightBlueAuto();
// The function def for other blue auto
void LeftBlueAuto();
// The function def for the main skills auto
void MainSkillsAuto();

void default_constants();