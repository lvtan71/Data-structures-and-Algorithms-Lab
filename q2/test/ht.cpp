#include <iostream>
#include <cassert>
#include "../include/Data.h"
#include "../include/LinkedList.h"
#include "../include/HashTable.h"

using namespace std;

void test_insert_and_retrieve_path() {
  typedef HashTable<FileData> HashTable;
  cout << "[Test] Insert and retrieve path in HashTable - "; 
  HashTable ht(20);
  ht.insertPath("a", "d:\\abc");
  ht.insertPath("a", "d:\\xyz");
  ht.insertPath("b", "d:\\123");

  FileData *result;      
  ht.retrieve("a", result);

  assert(result->abs_path.size() == 2);
  assert(result->abs_path[0] == "d:\\abc");
  assert(result->abs_path[1] == "d:\\xyz");

  ht.retrieve("b", result);
  assert(result->abs_path[0] == "d:\\123");
  cout << "Passed" << endl;
}

void test_insert_invalid_path() {
  typedef HashTable<FileData> HashTable;
  cout << "[Test] Insert in valid path to HashTable - ";
  HashTable ht(20);

  ht.insertPath("a", "xyz");
  FileData *result;
  assert(!ht.retrieve("a", result));

  cout << "Passed" << endl;
}

void test_remove_path() {
  typedef HashTable<FileData> HashTable;
  cout << "[Test] Remove path in HashTable - "; 

  HashTable ht(20);
  ht.insertPath("a", "d:\\abc");
  ht.insertPath("a", "d:\\xyz");
  ht.insertPath("b", "d:\\123");

  FileData *temp;
  assert(ht.remove("a"));
  assert(!ht.retrieve("a", temp));
  assert(ht.retrieve("b", temp));
  
  cout << "Passed" << endl;
}


void test_insert_and_retrieve_hash_table_folder_data() {
  cout << "[Test] Insert and retrieve in HashTable with FolderData - ";
  HashTable<FolderData> ht(20);

  assert(ht.insertPath("d:\\", "d:\\a\\b"));

  assert(ht.insertPath("d:\\", "d:\\a\\c\\b"));

  FolderData *res1;
  assert(ht.retrieve("d:\\", res1));

  FileData *res2;
  assert(res1->abs_path->retrieve("b", res2));

  assert(res2->abs_path.size() == 2);
  assert(res2->abs_path[0] == "d:\\a\\b");
  assert(res2->abs_path[1] == "d:\\a\\c\\b");

  cout << "Passed" << endl;
}

void test_hash_table_keys() {
  cout << "[Test] HashTable keys - ";
  HashTable<FolderData> ht(20);

  assert(ht.insertPath("d:\\", "d:\\a\\b"));
  assert(ht.insertPath("e:\\", "d:\\a"));
  assert(ht.insertPath("e:\\", "d:\\c"));

  assert(ht.keys.size() == 2);
  assert(ht.keys[0] == "d:\\");
  assert(ht.keys[1] == "e:\\");

  cout << "Passed" << endl;
}

void test_remove_hash_table_folder_data() {
  cout << "[Test] Remove in HashTable with FolderData - ";
  HashTable<FolderData> ht(20);

  assert(ht.insertPath("d:\\", "d:\\a\\b"));
  assert(ht.insertPath("e:\\", "d:\\a"));
  assert(ht.insertPath("e:\\", "d:\\c"));

  assert(ht.remove("e:\\"));

  FolderData *res1;
  assert(!ht.retrieve("e:\\", res1));
  assert(!ht.remove("e:\\"));

  assert(ht.retrieve("d:\\", res1));

  FileData *res2;
  assert(res1->abs_path->retrieve("b", res2));

  assert(res2->abs_path.size() == 1);
  assert(res2->abs_path[0] == "d:\\a\\b");

  cout << "Passed" << endl;
}

int main() {
  test_insert_and_retrieve_path();
  test_insert_invalid_path();
  test_remove_path();

  test_insert_and_retrieve_hash_table_folder_data();
  test_hash_table_keys();
  test_remove_hash_table_folder_data();
  return 0;
}
