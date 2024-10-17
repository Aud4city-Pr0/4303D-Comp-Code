#pragma once
#include "api.h"
#include "pros/adi.hpp"
#include "pros/motors.hpp"

// Your motors, sensors, etc. should go here.  Below are examples

// Our bot systems and mechs
inline pros::Motor IntakeMotor(11, pros::v5::MotorGears::green);
inline pros::adi::Pneumatics MogoMech('A', false);
inline pros::Motor LadyBrownMech(15, pros::v5::MotorGears::red);
