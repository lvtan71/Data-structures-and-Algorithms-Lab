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
  
  bool appendPath(const string &key, const string &path);
  bool retrieve(const string &key, FileData* &result) const;

  // Remove the first node that match `key`
  bool remove(const string &key, FileData &result, bool return_value);
private:
  Node *p_head_;
  bool addHead(const string &key, const string &path);
};
