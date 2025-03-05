#ifndef RUN_ELEVATOR_HPP
#define RUN_ELEVATOR_HPP

#include "pros/misc.hpp"
#include "src/mechanisms/elevator.hpp"
#include "src/mechanisms/intake.hpp"

namespace commands {
void score(pros::Controller &controller, Mechanisms::Elevator &elevator,
           Mechanisms::Intake &intake);
}

#endif