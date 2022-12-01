#include "include/LinkedList.h"

LinkedList::LinkedList() :
  p_head_(nullptr)
{}

bool LinkedList::isEmpty() const {
  return p_head_ == nullptr;
}

LinkedList::~LinkedList() {
  Node *cur = p_head_, *prev;
  while (cur != nullptr) {
    prev = cur;
    cur = cur->p_next;
    delete prev->p_data;
    delete prev;
  }
}

bool LinkedList::addHead(const string &key) {
  Node *new_head = new Node;
  new_head->key = key;
  new_head->p_data = new FileData;
  new_head->p_next = p_head_;
  p_head_ = new_head;
  return true;
}

bool LinkedList::retrieve(const string &key, FileData* &result) const {
  Node *cur = p_head_;
  while (cur != nullptr) {
    if (cur->key == key) {
      result = cur->p_data;
      return true;
    }
    cur = cur->p_next;
  }
  return false;
}

FileData *LinkedList::remove(const string &key) {
  if (p_head_ == nullptr) return nullptr;
  if (p_head_->key == key) {
    FileData *result = p_head_->p_data;
    Node *temp = p_head_;
    p_head_ = p_head_->p_next;

    delete temp->p_data;
  }
  
  return nullptr;
}
