#include <iostream>
#include "include/utils.h"

void utils::print_path_format() {
  cout << "Disk path format: " << endl;
  cout << "<Disk>:\\" << endl;
  cout << "Folder path format: " << endl;
  cout << "<Disk>:\\<Folder1>\\<Folder2>" << endl;
  cout << "File path format: " << endl;
  cout << "<Disk>:\\<Folder1>\\<File>" << endl;
  cout << "Name of disk, folder and file is not empty and does not contain \":\" \"\\\"" << endl;
}

bool utils::check_path_format(const string &path) {
  if (path.size() == 0 || path[0] == '\\' || path[0] == ':') return false;
  int i;
  for (i=0; i < (int)path.size(); i++) {
    if (path[i] == '\\') return false;
    if (path[i] == ':') break;
  }
  i++;
  if (i >= (int)path.size() || path[i] != '\\') return false;
  if (i == (int)path.size() - 1) return true;

  for (; i < (int)path.size() - 1; i++) {
    if (path[i+1] == ':' || (path[i] == '\\' && path[i+1] == '\\')) return false;
  }

  return path.back() != '\\';
}

utils::PathType utils::get_path_target(const string &path, string &result) {
  if (!utils::check_path_format(path)) return utils::kUndefined;
  // Disk
  int length = path.size();
  if (path.back() == '\\') {
    result = path.substr(0, length-2);
    return utils::kDisk;
  }
  
  while (path[--length] != '\\');

  result = path.substr(length+1);
  return utils::kFolderNFile;
}
