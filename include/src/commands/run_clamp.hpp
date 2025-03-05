#ifndef RUN_CLAMP_HPP
#define RUN_CLAMP_HPP

#include "pros/misc.hpp"
#include "src/mechanisms/clamp.hpp"

namespace commands {
void run_clamp(pros::Controller &controller,
               Mechanisms::Clamp &clamp_mechanism);
}

#endif