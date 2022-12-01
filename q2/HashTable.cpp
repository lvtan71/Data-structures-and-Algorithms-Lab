#include "include/HashTable.h"

HashTable::HashTable(int size) :
  table_(std::move(vector<LinkedList*>(size, nullptr)))
{}

HashTable::~HashTable() {
  for (auto &l : table_) delete l;
}

// Implement Cyclic shift hash
int HashTable::hash(string key) {
  int hashValue = 1315423911;
  int a = 5, b = 2;
  for (int i = 0; i < key.size(); i++) {
    int x = hashValue << a & MAX_INT;
    int y = hashValue >> b & MAX_INT;
    hashValue ^= (x + key[i] + y) & MAX_INT;
  }
  return (hashValue & MAX_INT) % table_.size();
}

bool HashTable::insertPath(const string &key, const string &path) {
  int idx = hash(key);   

  if (table_[idx] == nullptr) {
    table_[idx] = new LinkedList;
    table_[idx]->addHead(key, path);
    return true;
  }

  FileData *temp;
  // key has already existed
  if (table_[idx]->retrieve(key, temp)) {
    return false;
  }

  table_[idx]->addHead(key, path);
  return true;
}
