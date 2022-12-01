#include <iostream>
#include "include/utils.h"

void utils::print_path_format() {
  cout << "Disk path format: " << endl;
  cout << "<Disk>:\\" << endl;
  cout << "Folder path format: " << endl;
  cout << "<Disk>:\\<Folder1>\\<Folder2>" << endl;
  cout << "File path format: " << endl;
  cout << "<Disk>:\\<Folder1>\\<File>" << endl;
  cout << "Name of disk, folder and file does not contain \":\" \"\\\"" << endl;
}

bool utils::check_path_format(string path) {
  int i;
  for (i=0; i < path.size(); i++) {
    if (path[i] == '\\') return false;
    if (path[i] == ':') break;
  }
  i++;
  if (i >= path.size() || path[i] != '\\') return false;
  if (i == (int)path.size() - 1) return true;

  for (; i < (int)path.size() - 1; i++) {
    if (path[i+1] == ':' || (path[i] == '\\' && path[i+1] == '\\')) return false;
  }

  return path.back() != '\\';
}
