#include "src/mechanisms/intake.hpp"
#include "pros/motors.hpp"
using namespace Mechanisms;

Intake::Intake() : m1(pros::Motor(7)) {}

void Intake::run(int velocity) { m1.move_velocity(velocity); };
void Intake::stop() { m1.brake(); }