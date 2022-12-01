#include <iostream>
#include <cassert>
#include "../include/HashTable.h"

using namespace std;

void test_insert_and_retrieve_path() {
  typedef HashTable<FileData> HashTable;
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
}

void test_remove_path() {
  typedef HashTable<FileData> HashTable;
  cout << "[Test] Remove path in HashTable - "; 

  HashTable ht(20);
  ht.insertPath("a", "abc");
  ht.insertPath("a", "xyz");
  ht.insertPath("b", "123");

  FileData *temp;
  assert(ht.remove("a"));
  assert(!ht.retrieve("a", temp));
  assert(ht.retrieve("b", temp));
  
  cout << "Passed" << endl;
}

int main() {
  test_insert_and_retrieve_path();
  test_remove_path();
  return 0;
}
