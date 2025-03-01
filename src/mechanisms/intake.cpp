#include "src/mechanisms/intake.hpp"
#include "pros/motors.hpp"
#include "src/constants.hpp"
using namespace Mechanisms;

Intake::Intake() : m1(pros::Motor(Constants::Mechanisms::INTAKE)) {}

void Intake::run_velocity(int velocity) { m1.move_velocity(velocity); };
void Intake::stop() { m1.brake(); }