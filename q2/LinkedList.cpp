#include "include/LinkedList.h"
#include "include/Data.h"

template<class T>
LinkedList<T>::LinkedList() :
  p_head_(nullptr)
{}

template<class T>
bool LinkedList<T>::isEmpty() const {
  return p_head_ == nullptr;
}

template<class T>
LinkedList<T>::~LinkedList() {
  Node *cur = p_head_, *prev;
  while (cur != nullptr) {
    prev = cur;
    cur = cur->p_next;
    delete prev->p_data;
    delete prev;
  }
}

template<class T>
bool LinkedList<T>::addHead(const string &key, const string &path) {
  Node *new_head = new Node;

  new_head->key = key;

  new_head->p_data = new T;
  new_head->p_data->append(key, path);

  new_head->p_next = p_head_;

  p_head_ = new_head;
  return true;
}

template<class T>
bool LinkedList<T>::appendPath(const string &key, const string &path) {
  T *data;
  if (retrieve(key, data)) data->append(key, path);
  else addHead(key, path);

  return true;
}

template<class T>
bool LinkedList<T>::retrieve(const string &key, T* &result) const {
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

template<class T>
bool LinkedList<T>::remove(const string &key) {
  if (p_head_ == nullptr) return false;

  if (p_head_->key == key) {

    Node *temp = p_head_;
    p_head_ = p_head_->p_next;
    
    delete temp->p_data;
    delete temp;

    return true;
  }

  Node *cur = p_head_;
  while (cur->p_next != nullptr) {
    if (cur->p_next->key == key) {

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

template class LinkedList<FileData>;
