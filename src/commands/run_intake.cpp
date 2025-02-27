#include "pros/misc.h"
#include "pros/misc.hpp"
#include "src/mechanisms/intake.hpp"
#include <iostream>
using namespace std;

void run_intake(pros::Controller controller, Mechanisms::Intake intake) {
  if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_A) == 1) {

    intake.run(100);
  }
  cout << controller.get_digital(pros::E_CONTROLLER_DIGITAL_A) << endl;
}