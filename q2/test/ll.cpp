#include <iostream>
#include <cassert>
#include "../include/LinkedList.h"

using namespace std;

void test_add_and_retrieve() {
  cout << "[Test] Add and retrieve node in linked list" << endl;

  LinkedList L;
  L.addHead("a");
  L.addHead("b");
  L.addHead("c");

  FileData *result;
  assert(L.retrieve("b", result));
  assert(!L.retrieve("d", result));

  cout << "Passed!" << endl;
}

int main() {
  test_add_and_retrieve();
  return 0;
}
