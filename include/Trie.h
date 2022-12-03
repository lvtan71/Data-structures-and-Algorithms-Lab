#pragma once
#include <string>
#include "Constants.h"

using namespace std;

struct TrieNode {
  // @note One file_name can only have one absolute path
  string abs_path; 
  int num_descendent;
  TrieNode* child[NUM_CHILD_TRIE_NODE];
};

class Trie {
public:
  Trie();
  ~Trie();

  TrieNode *getRoot() const;

  /*
   * Not insert file_name and return false if abs_path is an empty string
   * Return false if file_name has already inserted, otherwise return true
   *
   * @onerror ignore invalid characters
   * @onerror after eliminate invalid characters 
   * if file_name is empty then do not insert abs_path 
   */
  bool insertFile(const string &file_name, const string &abs_path);

private:

  TrieNode *root_;

  int char_to_child_idx(const char &ch) const;

  TrieNode* createNode() const;
  void deleteNode(TrieNode *root);
};
