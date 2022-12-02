#include "include/Data.h"

void FileData::append(const string &path) {
  abs_path.emplace_back(path);
}
