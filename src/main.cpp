#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "liblvgl/llemu.hpp"
#include "pros/misc.h"
#include "src/commands/run_clamp.hpp"
#include "src/commands/run_elevator.hpp"
#include "src/commands/run_intake.hpp"
#include "src/constants.hpp"
#include "src/mechanisms/clamp.hpp"
#include "src/mechanisms/elevator.hpp"
#include "src/mechanisms/intake.hpp"
using namespace std;

// Drivetrain Motors
pros::MotorGroup
    right_motors({Constants::Drivetrain::R1, Constants::Drivetrain::R2},
                 pros::MotorGearset::green); // right motors on ports 3, 4
pros::MotorGroup
    left_motors({Constants::Drivetrain::L1, Constants::Drivetrain::L2},
                pros::MotorGearset::green); // left motors on ports 1, 2

// intake
// Mechanisms::Intake intake;

// clamp
// Mechanisms::Clamp clamp_mechanism;

// elevator
// Mechanisms::Elevator elevator;

// input curve for throttle input during driver control
// lemlib::ExpoDriveCurve
//     throttle_curve(3,    // joystick deadband out of 127
//                    10,   // minimum output where drivetrain will move out of
//                    127 1.019 // expo curve gain
//     );

// input curve for steer input during driver control
// lemlib::ExpoDriveCurve
//     steer_curve(3,    // joystick deadband out of 127
//                 10,   // minimum output where drivetrain will move out of 127
//                 1.019 // expo curve gain
//     );

// drivetrain settings
lemlib::Drivetrain drivetrain(&left_motors,             // left motor group
                              &right_motors,            // right motor group
                              16,                       // 16 inch track width
                              lemlib::Omniwheel::NEW_4, // using new 4" omnis
                              360,                      // drivetrain rpm is 360
                              2 // horizontal drift is 2 (for now)
);

// TODO Configure everything below

// imu
pros::Imu imu(10);
// horizontal tracking wheel encoder
// pros::Rotation horizontal_encoder(20);
// vertical tracking wheel encoder
// pros::adi::Encoder vertical_encoder('C', 'D', true);
// horizontal tracking wheel
// lemlib::TrackingWheel horizontal_tracking_wheel(&horizontal_encoder,
// lemlib::Omniwheel::NEW_275, -5.75); vertical tracking wheel
// lemlib::TrackingWheel vertical_tracking_wheel(&vertical_encoder,
// lemlib::Omniwheel::NEW_275, -2.5);

// odometry settings
// lemlib::OdomSensors sensors(&vertical_tracking_wheel, // vertical tracking
// wheel 1, set to null
//                             nullptr, // vertical tracking wheel 2, set to
//                             nullptr as we are using IMEs
//                             &horizontal_tracking_wheel, // horizontal
//                             tracking wheel 1 nullptr, // horizontal tracking
//                             wheel 2, set to nullptr as we don't have a second
//                             one &imu // inertial sensor
// );

// **

lemlib::OdomSensors sensors(
    nullptr, // vertical tracking wheel 1, set to null
    nullptr, // vertical tracking wheel 2, set to nullptr as we are using IMEs
    nullptr, // horizontal tracking wheel 1
    nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a
             // second one
    &imu     // inertial sensor
);

// lateral PID controller
lemlib::ControllerSettings
    lateral_controller(10,  // proportional gain (kP)
                       0,   // integral gain (kI)
                       3,   // derivative gain (kD)
                       3,   // anti windup
                       1,   // small error range, in inches
                       100, // small error range timeout, in milliseconds
                       3,   // large error range, in inches
                       500, // large error range timeout, in milliseconds
                       20   // maximum acceleration (slew)
    );

// angular PID controller
lemlib::ControllerSettings
    angular_controller(2,   // proportional gain (kP)
                       0,   // integral gain (kI)
                       10,  // derivative gain (kD)
                       3,   // anti windup
                       1,   // small error range, in degrees
                       100, // small error range timeout, in milliseconds
                       3,   // large error range, in degrees
                       500, // large error range timeout, in milliseconds
                       0    // maximum acceleration (slew)
    );

// create the chassis
lemlib::Chassis chassis(drivetrain,         // drivetrain settings
                        lateral_controller, // lateral PID settings
                        angular_controller, // angular PID settings
                        sensors             // odometry sensors
);

pros::Controller controller(pros::E_CONTROLLER_MASTER);

// !! UP to Here

// Autonomous
// string auto_path_name = Constants::Auto::a1_name;
// asset auto_path_file = Constants::Auto::a1_file_name;

/**
 * A callback function for LLEMU's left button.
 *
 */
void on_left_button() {
  // if (auto_path_name != Constants::Auto::a1_name) {
  //   pros::lcd::clear_line(2);
  // }
  // pros::lcd::set_text(5, "Auto: " + Constants::Auto::a1_name);
  // auto_path_file = Constants::Auto::a1_file_name;
  // auto_path_name = Constants::Auto::a1_name;
}

/**
 * A callback function for LLEMU's center button.
 *
 */

void on_center_button() {
  // if (auto_path_name != Constants::Auto::a2_name) {
  //   pros::lcd::clear_line(2);
  // }
  // pros::lcd::set_text(5, "Auto: " + Constants::Auto::a2_name);
  // auto_path_file = Constants::Auto::a2_file_name;
  // auto_path_name = Constants::Auto::a2_name;
}

/**
 * A callback function for LLEMU's right button.
 *
 */
void on_right_button() {
  // if (auto_path_name != Constants::Auto::a3_name) {
  //   pros::lcd::clear_line(2);
  // }
  // pros::lcd::set_text(5, "Auto: " + Constants::Auto::a3_name);
  // auto_path_file = Constants::Auto::a3_file_name;
  // auto_path_name = Constants::Auto::a3_name;
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
  pros::lcd::initialize();

  pros::lcd::set_text(1, "Welcome Master Gavin! Pick an auto:");
  // pros::lcd::set_text(2, "left - " + Constants::Auto::a1_name);
  // pros::lcd::set_text(3, "center - " + Constants::Auto::a2_name);
  // pros::lcd::set_text(4, "right - " + Constants::Auto::a3_name);

  pros::lcd::register_btn0_cb(on_left_button);
  pros::lcd::register_btn1_cb(on_center_button);
  pros::lcd::register_btn2_cb(on_right_button);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

// path file name is "example.txt".
// "." is replaced with "_" to overcome c++ limitations
ASSET(test_txt);

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
  // pros::lcd::clear();
  // pros::lcd::set_text(1, "Mode: autonomous");
  // lookahead distance: 15 inches
  // timeout: 2000 ms
  // chassis.follow(auto_path_file, 15, 2000);
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
  pros::lcd::clear();
  // pros::lcd::set_text(1, "Mode: opcontrol");

  while (true) {

    // ** Single stick arcade drive **

    // get left y and right x positions
    int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    int leftX = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X);

    // move the robot
    chassis.arcade(leftY, leftX);

    // run intake
    // commands::run_intake(controller, intake);

    // run elevator
    // commands::run_elevator(controller, elevator);

    // run clamp
    // commands::run_clamp(controller, clamp_mechanism);

    // delay to save resources
    pros::delay(25);
  }
}