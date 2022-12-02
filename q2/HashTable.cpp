#include "include/Data.h"
#include "include/LinkedList.h"
#include "include/HashTable.h"
#include "include/utils.h"

template<class T>
HashTable<T>::HashTable(int size) :
  table_(std::move(vector<LinkedList*>(size, nullptr)))
{}

template<class T>
HashTable<T>::~HashTable() {
  int idx;
  for (auto &key : keys_) {
    idx = hash(key);
    delete table_[idx];
    // Two keys may have the same idx in table_
    table_[idx] = nullptr;
  }
}

// Implement Cyclic shift hash
template<class T>
int HashTable<T>::hash(string key) const {
  int hashValue = 1315423911;
  int a = 5, b = 2;
  for (int i = 0; i < (int)key.size(); i++) {
    int x = hashValue << a & MAX_INT;
    int y = hashValue >> b & MAX_INT;
    hashValue ^= (x + key[i] + y) & MAX_INT;
  }
  return (hashValue & MAX_INT) % table_.size();
}

template<class T>
bool HashTable<T>::insertPath(const string &key, const string &path) {
  string temp;
  if (utils::get_path_target(path, temp) != utils::kFolderNFile) return false;

  int idx = hash(key);   

  if (table_[idx] == nullptr) {
    table_[idx] = new LinkedList;
  }

  if (table_[idx]->appendPath(key, path)) keys_.push_back(key);

  return true;
}

template<class T>
bool HashTable<T>::retrieve(const string &key, T* &result) const {
  int idx = hash(key);
  if (table_[idx] == nullptr) return false;
  return table_[idx]->retrieve(key, result);
}

template<class T>
bool HashTable<T>::remove(const string &key) {
  int idx = hash(key);
  if (table_[idx] == nullptr) return false;
  return table_[idx]->remove(key);
}

template class HashTable<FileData>;
template class HashTable<FolderData>;
