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

  bool isEmpty() const;

  bool addHead(const string &key);
  bool retrieve(const string &key, FileData* &result) const;
  FileData *remove(const string &key);
private:
  Node *p_head_;
};
