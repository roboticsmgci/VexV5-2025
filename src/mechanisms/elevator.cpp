#include "src/mechanisms/elevator.hpp"
#include "pros/motors.hpp"
#include "src/constants.hpp"


using namespace Mechanisms;

Elevator::Elevator() : motor(pros::Motor(Constants::Mechanisms::ELEVATOR)) {}