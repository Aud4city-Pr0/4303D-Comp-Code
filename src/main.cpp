#include "main.h"
#include "EZ-Template/auton.hpp"
#include "EZ-Template/sdcard.hpp"
#include "EZ-Template/util.hpp"
#include "autons.hpp"
#include "pros/misc.h"
#include "pros/rtos.hpp"
#include "subsystems.hpp"
#include "ladybrownglobals.hpp"

/////
// For installation, upgrading, documentations, and tutorials, check out our website!
// https://ez-robotics.github.io/EZ-Template/

/////

// Chassis constructor
ez::Drive chassis(
    // These are your drive motors, the first motor is used for sensing!
    {-5, -8, -4},     // Left Chassis Ports (negative port will reverse it!)
    {17, 10, 13},  // Right Chassis Ports (negative port will reverse it!)

    6,      // IMU Port
    2.75,  // Wheel Diameter (Remember, 4" wheels without screw holes are actually 4.125!)
    450);   // Wheel RPM

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
  // Print our branding over your terminal :D
  ez::ez_template_print();

  pros::delay(500);  // Stop the user from doing anything while legacy ports configure

  // setting up lady brown
  LadyBrownMech.set_zero_position(0);
  pros::Task LBControlTask([]{
    while(true) {
      LBControl();
      pros::delay(10);
    }
  });

  // Configure your chassis controls
  chassis.opcontrol_curve_buttons_toggle(true);  // Enables modifying the controller curve with buttons on the joysticks
  chassis.opcontrol_drive_activebrake_set(0);    // Sets the active brake kP. We recommend ~2.  0 will disable.
  chassis.opcontrol_curve_default_set(0, 0);     // Defaults for curve. If using tank, only the first parameter is used. (Comment this line out if you have an SD card!)

  // Set the drive to your own constants from autons.cpp!
  default_constants();

  // These are already defaulted to these buttons, but you can change the left/right curve buttons here!
  // chassis.opcontrol_curve_buttons_left_set(pros::E_CONTROLLER_DIGITAL_LEFT, pros::E_CONTROLLER_DIGITAL_RIGHT);  // If using tank, only the left side is used.
  // chassis.opcontrol_curve_buttons_right_set(pros::E_CONTROLLER_DIGITAL_Y, pros::E_CONTROLLER_DIGITAL_A);

  // Autonomous Selector using LLEMU
  ez::as::auton_selector.autons_add({
      // Our team autos (including skills)
      Auton("Four Ring With Tower Touch (RIGHT) \t Gets four rings on goal and ends with lb touching tower.", RightRedAuto),
      Auton("Two Ring On Mogo Third Goal Clamp (RIGHT) \t Puts two rings on a mogo and clamps on third goal.", LeftRedAuto),
      Auton("Four Ring With Tower Touch (LEFT) \t Gets four rings on goal and ends with lb touching tower.", RightBlueAuto),
      Auton("Two Ring On Mogo and Third Goal Clamp (LEFT) \t Puts two rings on a mogo and clamps on third goal.", LeftBlueAuto),
      Auton("Skills Auto. \t this is our skills auto.", MainSkillsAuto)
  });

  // Initialize chassis and auton selector
  chassis.initialize();
  ez::as::initialize();
  master.rumble(".");
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {
  // . . .
}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {
  // . . .
}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
  chassis.pid_targets_reset();                // Resets PID targets to 0
  chassis.drive_imu_reset();                  // Reset gyro position to 0
  chassis.drive_sensor_reset();               // Reset drive sensors to 0
  chassis.drive_brake_set(MOTOR_BRAKE_HOLD);  // Set motors to hold.  This helps autonomous consistency

  ez::as::auton_selector.selected_auton_call();  // Calls selected auton from autonomous selector
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
  // This is preference to what you like to drive on
  pros::motor_brake_mode_e_t driver_preference_brake = MOTOR_BRAKE_COAST;

  chassis.drive_brake_set(driver_preference_brake);

  while (true) {
    // PID Tuner
    // After you find values that you're happy with, you'll have to set them in auton.cpp
    if (!pros::competition::is_connected()) {
      // Enable / Disable PID Tuner
      //  When enabled:
      //  * use A and Y to increment / decrement the constants
      //  * use the arrow keys to navigate the constants
      if (master.get_digital_new_press(DIGITAL_X)) {
        chassis.pid_tuner_toggle();

      } // Trigger the selected autonomous routine
      if (master.get_digital(DIGITAL_B) && master.get_digital(DIGITAL_DOWN)) {
        autonomous();
        chassis.drive_brake_set(driver_preference_brake);
      }

      chassis.pid_tuner_iterate();  // Allow PID Tuner to iterate
    }

    chassis.opcontrol_arcade_standard(ez::SPLIT);   // Standard split arcade
    // . . .
    // Put more user control code here!
    // . . .

    // The driver controlls section
    // In this section, you will find the button controlls for our mechs (Intake, Mog, Etc.)

    MogoMech.button_toggle(master.get_digital(DIGITAL_A));
    DoinkerMech.button_toggle(master.get_digital(DIGITAL_Y));

    if (master.get_digital(DIGITAL_R1)) {
      IntakeMotor.move_velocity(-600);
    } 
    else if (master.get_digital(DIGITAL_L1)) {
      IntakeMotor.move_velocity(600);
    } 
    else {
      IntakeMotor.brake();
    }

    // The Lady Brown code
    if(master.get_digital(DIGITAL_L2)) {
      setLBState(1);
    } else if (master.get_digital(DIGITAL_R2)) {
      setLBState(2);
    } else if (master.get_digital(DIGITAL_X)) {
      setLBState(0);
    }
    pros::delay(ez::util::DELAY_TIME);  // This is used for timer calculations!  Keep this ez::util::DELAY_TIME
  }
}