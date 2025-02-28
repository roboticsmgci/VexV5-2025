#ifndef INTAKE_HPP
#define INTAKE_HPP

// Your public definitions go here
#include "pros/motors.hpp"

namespace Mechanisms {
class Intake {

private:
  pros::Motor m1;

public:
  void run(int velocity);
  void stop();
  Intake();
};
} // namespace Mechanisms

#endif // MY_HEADER_HPP