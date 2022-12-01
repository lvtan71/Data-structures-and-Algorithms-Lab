#pragma once
#include "LinkedList.h"

using namespace std;
const int MAX_INT = 0x7FFFFFFF;

class HashTable {
public:
  HashTable() = default;
  HashTable(int size);
  ~HashTable();

  bool insertPath(const string &key, const string &path);
  bool retrieve(const string &key, FileData* &result) const;

private:
  vector<LinkedList*> table_;

  // Cyclic shift hash function with:
  // + hash_value = 1,315,423,911
  // + a = 5
  // + b = 2
  int hash(string key) const;
};


