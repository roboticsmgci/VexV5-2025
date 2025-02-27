#ifndef INTAKE_HPP
#define INTAKE_HPP

// Your public definitions go here
#include "pros/motors.hpp"
extern pros::Motor m1;
namespace Mechanisms {
class Intake {
public:
  void run(int velocity) {}
};
} // namespace Mechanisms

#endif // MY_HEADER_HPP