#include "src/mechanisms/clamp.hpp"
#include "pros/motors.hpp"
#include "src/constants.hpp"
using namespace Mechanisms;

Clamp::Clamp() : motor(pros::Motor(Constants::Mechanisms::CLAMP)) {}