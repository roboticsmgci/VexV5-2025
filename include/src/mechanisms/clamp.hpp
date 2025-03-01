#ifndef CLAMP_HPP
#define CLAMP_HPP

// Your public definitions go here
#include "pros/motors.hpp"

namespace Mechanisms {
class Clamp {
public:
  pros::Motor motor;
  Clamp();
};
} // namespace Mechanisms

#endif // MY_HEADER_HP