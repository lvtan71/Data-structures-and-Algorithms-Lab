#pragma once
#include "Trie.h"
#include "Data.h"
#include "HashTable.h"
#include "utils.h"

namespace option_3 {
  void run(HashTable<FolderData> &cache);

  /*
   * Find a node X that have X->num_descendent + (X->abs_path.size() != 0) <= 3
   * All files are stored in X and its descendent should be in same folder
   *
   * `prefix_path` cumulates characters on the path from root to X
   * Use `prefix_path` to compute `dest_path`
   *
   * Example:
   * `folder_path`: d:\OrderedFolder
   * `prefix_path`: ABC
   * => `dest_path`: d:\OrderedFolder\A\AB\ABC
   */
  void dfs1(TrieNode *root, const string &folder_path, const string prefix_path);

  /*
   * Find and move files stored in root and its descendent to `dest_path`
   */
  void dfs2(TrieNode *root, const string &dest_path);

  // function overloading to hide the details
  void dfs1(TrieNode *root, const string &folder_path);

  // Move function
  void move_file(const string &dest_path, const string &src_path);
}

