#include "include/Trie.h"
#include "include/utils.h"

Trie::Trie() :
  root_(createNode())
{}

bool Trie::insertFile(const string &file_name, const string &abs_path) {
  if (abs_path.size() == 0) return false;
  int idx;
  Node *cur = root_;

  for (const auto &ch : file_name) {
    if (utils::check_valid_character(ch)) {

      idx = char_to_child_idx(ch);

      if (cur->child[idx] == nullptr) {
        cur->child[idx] = createNode();
      }
      
      cur->num_descendent++;
      cur = cur->child[idx];
    }
  }

  if (cur != root_ && cur->abs_path.size() == 0) {
    cur->abs_path = abs_path;
    return true;
  } 

  return false;
}

Trie::Node* Trie::createNode() const {
  Node *new_node = new Node;
  new_node->abs_path = "";

  for (int i = 0; i < NUM_CHILD_TRIE_NODE; i++) {
    new_node->child[i] = nullptr;
  }

  return new_node;
}

int Trie::char_to_child_idx(const char &ch) const {
  if ('0' <= ch && ch <= '9') return ch - '0';

  if ('a' <= ch && ch <= 'z') return ('9' - '0' + 1) + (ch - 'a');
  if ('A' <= ch && ch <= 'Z') return ('9' - '0' + 1) + ('z' - 'a' + 1) + (ch - 'A');

  if (ch == '_') return NUM_CHILD_TRIE_NODE - 2;
  if (ch == '.') return NUM_CHILD_TRIE_NODE - 1;

  return -1;
}
