#include <iostream>
#include <cassert>
#include "../include/LinkedList.h"

using namespace std;

void test_add_and_retrieve() {
  cout << "[Test] Add and retrieve node in linked list - ";

  LinkedList L;
  L.addHead("a");
  L.addHead("b");
  L.addHead("c");

  FileData *result;
  assert(L.retrieve("b", result));
  assert(!L.retrieve("d", result));

  cout << "Passed" << endl;
}

void test_add_and_retrieve_2() {
  cout << "[Test] Add using addHead method overloaded with 3 parameters - "; 

  LinkedList L;
  L.addHead("a");
  L.addHead("b", "xyz");
  L.addHead("c");

  FileData *result;
  assert(L.retrieve("b", result));
  assert(result->abs_path.size() == 1);
  assert(result->abs_path[0] == "xyz");

  cout << "Passed" << endl;
}

void test_remove() {
  LinkedList L;
  L.addHead("a");
  L.addHead("b");
  L.addHead("c");
  L.addHead("d");
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
  LinkedList L;
  L.addHead("a");
  L.addHead("b");

  cout << "[Test] Retrieve node -> Add Data -> Remove Node - ";

  FileData *p_result, result;

  assert(L.retrieve("b", p_result));
  p_result->abs_path.push_back("ok");

  assert(L.remove("b", result, true));
  assert(result.abs_path.size() == 1);
  assert(result.abs_path[0] == "ok");

  cout << "Passed";
}

int main() {
  test_add_and_retrieve();
  test_add_and_retrieve_2();
  test_remove();
  test_integration_1();
  return 0;
}
