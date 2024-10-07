#pragma once
#include "api.h"
#include "pros/adi.hpp"
#include "pros/motors.hpp"

// Your motors, sensors, etc. should go here.  Below are examples

// Our bot systems and mechs
inline pros::Motor IntakeMotor(11);
inline pros::adi::Pneumatics MogoMech('a', false);
