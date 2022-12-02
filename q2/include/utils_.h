#pragma once
#include <string>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

namespace utils_ {
  // List files in `dir` recursive with callback
  template<class T>
  void file_recursive_with_callback(
      const string &dir, 
      T callback
  ) {
    for (const auto &entry : fs::recursive_directory_iterator(dir)) {
      if (!fs::is_directory(entry)) {
        callback(entry.path().string());
      }
    }
  }
}
