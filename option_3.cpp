#include "include/option_3.h"

void option_3::run(HashTable<FolderData> &cache) {
  utils::print_path_format();
  string folder_path;
  cout << "Folder path: ";
  cin >> folder_path;
  if (!utils::check_path_format(folder_path)) {
    cerr << "Error: Invalid folder path" << endl;
    return;
  }

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
  utils::print_sep_line();

  TrieNode *root = trie.getRoot();

  dfs1(root, folder_path + "\\" + ORDERED_FOLDER_NAME);

  // Because all files in `folder_path` are changed,
  // remove folder_data out of cache
  cache.remove(folder_path);
}

void option_3::dfs1(TrieNode *root, const string &folder_path, const string prefix_path) {
  if (root->num_descendent + (root->abs_path.size() != 0) <= 3) {

    string dest_path = folder_path;

    // Add a backslash to the end
    if(dest_path.back() != '\\') dest_path += "\\";

    // Cumulating characters
    string folder_name = "";
    for (const auto &ch : prefix_path) {
      folder_name += ch;
      dest_path += folder_name + "\\";
    }
    
    // Remove a trailing backslash
    dest_path.pop_back();

    dfs2(root, dest_path);
  } else {
    for (int i = 0; i < NUM_CHILD_TRIE_NODE; i++) {
      if (root->child[i] != nullptr) {
        dfs1(root->child[i], folder_path, prefix_path + VALID_CHARS[i]);
      }
    }
  }
}

void option_3::dfs2(TrieNode *root, const string &dest_path) {
  if (root->abs_path.size() != 0) {
    move_file(dest_path, root->abs_path);
  }
  for (int i = 0; i < NUM_CHILD_TRIE_NODE; i++) {
    if (root->child[i] != nullptr) {
      dfs2(root->child[i], dest_path);
    }
  }
}

void option_3::dfs1(TrieNode *root, const string &folder_path) {
  dfs1(root, folder_path, "");
}

void option_3::move_file(const string &dest_path, const string &src_path) {
  cout << "From: " << src_path << endl;
  cout << "To: " << dest_path << endl;
  utils::print_sep_line();
}
