#include "src/commands/run_elevator.hpp"
#include "pros/misc.h"
#include "pros/misc.hpp"
#include "src/mechanisms/elevator.hpp"

void commands::run_elevator(pros::Controller &controller,
                            Mechanisms::Elevator &elevator) {
  if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1) == 1) {
    // velocity is in RPM <- green gearset maximum is 200 RPM
    elevator.motor.move_velocity(200);
  } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2) == 1) {
    elevator.motor.move_velocity(-200);
  } else {
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_A) == 0) {
      elevator.motor.move_velocity(0);
    }
  }
}