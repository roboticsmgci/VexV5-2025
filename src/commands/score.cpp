#include "src/commands/score.hpp"
#include "pros/misc.h"
#include "pros/misc.hpp"
#include "pros/rtos.hpp"
#include "src/mechanisms/elevator.hpp"
#include "src/mechanisms/intake.hpp"

void commands::score(pros::Controller &controller,
                     Mechanisms::Elevator &elevator,
                     Mechanisms::Intake &intake) {
  if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_A) == 1) {
    intake.motor.move_velocity(200);
    pros::delay(2000);
    elevator.motor.move_absolute(100, 100);
    pros::delay(500);
    elevator.motor.move_absolute(0, 100);
    // velocity is in RPM <- green gearset maximum is 200 RPM

  } else {
    bool run_el = controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1) == 1 ||
                  controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2) == 1;
    if (!run_el) {
      elevator.motor.move_velocity(0);
    };

    bool run_in = controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1) == 1 ||
                  controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2) == 1;
    if (!run_in) {
      intake.motor.move_velocity(0);
    }
  }
}