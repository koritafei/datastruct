/**
 * @ Description  :
 * @ Version      : 1.0
 * @ Author       : koritafei(koritafei@gmail.com)
 * @ Date         : 2021-05-30 15:41:36
 * @ LastEditors  : koritafei(koritafei@gmail.com)
 * @ LastEditTime : 2021-05-30 17:24:28
 * @ FilePath     : /datastruct/sort/heapsort.cpp
 * @ Copyright (C) 2021 koritafei(koritafei@gmail.com). All rights reserved.
 * */

#include <iostream>
#include <vector>

template <class Item>
class MaxHeap {
public:
  MaxHeap(int capacity) : count_(0), capacity_(capacity) {
    data_ = new Item[capacity + 1];
  }

  ~MaxHeap() {
    delete[] data_;
    count_    = 0;
    capacity_ = 0;
  }

  int size() const {
    return count_;
  }

  bool empty() const {
    return count_ == 0;
  }

  void insertItem(Item item) {
    assert(count_ + 1 < capacity_);
    data_[count_] = item;
    shiftUp(count_);
    count_++;
  }

  void print() const {
    for (int i = 0; i < count_; i++) {
      std::cout << data_[i] << " ";
    }
    std::cout << std::endl;
  }

  // get heap item
  // only get root val
  Item getItem() {
    assert(count_ > 0);
    std::swap(data_[0], data_[count_ - 1]);
    Item item = data_[count_ - 1];
    count_--;
    shiftDown(0);
    return item;
  }

private:
  void shiftUp(int index) {
    while (index >= 0 && data_[(index - 1) / 2] < data_[index]) {
      std::swap(data_[index], data_[(index - 1) / 2]);
      index = (index - 1) / 2;
    }
  }

  void shiftDown(int index) {
    while (index * 2 + 1 < count_) {
      int k = index * 2 + 1;
      if (k + 1 < count_ && data_[k] < data_[k + 1]) {
        k++;
      }
      if (data_[k] <= data_[index]) {
        break;
      }

      std::swap(data_[k], data_[index]);
      index = k;
    }
  }

  Item *data_;
  int   count_;
  int   capacity_;
};

// 最小堆
template <class Item>
class MinHeap {
public:
  MinHeap(int capacity) : count_(0), capacity_(capacity) {
    data_ = new Item[capacity + 1];
  }

  ~MinHeap() {
    delete[] data_;
    count_    = 0;
    capacity_ = 0;
  }

  Item getItem() {
    assert(count_ > 0);
    std::swap(data_[0], data_[count_ - 1]);
    Item item = data_[count_ - 1];
    count_--;
    shiftDown(0);
    return item;
  }

  void insertItem(Item item) {
    assert(count_ < capacity_);
    data_[count_] = item;
    shiftUp(count_);
    count_++;
  }

  void print() const {
    for (int i = 0; i < count_; i++) {
      std::cout << data_[i] << " ";
    }
    std::cout << std::endl;
  }

  int size() const {
    return count_;
  }

  bool empty() const {
    return count_ == 0;
  }

private:
  void shiftUp(int index) {
    while (index >= 0 && data_[(index - 1) / 2] > data_[index]) {
      std::swap(data_[index], data_[(index - 1) / 2]);
      index = (index - 1) / 2;
    }
  }

  void shiftDown(int index) {
    while (index * 2 + 1 < count_) {
      int k = index * 2 + 1;
      if (k + 1 < count_ && data_[k] > data_[k + 1]) {
        k++;
      }
      if (data_[index] <= data_[k]) {
        break;
      }
      std::swap(data_[index], data_[k]);
      index = k;
    }
  }

  Item *data_;
  int   count_;
  int   capacity_;
};

template <class T>
void __shiftDown(std::vector<T> &arr, int n, int k) {
  while (2 * k + 1 < n) {
    int j = 2 * k + 1;
    if (j + 1 < n && arr[j] < arr[j + 1]) {
      j++;
    }
    if (arr[j] <= arr[k]) {
      break;
    }
    std::swap(arr[j], arr[k]);
    k = j;
  }
}

template <class T>
void heapSort(std::vector<T> &arr, int n) {
  for (int i = (n - 1) / 2; i >= 0; i--) {
    __shiftDown(arr, n, i);
  }
  for (auto item : arr) {
    std::cout << item << " ";
  }
  std::cout << std::endl;

  for (int i = n - 1; i >= 0; i--) {
    std::swap(arr[0], arr[i]);
    for (auto item : arr) {
      std::cout << item << " ";
    }
    std::cout << std::endl;
    __shiftDown(arr, i, 0);
  }
}

int main(int argc, char **argv) {
  MaxHeap<int> h(20);
  h.insertItem(12);
  h.insertItem(13);
  h.insertItem(14);
  h.insertItem(1);
  h.insertItem(2);

  h.print();
  std::cout << h.getItem() << std::endl;
  h.print();

  MinHeap<int> m(20);
  m.insertItem(12);
  m.insertItem(13);
  m.insertItem(14);
  m.insertItem(1);
  m.insertItem(2);

  m.print();
  std::cout << m.getItem() << std::endl;
  m.print();

  std::vector<int> nums = {1, 4, 6, 2, 0};
  for (auto item : nums) {
    std::cout << item << " ";
  }
  std::cout << std::endl;
  heapSort(nums, nums.size());
  for (auto item : nums) {
    std::cout << item << " ";
  }
  std::cout << std::endl;
}