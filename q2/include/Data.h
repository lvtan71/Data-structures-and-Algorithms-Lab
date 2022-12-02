#pragma once
#include <vector>
#include <string>

using namespace std;

struct BaseData {
  virtual ~BaseData() {};
  virtual void append(const string &key, const string &path) = 0;
};

struct FileData : public BaseData {
  FileData() = default;
  ~FileData() = default;
  void append(const string &key, const string &path);
  vector<string> abs_path;
};
