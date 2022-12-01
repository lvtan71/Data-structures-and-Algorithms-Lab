#include "include/LinkedList.h"

LinkedList::LinkedList() :
  p_head_(nullptr)
{}

LinkedList::~LinkedList() {
  Node *cur = p_head_, *prev;
  while (cur != nullptr) {
    prev = cur;
    cur = cur->p_next;
    delete prev->p_data;
    delete prev;
  }
}

bool LinkedList::addHead(string key) {
  Node *new_head = new Node;
  new_head->key = key;
  new_head->p_data = new FileData;
  new_head->p_next = p_head_;
  p_head_ = new_head;
  return true;
}
