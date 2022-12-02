#pragma once
#include <vector>
#include <string>
#include "Data.h"

using namespace std;

template<class T>
class LinkedList {
public:
  LinkedList();
  ~LinkedList();

  bool isEmpty() const;
  
  bool appendPath(const string &key, const string &path);
  bool retrieve(const string &key, T* &result) const;

  // Remove the first node that match `key`
  bool remove(const string &key);
private:
  struct Node {
    string key;
    T *p_data;
    Node* p_next;
  };
  Node *p_head_;
  bool addHead(const string &key, const string &path);
};
