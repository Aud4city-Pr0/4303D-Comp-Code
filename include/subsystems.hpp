#pragma once
#include "EZ-Template/piston.hpp"
#include "api.h"
#include "pros/motors.hpp"

// Your motors, sensors, etc. should go here.  Below are examples

// Our bot systems and mechs
inline ez::Piston MogoMech('A', false);
inline ez::Piston DoinkerMech('B', true);
inline pros::Motor LadyBrownMech(11, pros::v5::MotorGears::red);
// intake motor
inline pros::Motor IntakeMotor(19, pros::v5::MotorGear::blue);