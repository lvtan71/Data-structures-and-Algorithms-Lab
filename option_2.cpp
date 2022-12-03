#include "include/option_2.h"

void option_2(HashTable<FolderData> &cache) {
  utils::print_path_format();

  string folder_path, target_name;
  cout << "Folder path: ";
  cin >> folder_path;
  if (!utils::check_path_format(folder_path)) {
    cerr << "Error: Invalid folder path" << endl;
    return;
  }

  cout << "File name: ";
  cin >> target_name;
  if (!utils::check_valid_file(target_name)) {
    cerr << "Error: Invalid file name" << endl;
    return;
  }

  FolderData *folder_data;

  // Folder has not cached => Recursively list all files in folder
  if (!cache.retrieve(folder_path, folder_data)) {

    // Callback function executed when hit an absolute path of a file
    auto handleAppend = [&cache, &folder_path] (const string &path) {
      cache.insertPath(folder_path, path);
    };
    
    utils_::file_recursive_with_callback(folder_path, handleAppend);

    cache.retrieve(folder_path, folder_data);
  }

  cout << "File path:" << endl;
  
  FileData *file_paths = nullptr;
  if(folder_data->retrieve(target_name, file_paths)) {
    cout << *file_paths;
  }

  utils::print_sep_line();

}
