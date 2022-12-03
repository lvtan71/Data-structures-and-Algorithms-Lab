#include <iostream>
#include <string>
#include "include/Data.h"
#include "include/HashTable.h"
#include "include/utils.h"
#include "include/utils_.h"
using namespace std;

const int HT_FOLDER_MAX_SIZE = 20;

int main() {
  HashTable<FolderData> ht(HT_FOLDER_MAX_SIZE);

  utils::print_path_format();
  string folder, target;

  cout << "Folder link: ";
  cin >> folder;
  if (!utils::check_path_format(folder)) {
    cerr << "Error: Invalid folder link" << endl;
    return 1;
  }
  cout << "File name: ";
  cin >> target;
  if (!utils::check_valid_file(target)) {
    cerr << "Error: Invalid file name" << endl;
    return 1;
  }
  
  auto handleAppend = [&ht, &folder] (const string &path) {
    ht.insertPath(folder, path);
  };

  utils_::file_recursive_with_callback(folder, handleAppend);

  FolderData *res1;
  ht.retrieve(folder, res1);

  FileData *res2;  
  res1->retrieve(target, res2);

  cout << *res2;

  return 0;
}
