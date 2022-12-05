#pragma once
#include <string>
#include <filesystem>
#include "Data.h"
#include "HashTable.h"
using namespace std;
namespace fs = std::filesystem;

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

  // If folder_path is already in cache then return stored value
  // else recursively list all files in folder_path and store into cache
  FolderData *list_files_from_path(HashTable<FolderData> &cahe, const string &folder_path);
}
