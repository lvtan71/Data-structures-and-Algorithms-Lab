#pragma once
#include <string>

using namespace std;

const char VALID_CHARS[] = {
  '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',

  'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
  'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
  'u', 'v', 'w', 'x', 'y', 'z',

  'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
  'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
  'U', 'V', 'W', 'X', 'Y', 'Z',

  '_', '.'
};

constexpr int NUM_CHILD_TRIE_NODE = sizeof(VALID_CHARS) / sizeof(char);

class Trie {
public:
  Trie();

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
  struct Node {
    // @note One file_name can only have one absolute path
    string abs_path; 
    int num_descendent;
    Node* child[NUM_CHILD_TRIE_NODE];
  };

  Node *root_;

  int char_to_child_idx(const char &ch) const;
  Node* createNode() const;
};
