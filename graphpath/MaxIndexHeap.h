/**
 * @ Description  : Max Index Heap
 * @ Version      : 1.0
 * @ Author       : koritafei(koritafei@gmail.com)
 * @ Date         : 2021-05-30 17:41:57
 * @ LastEditors  : koritafei(koritafei@gmail.com)
 * @ LastEditTime : 2021-06-08 14:44:45
 * @ FilePath     : /datastruct/graphpath/MaxIndexHeaap.h
 * @ Copyright (C) 2021 koritafei(koritafei@gmail.com). All rights reserved.
 * */

#ifndef __MAX_INDEX_HEAP_H__
#define __MAX_INDEX_HEAP_H__

#include <iostream>
#include <vector>

template <class T>
class MaxIndexHeap {
public:
  MaxIndexHeap(int capacity) : count_(0), capacity_(capacity) {
    data_    = new T[capacity + 1];
    indexs_  = new int[capacity + 1];
    reverse_ = new int[capacity + 1];
    for (int i = 0; i < capacity; i++) {
      reverse_[i] = 0;
    }
  }

  ~MaxIndexHeap() {
    delete[] data_;
    delete[] indexs_;
    count_    = 0;
    capacity_ = 0;
  }

  bool empty() const {
    return count_ == 0;
  }

  int size() const {
    return count_;
  }

  int getIndex() {
    int ret                       = indexs_[0];
    reverse_[indexs_[0]]          = 0;
    reverse_[indexs_[count_ - 1]] = 0;
    std::swap(indexs_[0], indexs_[count_ - 1]);
    shiftDown(0);

    return ret;
  }

  void changeItem(int index, T item) {
    data_[index] = item;
    // for (int i = 0; i < count_; i++) {
    //   if (indexs_[i] == index) {
    //     shiftDown(i);
    //     shiftUp(i);
    //     return;
    //   }
    // }
    int j = index;
    shiftUp(j);
    shiftDown(j);
  }

  T getItem() {
    T item = data_[indexs_[0]];
    std::swap(indexs_[0], indexs_[count_ - 1]);
    reverse_[indexs_[0]]          = 0;
    reverse_[indexs_[count_ - 1]] = 0;
    shiftDown(0);
    return item;
  }

  void insertItem(int index, T item) {
    data_[count_]   = item;
    indexs_[count_] = index;
    reverse_[index] = count_;
    count_++;
    shiftUp(count_ - 1);
  }

private:
  void shiftDown(int index) {
    while ((2 * index + 1) < count_) {
      int k = 2 * index + 1;
      if (k + 1 < count_ && data_[indexs_[k + 1] > data_[indexs_[k]]]) {
        k++;
      }

      if (data_[indexs_[k]] < data_[indexs_[index]]) {
        break;
      }

      std::swap(indexs_[k], indexs_[index]);
      reverse_[indexs_[index]] = index;
      reverse_[indexs_[k]]     = k;
      index                    = k;
    }
  }

  void shiftUp(int index) {
    assert(count_ <= capacity_);
    while (index >= 0 &&
           data_[indexs_[(index - 1) / 2]] > data_[indexs_[index]]) {
      std::swap(indexs_[(index - 1) / 2], indexs_[index]);
      reverse_[(index - 1) / 2] = (index - 1) / 2;
      reverse_[index]           = index;
    }
  }

  T*   data_;
  int* indexs_;
  int* reverse_;
  int  count_;
  int  capacity_;
};

#endif /* __MAX_INDEX_HEAP_H__ */