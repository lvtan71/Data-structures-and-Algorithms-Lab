#pragma once
#include "Data.h"
#include "HashTable.h"
#include "utils.h"

namespace option_2 {
  void run(const string &folder_path, HashTable<FolderData> &cache);
}
