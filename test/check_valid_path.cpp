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

  assert(!utils::check_path_format(":\\abc\\xy:z"));
  assert(!utils::check_path_format("\\abc\\xy:z"));

  cout << "Passed" << endl;
}

void test_get_target() {
  cout << "[Test] Get target in path - ";
  string result;
  
  assert(utils::get_path_target("d:\\", result) == utils::kDisk);
  assert(result == "d");

  assert(utils::get_path_target("d:\\abc", result) == utils::kFolderNFile);
  assert(result == "abc");

  assert(utils::get_path_target("d:\\abc\\", result) == utils::kUndefined);
  cout << "Passed" << endl;
}

int main() {
  test_check_valid_path();
  test_get_target();
  return 0;
}
