#include <iostream>
#include <string>
#include "include/Data.h"
#include "include/HashTable.h"
#include "include/utils.h"
#include "include/Constants.h"
#include "include/option_1.h"
#include "include/option_2.h"
#include "include/option_3.h"

using namespace std;

bool check_input_folder_path(const string &folder_path) {
  if (!utils::check_path_format(folder_path)) {
    cerr << "Error: Invalid folder path" << endl;
    return false;
  }
  if (!fs::exists(fs::path(folder_path))) {
    cerr << "Error: Folder does not exist" << endl;
    return false;
  }
  return true;
}

int main() {
  HashTable<FolderData> cache(HT_FOLDER_MAX_SIZE);

  int opt;
  string folder_path;

  while (true) {
    utils::print_path_format();
    cout << "Disk/Folder path: ";
    cin >> folder_path;

    utils::print_sep_line();
    if (!check_input_folder_path(folder_path)) continue;
    opt = -1;
    while (opt != 4) {
      utils::print_menu();

      cout << "Option: ";
      cin >> opt;
      utils::print_sep_line();
      switch(opt) {
        case 1:
          option_1::run(folder_path, cache);
          break;
        case 2:
          option_2::run(folder_path, cache);
          break;
        case 3:
          option_3::run(folder_path, cache);
          break;
        case 4:
          break;
        case 0:
          return 0;
        default:
          cerr << "Error: Invalid option" << endl;
      }
    }
  }
  return 0;
}
