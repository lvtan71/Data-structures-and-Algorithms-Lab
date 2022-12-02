#include "include/Data.h"
#include "include/HashTable.h"
#include "include/utils.h"

void FileData::append(const string &path) {
  abs_path.emplace_back(path);
}
FolderData::FolderData() : 
  abs_path(nullptr) 
{}

FolderData::FolderData(int size) {
  abs_path = new HashTable<FileData>(size);
}

FolderData::~FolderData() {
  delete abs_path;
}

void FolderData::append(const string &path) {
  if (abs_path == nullptr) abs_path = new HashTable<FileData>(MAX_FILE_HT_SIZE);
  string key;
  if(utils::get_path_target(path, key) == utils::kFolderNFile) {
    abs_path->insertPath(key, path);
  } 
}
