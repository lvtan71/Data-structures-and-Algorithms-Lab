#include "include/option_1.h"

void option_1::run(HashTable<FolderData> &cache) {
  utils::print_path_format();

  cout << "Note: maximum depth for directory tree is 64" << endl;
  utils::print_sep_line();

  string folder_path;
  cout << "Folder path: ";
  cin >> folder_path;
  if (!utils::check_path_format(folder_path)) {
    cerr << "Error: Invalid folder path" << endl;
    return;
  }

  utils::print_sep_line();

  if (!fs::exists(fs::path(folder_path))) {
    cerr << "Error: Folder does not exist" << endl;
    utils::print_sep_line();
    return;
  }

  option_1::print_directory_tree(folder_path, cache);
  utils::print_sep_line();
}

void option_1::dfs(
  const fs::path &path, 
  int level, 
  AncestorInfo info,
  const string &folder_path,
  HashTable<FolderData> &cache
) {
  if (level > MAX_DIRECTORY_TREE_DEPTH) return;

  // Number of files at the same level
  int num_file = std::distance(fs::directory_iterator(path), fs::directory_iterator{});
  int count = 0;

  for (const auto &entry : fs::directory_iterator(path)) {
    count++;
    print_file(entry.path().filename().string(), level+1, info);

    if (entry.is_directory()) {
      dfs(
        entry.path(),
        level+1,
        (level == -1 ? 0 : info | ((count == num_file) << level)),
        folder_path,
        cache
      );
    }
    else {
      // Caching
      cache.insertPath(folder_path, entry.path().string());
    }
  } 
}

void option_1::print_file(
  const string &name, 
  int level, 
  AncestorInfo info
) {
  if (level == 0) {
    cout << name << endl;
    return;
  } 
  
  for (int pos = 0; pos < level-1; pos++) {
    cout << (((info>>pos) & 1) ? CLOSE_SYSMBOL : OPEN_SYSMBOL);
  }

  cout << END_SYSMBOL << name << endl;
}

void option_1::print_directory_tree(
  string folder_path, 
  HashTable<FolderData> &cache
) {
  dfs(fs::path(folder_path), -1, 0, folder_path, cache);
}

