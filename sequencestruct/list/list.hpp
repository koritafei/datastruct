/**
 * @file list.hpp
 * @author koritafei (koritafei@gmail.com)
 * @brief 链表定义
 * @version 0.1
 * @date 2020-08-25
 *
 * @copyright Copyright (c) 2020
 *
 */

#ifndef __LIST__H__
#define __LIST__H__

#include <iostream>

template <typename T>
class List {
private:
  struct Node {
    T     data_;
    Node *prev_;
    Node *next_;

    Node(const T &d = T(), Node *p = nullptr, Node *n = nullptr)
        : data_(d),
          prev_(p),
          next_(n) {
    }
  };

public:
  class const_iterator {
  public:
    const_iterator() : current(nullptr) {
    }

    const T &operator*() const {
      return retrive();
    }

    const_iterator operator++(int) {
      const_iterator *old = this;
      ++(*this);
      return old;
    }

    bool operator==(const const_iterator &rhs) const {
      return current == rhs.curent;
    }

    bool operator!=(const const_iterator &rhs) const {
      return !(*this == rhs);
    }

  protected:
    Node *current;
    T &   retrive() const {
      return current->data_;
    }
    const_iterator(Node *p) : current(p) {
    }

    friend class List<T>;
  };

  class iterator : public const_iterator {
  public:
    iterator() {
    }

    T &operator*() {
      return const_iterator::retrive();
    }

    const T &operator*() const {
      return const_iterator::operator*();
    }

    iterator &operator++() {
      const_iterator::current = const_iterator::current->next;
      return *this;
    }

    iterator operator++(int) {
      iterator old = *this;
      ++(*this);
      return old;
    }

  protected:
    iterator(Node *p) : const_iterator(p) {
    }
    friend class List<T>;
  };

  List() {
    init();
  }

  ~List() {
    clear();
    delete head_;
    delete tail_;
  }

  List(const List &rhs) {
    init();
    *this = rhs;
  }

  const List &operator=(const List &rhs) {
    if (*this == rhs) {
      return *this;
    }
    clear();
    for (const_iterator iter = rhs.begin(); iter != rhs.end(); iter++) {
      push_back(*iter);
    }
    return *this;
  }

  iterator begin() {
    return iterator(head_->next_);
  }

  const_iterator begin() const {
    return const_iterator(head_->next_);
  }

  iterator end() {
    return iterator(tail_);
  }

  const_iterator end() const {
    return const_iterator(tail_);
  }

  int size() const {
    return size_;
  }

  bool empty() const {
    return size_ == 0;
  }

  void clear() {
    while (!empty()) {
      pop_front();
    }
  }

  T &front() {
    return *begin();
  }

  const T &front() const {
    return *begin();
  }

  T &back() {
    return *--end();
  }

  const T &back() const {
    return *--end();
  }

  void push_front(const T &val) {
    insert(begin(), val);
  }

  void push_back(const T &val) {
    insert(end(), val);
  }

  void pop_front() {
    erase(begin());
  }

  void pop_back() {
    erase(end());
  }

  iterator insert(iterator itr, const T &val) {
    Node *p = itr.current;
    size_++;
    return iterator(p->prev_ = p->prev_->next_ = new Node(val, p->prev_, p));
  }

  iterator erase(iterator itr) {
    Node *   p = itr.current;
    iterator retVal(p->next_);
    p->prev_->next_ = p->next_;
    p->next_->prev_ = p->prev_;
    delete p;
    size_--;

    return retVal;
  }

  iterator erase(iterator start, iterator end) {
    for (iterator itr = start; itr != end;) {
      itr = erase(itr);
    }
    return end;
  }

private:
  size_t size_;
  Node * head_;
  Node * tail_;

  void init() {
    size_        = 0;
    head_        = new Node;
    tail_        = new Node;
    head_->next_ = tail_;
    tail_->prev_ = head_;
  }
};

#endif  //!__LIST__H__
