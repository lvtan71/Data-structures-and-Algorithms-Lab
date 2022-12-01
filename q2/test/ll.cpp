#include <iostream>
#include <cassert>
#include "../include/LinkedList.h"

using namespace std;

void test_add_and_retrieve() {
  typedef LinkedList<FileData> LinkedList;
  cout << "[Test] Add and retrieve node in linked list - ";

  LinkedList L;
  L.appendPath("a", "1");
  L.appendPath("b", "2");
  L.appendPath("c", "3");

  FileData *result;
  assert(L.retrieve("b", result));

  assert(result->abs_path.size() == 1);
  assert(result->abs_path[0] == "2");

  cout << "Passed" << endl;
}

void test_retrieve_not_exist_key() {
  typedef LinkedList<FileData> LinkedList;
  cout << "[Test] Retrieve key that is not exist - ";

  LinkedList L;
  L.appendPath("a", "1");
  L.appendPath("b", "2");
  L.appendPath("c", "3");

  FileData *result;
  assert(!L.retrieve("d", result));

  cout << "Passed" << endl;
}

void test_add_same_key() {
  cout << "[Test] Add multiple paths to same key - ";
  typedef LinkedList<FileData> LinkedList;
  LinkedList L;
  L.appendPath("a", "1");
  L.appendPath("a", "2");
  L.appendPath("a", "3");

  FileData *result;
  assert(L.retrieve("a", result));
  assert(result->abs_path.size() == 3);
  assert(result->abs_path[0] == "1");
  assert(result->abs_path[1] == "2");
  assert(result->abs_path[2] == "3");

  cout << "Passed" << endl;
}

void test_remove() {
  typedef LinkedList<FileData> LinkedList;
  LinkedList L;
  L.appendPath("a", "1");
  L.appendPath("b", "2");
  L.appendPath("c", "3");
  L.appendPath("d", "4");

  cout << "[Test] Remove head in linked list - ";
  assert(L.remove("a"));
  cout << "Passed" << endl;

  cout << "[Test] Remove node not in linked list - ";
  assert(!L.remove("a"));
  cout << "Passed" << endl;

  cout << "[Test] Empty the list - ";
  assert(L.remove("d"));
  assert(L.remove("c"));
  assert(L.remove("b"));
  assert(L.isEmpty());
  cout << "Passed" << endl;
}

int main() {
  test_add_and_retrieve();
  test_retrieve_not_exist_key();
  test_remove();
  return 0;
}
