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

  // Because all files in `folder_path` will be relocated,
  // remove folder_data out of cache
  cache.remove(folder_path);

  TrieNode *root = trie.getRoot();

  dfs1(root, folder_path + "\\" + ORDERED_FOLDER_NAME, cache);

  remove_old(folder_path);
}

void option_3::dfs1(
    TrieNode *root, 
    const string &folder_path, 
    const string prefix_path,
    HashTable<FolderData> &cache
) {
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

    dfs2(root, dest_path, cache);
  } else {
    for (int i = 0; i < NUM_CHILD_TRIE_NODE; i++) {
      if (root->child[i] != nullptr) {
        dfs1(
          root->child[i], 
          folder_path, 
          prefix_path + VALID_CHARS[i], 
          cache
        );
      }
    }
  }
}

void option_3::dfs2(
  TrieNode *root, 
  const string &dest_path,
  HashTable<FolderData> &cache
) {
  if (root->abs_path.size() != 0) {
    move_file(dest_path, root->abs_path, cache);
  }
  for (int i = 0; i < NUM_CHILD_TRIE_NODE; i++) {
    if (root->child[i] != nullptr) {
      dfs2(root->child[i], dest_path, cache);
    }
  }
}

void option_3::dfs1(
  TrieNode *root, 
  const string &folder_path,
  HashTable<FolderData> &cache
) {
  dfs1(root, folder_path, "", cache);
}

void option_3::move_file(
  const string &dest_path, 
  const string &src_path,
  HashTable<FolderData> &cache
) {
  (void)cache;
  //cout << fs::current_path() << "\n";
  cout << "From: " << src_path << endl;
  cout << "To: " << dest_path << endl;
  try {
      string file_name;
      utils::get_path_target(dest_path, file_name);
      string directory_name = dest_path.substr(dest_path.length() - file_name.length() + 1);

      fs::create_directories(directory_name);

      fs::copy(src_path, dest_path);
  }
  catch (fs::filesystem_error const& fe) {
      //
  }
  

  //string s;
  //utils::get_path_target(src_path, s);
  //cout << s << "\n";

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
