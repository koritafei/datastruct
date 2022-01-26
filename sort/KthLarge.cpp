/**
 * @ Description  : kth large number
 * @ Version      : 1.0
 * @ Author       : koritafei(koritafei@gmail.com)
 * @ Date         : 2021-05-23 17:23:49
 * @ LastEditors  : koritafei(koritafei@gmail.com)
 * @ LastEditTime : 2021-05-24 18:37:22
 * @ FilePath     : /datastruct/sort/KthLarge.cpp
 * @ Copyright (C) 2021 koritafei(koritafei@gmail.com). All rights reserved.
 * */

#include <iostream>
#include <vector>

using namespace std;

template <class T>
void printVector(std::vector<T> &nums) {
  for (auto item : nums) {
    std::cout << item << " ";
  }
  std::cout << std::endl;
}

template <class T>
int partition(std::vector<T> &nums, int start, int end) {
  T   key = nums[start];
  int i = start + 1, j = end;
  while (i <= j) {
    while (i <= end && nums[i] <= key) {
      i++;
    }
    while (j >= start && nums[j] > key) {
      j--;
    }
    std::swap(nums[i++], nums[j--]);
  }

  std::swap(nums[start], nums[j]);
  return j;
}

template <class T>
T findKthLarge(std::vector<T> &nums, int start, int end, int kth) {
  if (start >= end || kth < 0) {
    return 0;
  }

  int p = partition(nums, start, end);
  if (p == kth - 1) {
    return nums[p];
  } else if (p < kth - 1) {
    return findKthLarge(nums, p + 1, end, kth);
  } else if (p > kth - 1) {
    return findKthLarge(nums, start, p - 1, kth);
  }

  return 0;
}

int main(int argc, char **argv) {
  std::vector<int> nums = {1, 10, 8, 2, 6, 1};
  int              k    = 4;
  printVector(nums);
  int num = findKthLarge(nums, 0, static_cast<int>(nums.size() - 1), k);
  std::cout << k << '\t' << num << std::endl;
}
