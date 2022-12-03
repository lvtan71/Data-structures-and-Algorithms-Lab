#include <iostream>
#include <cassert>
#include "../include/Trie.h"

void test_insert_file() {
  Trie tr;
  cout <<  "[Test] abs_path is an empty string - ";
  assert(!tr.insertFile("123", ""));
  cout << "Passed" << endl;

  cout << "[Test] Insert same file_name - ";
  assert(tr.insertFile("123", "abc"));
  assert(!tr.insertFile("123", "xyz"));
  cout << "Passed" << endl;
}

int main() {
  test_insert_file();
  return 0;
}
