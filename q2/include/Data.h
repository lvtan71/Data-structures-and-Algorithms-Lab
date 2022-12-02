#pragma once
#include <vector>
#include <string>

using namespace std;

// Forward declaration
template <class T>
class HashTable;

struct BaseData {
  virtual ~BaseData() {};
  virtual void append(const string &path) = 0;
};

struct FileData : public BaseData {
  FileData() = default;
  ~FileData() = default;
  void append(const string &path);

  vector<string> abs_path;
};
struct FolderData : public BaseData {
  FolderData() = default;
  FolderData(int size);
  ~FolderData();
  
  HashTable<FileData> *abs_path;
};
