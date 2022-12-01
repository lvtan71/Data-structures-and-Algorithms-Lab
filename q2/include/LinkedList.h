#pragma once
#include <vector>
#include <string>

using namespace std;

struct FileData {
  vector<string> abs_path;
};

struct Node {
  string key;
  FileData *p_data;
  Node* p_next;
};

class LinkedList {
public:
  LinkedList();
  ~LinkedList();

  bool addHead(const string &key);
  FileData *retrieve(const string &key) const;
private:
  Node *p_head_;
};
