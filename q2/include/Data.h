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

/*
 * Vector of paths
 *
 * Example: ["d:\a\xyz", "d:\b\xyz"]
 */
struct FileData : public BaseData {
  FileData() = default;
  ~FileData() = default;

  /*
   * @note assume path has utils::kFolderNFile type
   * @onerror do not append path
   */
  void append(const string &path);

  vector<string> abs_path;
};

/* 
 * HashTable: (key, value) = (file, paths)
 *
 * Example:
 *  xyz: ["d:\a\xyz", "d:\b\xyz"]
 *  123: ["d:\a\123", "d:\b\123"]
 */
struct FolderData : public BaseData {
  FolderData() = default;
  FolderData(int size);
  ~FolderData();
  
  /*
   * @note assume path has utils::kFolderNFile type
   * @onerror do not append path
   *
   * Example usage:
   *  fileData.append("d:\abc\xy")
   *  => abs_path->insertPath("xy", "d:\abc\xy")
   */
  void append(const string &path);

  HashTable<FileData> *abs_path;
};
