#include "include/option_3.h"
#include<string>

void option_3::run(const string &folder_path, HashTable<FolderData> &cache) {
  FolderData *folder_data;

  try {
    folder_data = utils::list_files_from_path(cache, folder_path);
  } catch (fs::filesystem_error const& ex) {
    cerr << "Error: Encounter invalid file or folder name while reordering" << endl;
    return;
  }

  if (folder_data == nullptr) {
    return;
  }

  Trie trie;

  FileData *file_data;
  for (auto &key : folder_data->abs_path->keys) {
    folder_data->retrieve(key, file_data);

    // Same file name but in different folders
    // => Add absolute path (without ":", "\" and filename ) to the end of file name
    // Note: Still keep file extension
    //
    // Example:
    //
    // File name: abc
    // Absolute paths:
    // + d:\x\abc
    // + d:\y\abc
    //
    // => abc_dx
    // => abc_dy
    //
    // File name: abc.txt
    // Absolute paths:
    // + d:\x\abc.txt
    // + d:\y\abc.txt
    //
    // => abc_dx.txt
    // => abc_dy.txt
    //
    if (file_data->abs_path.size() > 1) {
      int dot_pos = key.size() - 1;
      while(dot_pos >= 0 && key[dot_pos] != '.' && key[dot_pos] != '\\') dot_pos--;
      if (key[dot_pos] == '\\') dot_pos = -1;

      for (auto &path : file_data->abs_path) {
        string tag = path.substr(0, (int)path.size() - (int)key.size());

        // The implementation of insertFile method of trie ignores ":" and "\"

        if (dot_pos != -1) { // File with extension
          string new_file_name = key.substr(0, dot_pos) + "_" + tag + key.substr(dot_pos);
          trie.insertFile(new_file_name, path);
        } 
        else { //File without extension
          trie.insertFile(key + "_" + tag, path);
        }
      }
    }
    else {
      trie.insertFile(key, file_data->abs_path[0]);
    }
  }

  // Because all files in `folder_path` will be relocated,
  // remove folder_data out of cache
  cache.remove(folder_path);

  TrieNode *root = trie.getRoot();

  dfs_solve_request(root, folder_path + "\\" + ORDERED_FOLDER_NAME, cache);

  // remove_old(folder_path);
}

void option_3::dfs_solve_request(
    TrieNode *root, 
    const string &folder_path, 
    const string prefix_path,
    HashTable<FolderData> &cache
) {
  if (
    root->abs_path.size() != 0 ||
    root->num_descendent + (root->abs_path.size() != 0) <= 3
  ) {
    string dest_path = folder_path;

    // Add a backslash to the end
    if(dest_path.back() != '\\') dest_path += "\\";

    // Cumulating characters
    string folder_name = "";
    for (const auto &ch : prefix_path) {
      folder_name += ch;
      dest_path += folder_name + "\\";
    }

    dest_path += prefix_path;

    if (root->abs_path.size() != 0) {
      move_file(dest_path, root->abs_path, cache);
    }

    for (int i = 0; i < NUM_CHILD_TRIE_NODE; i++) {
      if (root->child[i] != nullptr) {
        dfs_listing_in(root->child[i], dest_path + VALID_CHARS[i], cache);
      }
    }

  } else {
    for (int i = 0; i < NUM_CHILD_TRIE_NODE; i++) {
      if (root->child[i] != nullptr) {
        dfs_solve_request(
          root->child[i], 
          folder_path, 
          prefix_path + VALID_CHARS[i], 
          cache
        );
      }
    }
  }
}

void option_3::dfs_listing_in(
  TrieNode *root, 
  string dest_path,
  HashTable<FolderData> &cache
) {
  if (root->abs_path.size() != 0) {
    move_file(dest_path, root->abs_path, cache);
  }
  for (int i = 0; i < NUM_CHILD_TRIE_NODE; i++) {
    if (root->child[i] != nullptr) {
      dfs_listing_in(root->child[i], dest_path + VALID_CHARS[i], cache);
    }
  }
}

void option_3::dfs_solve_request(
  TrieNode *root, 
  const string &folder_path,
  HashTable<FolderData> &cache
) {
  dfs_solve_request(root, folder_path, "", cache);
}

void option_3::move_file(
  const string &dest_path, 
  const string &src_path,
  HashTable<FolderData> &cache
) {
  (void)cache;
  cout << "From: " << src_path << endl;
  cout << "To: " << dest_path << endl;
  try {
      string file_name;
      utils::get_path_target(dest_path, file_name);
      string directory_name = dest_path.substr(0,dest_path.length() - file_name.length() - 1);

      fs::create_directories(directory_name);

      fs::copy(src_path, dest_path);
  }
  catch (fs::filesystem_error const& fe) {
    cerr << "Error: An error occours when moving files" << endl;
  }
  utils::print_sep_line();
}

void option_3::remove_old(string folder_path) {
    fs::current_path(folder_path);
    for (const auto& entry : fs::directory_iterator(folder_path)) {
        string remove = entry.path().filename().string();
        if (remove!="OrderedFolder") {
            fs::remove_all(remove);
        }
    }
}
