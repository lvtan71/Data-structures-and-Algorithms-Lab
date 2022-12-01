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

void test_remove() {
  typedef LinkedList<FileData> LinkedList;
  LinkedList L;
  L.appendPath("a", "1");
  L.appendPath("b", "2");
  L.appendPath("c", "3");
  L.appendPath("d", "4");
  FileData result;

  cout << "[Test] Remove head in linked list - ";
  assert(L.remove("a", result, false));
  cout << "Passed" << endl;

  cout << "[Test] Remove node not in linked list - ";
  assert(!L.remove("a", result, false));
  cout << "Passed" << endl;

  cout << "[Test] Empty the list - ";
  assert(L.remove("d", result, false));
  assert(L.remove("c", result, false));
  assert(L.remove("b", result, false));
  assert(L.isEmpty());
  cout << "Passed" << endl;
}

void test_integration_1() {
  typedef LinkedList<FileData> LinkedList;
  LinkedList L;
  L.appendPath("a", "1");
  L.appendPath("b", "2");

  cout << "[Test] Retrieve node -> Add Data -> Remove Node - ";

  FileData *p_result, result;

  assert(L.retrieve("b", p_result));
  p_result->abs_path.push_back("ok");

  assert(L.remove("b", result, true));
  assert(result.abs_path.size() == 2);
  assert(result.abs_path.back() == "ok");

  cout << "Passed" << endl;
}

int main() {
  test_add_and_retrieve();
  test_retrieve_not_exist_key();
  test_remove();
  test_integration_1();
  return 0;
}
