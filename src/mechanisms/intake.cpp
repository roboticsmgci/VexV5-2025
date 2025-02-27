#include "src/mechanisms/intake.hpp"
#include "pros/motors.hpp"

pros::Motor m1 = pros::Motor(7);

class Intake {
  void run_velocity(int velocity) { m1.move_velocity(velocity); };
};