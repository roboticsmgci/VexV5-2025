#ifndef ELEVATOR_HPP
#define ELEVATOR_HPP

// Your public definitions go here
#include "pros/motors.hpp"

namespace Mechanisms {
class Elevator {
public:
  pros::Motor motor;
  Elevator();
};
} // namespace Mechanisms

#endif // MY_HEADER_HP