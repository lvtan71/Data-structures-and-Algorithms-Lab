#include "include/option_3.h"

void option_3(HashTable<FolderData> &cache) {
  utils::print_path_format();
  string folder_path;
  cout << "Folder path: ";
  cin >> folder_path;

  FolderData *folder_data = utils::list_files_from_path(cache, folder_path);
}
