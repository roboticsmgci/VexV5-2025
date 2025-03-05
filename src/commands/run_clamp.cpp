#include "src/commands/run_clamp.hpp"
#include "pros/misc.h"
#include "pros/misc.hpp"
#include "src/mechanisms/clamp.hpp"

void commands::run_clamp(pros::Controller &controller,
                         Mechanisms::Clamp &clamp_mechanism) {
  if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_X) == 1) {
    // velocity is in RPM <- green gearset maximum is 200 RPM
    clamp_mechanism.motor.move_velocity(50);
  } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_Y) == 1) {
    clamp_mechanism.motor.move_velocity(-50);
  } else {
    clamp_mechanism.motor.move_velocity(0);
  }
}