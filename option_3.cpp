#include "include/option_3.h"

void option_3(HashTable<FolderData> &cache) {
  utils::print_path_format();
  string folder_path;
  cout << "Folder path: ";
  cin >> folder_path;

  FolderData *folder_data = utils::list_files_from_path(cache, folder_path);

  Trie trie;

  FileData *file_data;
  for (auto &key : folder_data->abs_path->keys) {
    folder_data->retrieve(key, file_data);

    // Same file name but in different folders
    // => Add absolute path (with ":" and "\" removed) to the end of file name
    //
    // Example:
    //
    // File name: abc
    // Absolute paths:
    // + d:\x\abc
    // + d:\y\abc
    //
    // => abc_dxabc
    // => abc_dyabc
    if (file_data->abs_path.size() > 1) {
      for (auto &path : file_data->abs_path) {
        // The implementation of insertFile method of trie ignores ":" and "\"
        trie.insertFile(key + "_" + path, path);
      }
    }
    else {
      trie.insertFile(key, file_data->abs_path[0]);
    }
  }
}
