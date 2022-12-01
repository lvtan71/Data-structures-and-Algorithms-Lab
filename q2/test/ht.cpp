#include <iostream>
#include <cassert>
#include "../include/HashTable.h"

using namespace std;

void test_insert_and_retrieve_path() {
  cout << "[Test] Insert and retrieve path in HashTable - "; 
  HashTable ht(20);
  ht.insertPath("a", "abc");
  ht.insertPath("a", "xyz");
  ht.insertPath("b", "123");

  FileData *result;      
  ht.retrieve("a", result);

  assert(result->abs_path.size() == 2);
  assert(result->abs_path[0] == "abc");
  assert(result->abs_path[1] == "xyz");

  ht.retrieve("b", result);
  assert(result->abs_path[0] == "123");
  cout << "Passed" << endl;
  cout << "Passed" << endl;
}

int main() {
  test_insert_and_retrieve_path();
  return 0;
}
