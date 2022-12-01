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

bool LinkedList::addHead(const string &key, const string &path) {
  Node *new_head = new Node;

  new_head->key = key;

  new_head->p_data = new FileData;
  new_head->p_data->abs_path.emplace_back(path);

  new_head->p_next = p_head_;

  p_head_ = new_head;
  return true;
}

bool LinkedList::appendPath(const string &key, const string &path) {
  FileData *data;
  if (retrieve(key, data)) data->abs_path.emplace_back(path);
  else addHead(key, path);

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

bool LinkedList::remove(const string &key, FileData &result, bool return_value) {
  if (p_head_ == nullptr) return false;

  if (p_head_->key == key) {
    if (return_value) result = *(p_head_->p_data);

    Node *temp = p_head_;
    p_head_ = p_head_->p_next;
    
    delete temp->p_data;
    delete temp;

    return true;
  }

  Node *cur = p_head_;
  while (cur->p_next != nullptr) {
    if (cur->p_next->key == key) {
      if (return_value) result = *(cur->p_next->p_data);

      Node *temp = cur->p_next;
      cur->p_next = cur->p_next->p_next;

      delete temp->p_data;
      delete temp;

      return true;
    }

    cur = cur->p_next;
  }
  return false;
}
