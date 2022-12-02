#pragma once
#include <string>
using namespace std;

namespace utils {
  enum PathType {
    kDisk,
    kFolderNFile,
    kUndefined
  };
  void print_path_format();
  bool check_path_format(const string &path);
  PathType get_path_target(const string &path, string &result);
}
