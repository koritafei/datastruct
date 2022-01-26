/**
 * @file vector.hpp
 * @author koritafei (koritafei@gmail.com)
 * @brief 向量的实现
 * @version 0.1
 * @date 2020-08-27
 *
 * @copyright Copyright (c) 2020
 *
 */
#ifndef __VECTOR__H__
#define __VECTOR__H__

#include <iostream>

template <typename T>
class Vector {
public:
  explicit Vector(size_t size = 0)
      : size_(size), capacity_(size + SPARE_CAPACITY) {
    data_ = new T[size];
  }

  Vector(const Vector& rhs) : data_(nullptr) {
    operator=(rhs);
  }

  ~Vector() {
    delete[] data_;
  }

  const Vector& operator=(const Vector& rhs) {
    if (this != &rhs) {
      delete[] data_;
      size_     = rhs.size();
      capacity_ = rhs.capacity();
      data_     = new T[capacity_];
      for (size_t i = 0; i < size_; i++) {
        data_[i] = rhs.data_[i];
      }
    }

    return *this;
  }

  void resize(size_t newSize) {
    if (newSize > capacity_) {
      reserve(newSize * 2 + 1);
    }
    size_ = newSize;
  }

  void reserve(size_t newCapacity) {
    if (newCapacity < size_) {
      return;
    }
    T* old_data_ = data_;
    data_        = new T[newCapacity];
    for (size_t i = 0; i < size_; i++) {
      data_[i] = old_data_[i];
    }
    capacity_ = newCapacity;
    delete[] old_data_;
  }

  T& operator[](size_t index) {
    return data_[index];
  }

  const T& operator[](size_t index) const {
    return data_[index];
  }

  size_t size() const {
    return size_;
  }

  size_t capacity() const {
    return capacity_;
  }

  bool IsEmpty() const {
    return size_ == 0;
  }

  void push_back(const T& val) {
    if (size_ == capacity_) {
      reserve(size_ * 2 + 1);
    }

    data_[size_++] = val;
  }

  void pop_back() {
    size_--;
  }

  const T& back() const {
    return data_[size_ - 1];
  }

  typedef T*       iterator;
  typedef const T* const_iterator;

  iterator begin() {
    return &data_[0];
  }

  iterator end() {
    return &data_[size()];
  }

  const_iterator begin() const {
    return &data_[0];
  }

  const_iterator end() const {
    return &data_[size()];
  }

  enum { SPARE_CAPACITY = 16 };

private:
  size_t size_;
  size_t capacity_;
  T*     data_;
};

#endif  //!__VECTOR__H__