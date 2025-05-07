#pragma once
#include "EZ-Template/piston.hpp"
#include "api.h"
#include "pros/motors.hpp"

// Your motors, sensors, etc. should go here.  Below are examples

// Our bot systems and mechs
inline ez::Piston MogoMech('A', false);
inline ez::Piston DoinkerMech('B', false);
inline pros::Motor LadyBrownMech(-12, pros::v5::MotorGears::green);
// intake motor
inline pros::Motor IntakeMotor(20, pros::v5::MotorGear::blue);