/**
 * @Copyright (c) 2021  koritafei
 * @file InsertSort.cpp
 * @brief
 * @author koritafei (koritafei@gmail.com)
 * @version 0.1
 * @date 2021-05-21 14:05:23
 *
 * */

#include <iostream>
#include <vector>

template <class T>
void InsertSort(std::vector<T> &nums) {
  int len = nums.size();
}

int main(int argc, char **argv) {
  std::vector<int> nums = {1, 10, 9, 2, 8, 3, 7, 5};
  for (auto item : nums) {
    std::cout << item << " ";
  }
  std::cout << "\n";
  InsertSort(nums);
  for (auto item : nums) {
    std::cout << item << " ";
  }
  std::cout << "\n";
}