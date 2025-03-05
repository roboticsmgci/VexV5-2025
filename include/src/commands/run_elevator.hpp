#ifndef RUN_ELEVATOR_HPP
#define RUN_ELEVATOR_HPP

#include "pros/misc.hpp"
#include "src/mechanisms/elevator.hpp"

namespace commands {
void run_elevator(pros::Controller &controller, Mechanisms::Elevator &elevator);
}

#endif