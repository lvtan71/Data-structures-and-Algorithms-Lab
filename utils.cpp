#include <iostream>
#include "include/utils.h"

void utils::print_sep_line() {
  cout << "-------------------------------------------------" << endl;
}

void utils::print_menu() {
  cout << "Option 1: Print directory tree (maximum depth is 64)" << endl;  
  cout << "Option 2: Find a file" << endl;
  cout << "Option 3: Reoreder files" << endl;
  cout << "Option 4: Choose another starting directory" << endl;
  cout << "Option 0: Exit" << endl;
  utils::print_sep_line();
}

void utils::print_path_format() {
  cout << "Disk path format: " << endl;
  cout << "<Disk>:\\" << endl;
  cout << "Folder path format: " << endl;
  cout << "<Disk>:\\<Folder1>\\<Folder2>" << endl;
  cout << "File path format: " << endl;
  cout << "<Disk>:\\<Folder1>\\<File>" << endl;
  cout << "Name of disk, folder and file is not empty and only contains: " << endl;
  cout << "\t + Numbers [0-9]" << endl;
  cout << "\t + Alphabet letters [a-z] [A-Z]" << endl;
  cout << "\t + Special characters:" << endl;
  cout << "\t\t _ (underscore)" << endl;
  cout << "\t\t . (dot)" << endl;
  cout << "\t\t - (minus)" << endl;
  cout << "\t\t ( (open bracket)" << endl;
  cout << "\t\t ) (close bracket)" << endl;
  utils::print_sep_line();
}

bool utils::check_valid_character(const char &ch) {
  return (
    ('0' <= ch && ch <= '9') ||
    ('a' <= ch && ch <= 'z') ||
    ('A' <= ch && ch <= 'Z') ||
    ch == '.' ||
    ch == '_' ||
    ch == '-'
  );
}

bool utils::check_path_format(const string &path) {
  if (path.size() == 0 || path[0] == '\\' || path[0] == ':') return false;
  int i;
  for (i=0; i < (int)path.size(); i++) {
    if (path[i] == '\\') return false;
    if (path[i] == ':') break;

    if (!utils::check_valid_character(path[i])) return false;
  }
  i++;
  if (i >= (int)path.size() || path[i] != '\\') return false;
  if (i == (int)path.size() - 1) return true;

  for (; i < (int)path.size() - 1; i++) {
    if (
      (!utils::check_valid_character(path[i+1]) && path[i+1] != '\\') ||
      (path[i] == '\\' && path[i+1] == '\\')
    ) return false;
  }

  return path.back() != '\\';
}
bool utils::check_valid_file(const string &file) {
  for (const auto &ch : file) if (!utils::check_valid_character(ch)) return false;
  return true; 
}

utils::PathType utils::get_path_target(const string &path, string &result) {
  if (!utils::check_path_format(path)) return utils::kUndefined;
  // Disk
  int length = path.size();
  if (path.back() == '\\') {
    result = path.substr(0, length-2);
    return utils::kDisk;
  }
  
  while (path[--length] != '\\');

  result = path.substr(length+1);
  return utils::kFolderNFile;
}

FolderData *utils::list_files_from_path(
    HashTable<FolderData> &cache, 
    const string &folder_path
) {
  FolderData *folder_data = nullptr;
  // Folder has not cached => Recursively list all files in folder
  if (!cache.retrieve(folder_path, folder_data)) {

    for (const auto &entry : fs::recursive_directory_iterator(folder_path)) {
      if (!fs::is_directory(entry)) {
        cache.insertPath(folder_path, entry.path().string());
      }
    }
    cache.retrieve(folder_path, folder_data);
  }
  return folder_data;
}
