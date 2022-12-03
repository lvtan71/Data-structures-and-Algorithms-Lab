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

  FolderData *folder_data = utils::list_files_from_path(cache, folder_path);

  cout << "File path:" << endl;
  
  FileData *file_paths = nullptr;
  if(folder_data->retrieve(target_name, file_paths)) {
    cout << *file_paths;
  }

  utils::print_sep_line();

}
