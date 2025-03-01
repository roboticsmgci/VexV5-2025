#include "src/commands/run_intake.hpp"
#include "pros/misc.hpp"
#include "src/mechanisms/intake.hpp"

void commands::run_intake(pros::Controller &controller,
                          Mechanisms::Intake &intake) {
  if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_A)) {
    // velocity is in RPM <- red gearset maximum is 100 RPM
    intake.run_velocity(100);
  }
}