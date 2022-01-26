/**
 * @ Description  : 逆序对数
 * @ Version      : 1.0
 * @ Author       : koritafei(koritafei@gmail.com)
 * @ Date         : 2021-05-23 17:23:31
 * @ LastEditors  : koritafei(koritafei@gmail.com)
 * @ LastEditTime : 2021-05-24 16:57:36
 * @ FilePath     : /datastruct/sort/pairsNum.cpp
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
unsigned long mergeSort(std::vector<T> &nums,
                        unsigned long   start,
                        unsigned long   end) {
  if (start >= end) {
    return 0;
  }

  unsigned long mid   = start + (end - start) / 2;
  unsigned long left  = mergeSort(nums, start, mid);
  unsigned long right = mergeSort(nums, mid + 1, end);

  std::vector<T> copy(nums.size());

  unsigned long count = 0;
  unsigned long i     = mid;
  unsigned long j     = end;
  unsigned long k     = end;
  while (i >= start && j >= mid + 1) {
    if (nums[i] > nums[j]) {
      copy[k--] = nums[i--];
      count += j - mid;
    } else {
      copy[k--] = nums[j--];
    }
  }

  while (i >= start) {
    copy[k--] = nums[i--];
  }
  while (j >= mid + 1) {
    copy[k--] = nums[j--];
  }

  for (unsigned long t = start; t <= end; t++) {
    nums[t] = copy[t];
  }

  return left + right + count;
}

int main(int argc, char **argv) {
  std::vector<int> nums = {6, 1, 3, 5, 2, 10};
  printVector(nums);
  std::cout << mergeSort(nums, 0, nums.size() - 1) << std::endl;
  printVector(nums);
}
