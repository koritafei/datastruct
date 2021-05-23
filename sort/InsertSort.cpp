/**
 * @ Description  :
 * @ Version      : 1.0
 * @ Author       : koritafei(koritafei@gmail.com)
 * @ Date         : 2021-05-21 14:42:36
 * @ LastEditors  : koritafei(koritafei@gmail.com)
 * @ LastEditTime : 2021-05-21 17:15:26
 * @ FilePath     : /datastruct/sort/InsertSort.cpp
 * @ Copyright (C) 2021 koritafei(koritafei@gmail.com). All rights reserved.
 * */
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
  for (int i = 1; i < len; i++) {
    int e = nums[i];
    int j;
    for (j = i; j > 0 && nums[j - 1] > e; j--) {
      nums[j] = nums[j - 1];
    }
    nums[j] = e;
  }
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