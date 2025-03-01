#include "src/mechanisms/intake.hpp"
#include "pros/motors.hpp"
#include "src/constants.hpp"
using namespace Mechanisms;

Intake::Intake() : motor(pros::Motor(Constants::Mechanisms::INTAKE)) {}
