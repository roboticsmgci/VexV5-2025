#include "src/commands/run_intake.hpp"
#include "pros/misc.hpp"
#include "src/mechanisms/intake.hpp"

void commands::run_intake(pros::Controller &controller,
                          Mechanisms::Intake &intake) {
  if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_A) == 1) {
    // velocity is in RPM <- green gearset maximum is 200 RPM
    intake.motor.move_velocity(100);
  } else {
    intake.motor.move_velocity(0);
  }
}