#include "include/Data.h"
#include "include/HashTable.h"
#include "include/utils.h"

void FileData::append(const string &path) {
  abs_path.emplace_back(path);
}

ostream& operator<<(ostream &stream, const FileData &rhs) {
  for(const auto &path : rhs.abs_path) {
    stream << path << endl;
  }
  return stream;
}

FolderData::FolderData() : 
  abs_path(nullptr) 
{}

FolderData::~FolderData() {
  delete abs_path;
}

void FolderData::append(const string &path) {
  if (abs_path == nullptr) abs_path = new HashTable<FileData>(HT_FILE_MAX_SIZE);
  string key;
  if(utils::get_path_target(path, key) == utils::kFolderNFile) {
    abs_path->insertPath(key, path);
  } 
}

bool FolderData::retrieve(const string &key, FileData* &result) {
  if (abs_path != nullptr) {
    return abs_path->retrieve(key, result);
  }
  return false;
}
