#pragma once
#include <vector>
#include <string>
#include "Constants.h"

// Forward declaration
template<class T>
class LinkedList;

using namespace std;

template<class T>
class HashTable {
public:
  HashTable() = default;
  HashTable(int size);
  ~HashTable();

  bool insertPath(const string &key, const string &path);
  bool retrieve(const string &key, T* &result) const;
  bool remove(const string &key);

  vector<string> keys;
private:
  vector<LinkedList<T>*> table_;

  // Cyclic shift hash function with:
  // + hash_value = 1,315,423,911
  // + a = 5
  // + b = 2
  int hash(const string &key) const;
};


