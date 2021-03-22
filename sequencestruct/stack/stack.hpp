/**
 * @file stack.hpp
 * @author koritafei (koritafei@gmail.com)
 * @brief 链表实现栈
 * @version 0.1
 * @date 2020-08-30
 *
 * @copyright Copyright (c) 2020
 *
 */

#ifndef __STACK__H__
#define __STACK__H__

#include <iostream>

#include "list/list.hpp"

template <typename T>
class Stack {
public:
  Stack() {
  }

  bool IsEmpty() const {
    return data_.empty();
  }

  size_t size() const {
    return data_.size();
  }

  void push(const T &val) {
    data_.push_back(val);
  }

  T pop() {
    T front = data_.front();
    data_.pop_front();
    return front;
  }

  void clear() {
    data_.clear();
  }

  T top() {
    return data_.front();
  }

private:
  List<T> data_;
};

#endif  //!__STACK__H__
