#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP
#include "lemlib/asset.hpp"
#include "string"

namespace Constants {
enum Drivetrain { L1 = -1, L2 = -2, R1 = 3, R2 = 4 };
enum Mechanisms { INTAKE = 7, CLAMP = 5, ELEVATOR = 9, IMU = 8 };

class Auto {
public:
  static std::string a1_name;
  static asset a1_file_name;
  static std::string a2_name;
  static asset a2_file_name;
  static std::string a3_name;
  static asset a3_file_name;

public:
  Auto();
};

} // namespace Constants

#endif