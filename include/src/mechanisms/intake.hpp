#ifndef INTAKE_HPP
#define INTAKE_HPP

// Your public definitions go here
#include "pros/motors.hpp"

namespace Mechanisms {
class Intake {
public:
  pros::Motor motor;
  Intake();
};
} // namespace Mechanisms

#endif // MY_HEADER_HP