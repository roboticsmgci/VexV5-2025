#include "src/constants.hpp"
#include "lemlib/asset.hpp"
#include "string"

using namespace std;

ASSET(test_txt);

Constants::Auto::Auto() {
  a1_name = "a1";
  a1_file_name = test_txt;

  a2_name = "a2";
  a2_file_name = test_txt;

  a3_name = "a3";
  a3_file_name = test_txt;
}