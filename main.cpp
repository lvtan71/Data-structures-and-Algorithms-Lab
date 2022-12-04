#include <iostream>
#include <string>
#include "include/Data.h"
#include "include/HashTable.h"
#include "include/utils.h"
#include "include/utils_.h"
#include "include/Constants.h"
#include "include/option_1.h"
#include "include/option_2.h"
#include "include/option_3.h"

using namespace std;

int main() {
  HashTable<FolderData> cache(HT_FOLDER_MAX_SIZE);

  int opt;
  while (true) {
    utils::print_menu();
    cout << "Option: ";
    cin >> opt;
    utils::print_sep_line();
    switch(opt) {
      case 1:
        option_1::run(cache);
        break;
      case 2:
        option_2(cache);
        break;
      case 3:
        option_3(cache);
        break;
      case 0:
        return 0;
      default:
        cerr << "Error: Invalid option" << endl;
    }
  }

  return 0;
}
