/**
 * @Copyright (c) 2021  koritafei
 * @file SelectSort.cpp
 * @brief
 * @author koritafei (koritafei@gmail.com)
 * @version 0.1
 * @date 2021-05-21 14:05:36
 *
 * */

#include <iostream>
#include <vector>

template <class T>
void SelectSort(std::vector<T> &nums) {
  unsigned long len      = nums.size();
  unsigned long minIndex = 0;
  for (unsigned long i = 0; i < len - 1; i++) {
    minIndex = i;
    for (unsigned long j = i + 1; j < len; j++) {
      if (nums[j] < nums[minIndex]) {
        minIndex = j;
      }
    }
    std::swap(nums[i], nums[minIndex]);
  }
}

int main(int argc, char **argv) {
  std::vector<int> nums = {1, 10, 9, 2, 8, 3, 7, 5};
  for (auto item : nums) {
    std::cout << item << " ";
  }
  std::cout << "\n";
  SelectSort(nums);
  for (auto item : nums) {
    std::cout << item << " ";
  }
  std::cout << "\n";
}
