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

  assert(L.retrieve("b") != nullptr);
  assert(L.retrieve("d") == nullptr);

  cout << "Passed!" << endl;
}

int main() {
  test_add_and_retrieve();
  return 0;
}
