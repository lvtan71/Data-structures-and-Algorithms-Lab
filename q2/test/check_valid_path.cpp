#include <iostream>
#include <cassert>
#include "../include/utils.h"
using namespace std;

void test_check_valid_path() {
  cout << "[Test] Check valid path - ";
  assert(utils::check_path_format("d:\\"));
  assert(utils::check_path_format("d:\\abc"));
  assert(utils::check_path_format("d:\\abc\\xyz"));
  
  assert(!utils::check_path_format("d\\abc\\xyz"));
  assert(!utils::check_path_format("d:\\\\xyz"));
  assert(!utils::check_path_format("d:\\abc\\xyz\\"));
  assert(!utils::check_path_format("d:\\\\"));
  assert(!utils::check_path_format("d\\\\"));
  assert(!utils::check_path_format("d:\\abc\\xy:z"));
  assert(!utils::check_path_format("d:\\abc\\xy:z"));

  cout << "Passed" << endl;
}

int main() {
  test_check_valid_path();
  return 0;
}
