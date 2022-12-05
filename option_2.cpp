#include "include/option_2.h"

void option_2::run(const string &folder_path, HashTable<FolderData> &cache) {
  string target_name;

  cout << "File name: ";
  cin >> target_name;
  if (!utils::check_valid_file(target_name)) {
    cerr << "Error: Invalid file name" << endl;
    return;
  }

  FolderData *folder_data;

  try {
    folder_data = utils::list_files_from_path(cache, folder_path);
  } catch (fs::filesystem_error const& ex) {
    cerr << "Error: Encounter invalid file or folder name while finding" << endl;
    return;
  }

  cout << "File path:" << endl;
  
  FileData *file_paths = nullptr;
  if(folder_data->retrieve(target_name, file_paths)) {
    cout << *file_paths;
  }

  utils::print_sep_line();
}
