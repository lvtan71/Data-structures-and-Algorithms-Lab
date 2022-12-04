#pragma once
#include "Data.h"
#include "HashTable.h"
#include "utils.h"
#include "utils_.h"
#include "Constants.h"

namespace option_1 {
  /* 
   * Internal type storing if an ancestor is a last folder
   * If ancestor at level `i` is a last folder
   * then the `i` bit of AncestorInfo is 1, otherwise 0
   */
  typedef long long AncestorInfo;

  // Driver code
  void run(HashTable<FolderData> &cache);

  /*
   * Iterate over files and folders at the same level,
   * print to the console base on `level` and `info`
   */
  void dfs(
    const fs::path &path, 
    int level, 
    AncestorInfo info,
    const string &folder_path,
    HashTable<FolderData> &cache
  );

  void print_file(
    const string &name,
    int level,
    AncestorInfo info
  );

  void print_directory_tree(
    string folder_path, 
    HashTable<FolderData> &cache
  );
}
