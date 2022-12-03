#pragma once
#include <string>
using namespace std;

namespace utils {
  void print_sep_line();
  void print_menu();

  bool check_valid_character(const char &ch);

  enum PathType {
    kDisk,
    kFolderNFile,
    kUndefined
  };
  void print_path_format();
  bool check_path_format(const string &path);
  bool check_valid_file(const string &file);
  PathType get_path_target(const string &path, string &result);
}
