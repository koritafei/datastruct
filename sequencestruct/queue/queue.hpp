/**
 * @file queue.hpp
 * @author koritafei (koritafei@gmail.com)
 * @brief 双端队列实现
 * @version 0.1
 * @date 2020-09-07
 *
 * @copyright Copyright (c) 2020
 *
 */

#ifndef __QUEUE__H__
#define __QUEUE__H__

#include <cstring>
#include <iostream>

template <typename T>
class Queue {
public:
  Queue() : cap_(capacity), front_(0), back_(capacity - 1) {
    data_ = new T[capacity];
  }

  ~Queue() {
    if (data_) {
      delete[] data_;
    }
    cap_ = 0;
  }

  Queue(Queue &rhs) {
    data_ = rhs.data_;
    cap_  = rhs.cap_;
    delete[] rhs.data_;
    rhs.data_ = nullptr;
    rhs.size_ = 0;
    rhs.cap_  = 0;
  }
  Queue &operator=(Queue &rhs) {
    data_ = rhs.data_;
    cap_  = rhs.cap_;
    delete[] rhs.data_;
    rhs.data_ = nullptr;
    rhs.size_ = 0;
    rhs.cap_  = 0;
  }

  void push_front(T data) {
    if (full()) {
      resize();
    }
    data_[(front_ + cap_ - 1) % cap_] = data;
    front_                            = (front_ + cap_ - 1) % cap_;
  }

  void push_back(T data) {
    if (full()) {
      resize();
    }
    data_[(back_ + cap_ + 1) % cap_] = data;
    back_                            = (back_ + cap_ + 1) % cap_;
  }

  void pop_front() {
    if (!empty()) {
      front_ = (front_ + 1) % cap_;
    }
  }

  void pop_back() {
    if (!empty()) {
      back_ = (back_ + cap_ - 1) % cap_;
    }
  }

  T front() {
    return data_[front_];
  }

  T back() {
    return data_[back_];
  }

  size_t size() {
    return (front_ + cap_ - back_) % cap_;
  }

  bool empty() {
    return front_ == back_;
  }

private:
  /**
   * @brief 扩充队列，每次扩充为原来大小的2倍
   *
   */
  void resize() {
    T *    old     = data_;
    size_t old_cap = cap_;
    cap_ <<= 1;
    data_ = new T[cap_];
    for (size_t i = 0; i < old_cap; i++) {
      data_[i] = old[i];
    }

    delete[] old;
    old = nullptr;
  }

  bool full() {
    return size() == cap_;
  }

  const size_t capacity = 20;
  T *          data_;
  size_t       cap_;
  size_t       front_;
  size_t       back_;
};

#endif  //!__QUEUE__H__
