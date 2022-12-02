#include "include/Data.h"

void FileData::append(const string &key, const string &path) {
  (void)key;
  abs_path.emplace_back(path);
}
