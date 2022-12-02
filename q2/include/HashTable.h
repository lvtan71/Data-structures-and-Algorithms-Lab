#pragma once
#include <vector>
#include <string>

// Forward declaration
template<class T>
class LinkedList;

using namespace std;
const int MAX_INT = 0x7FFFFFFF;

template<class T>
class HashTable {
typedef LinkedList<T> LinkedList;
public:
  HashTable() = default;
  HashTable(int size);
  ~HashTable();

  bool insertPath(const string &key, const string &path);
  bool retrieve(const string &key, T* &result) const;
  bool remove(const string &key);

private:
  vector<LinkedList*> table_;
  vector<string> keys_;

  // Cyclic shift hash function with:
  // + hash_value = 1,315,423,911
  // + a = 5
  // + b = 2
  int hash(string key) const;
};


