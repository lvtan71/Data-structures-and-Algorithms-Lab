#include "include/HashTable.h"

HashTable::HashTable(int size) :
  size_(size),
  table_(std::move(vector<LinkedList*>(size)))
{}

// Implement Cyclic shift hash
int HashTable::hash(string key) {
  int hashValue = 1315423911;
  int a = 5, b = 2;
  for (int i = 0; i < key.size(); i++) {
    int x = hashValue << a & MAX_INT;
    int y = hashValue >> b & MAX_INT;
    hashValue ^= (x + key[i] + y) & MAX_INT;
  }
  return (hashValue & MAX_INT) % size_;
}
