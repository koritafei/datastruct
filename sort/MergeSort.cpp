/**
 * @ Description  :
 * @ Version      : 1.0
 * @ Author       : koritafei(koritafei@gmail.com)
 * @ Date         : 2021-05-21 17:18:38
 * @ LastEditors  : koritafei(koritafei@gmail.com)
 * @ LastEditTime : 2021-05-23 10:21:45
 * @ FilePath     : /datastruct/sort/MergeSort.cpp
 * @ Copyright (C) 2021 koritafei(koritafei@gmail.com). All rights reserved.
 * */

#include <iostream>
#include <vector>

template <class T>
void print(const std::vector<T> &nums) {
  for (auto item : nums) {
    std::cout << item << " ";
  }
  std::cout << "\n";
}

template <class T>
void merge(std::vector<T> &nums,
           unsigned long   start,
           unsigned long   mid,
           unsigned long   end) {
  unsigned long  len1 = mid - start + 1;
  unsigned long  len2 = end - mid;
  std::vector<T> n1;
  std::vector<T> n2;
  for (unsigned long i = start; i <= mid; i++) {
    n1.push_back(nums[i]);
  }
  for (unsigned long i = mid + 1; i <= end; i++) {
    n2.push_back(nums[i]);
  }

  unsigned long i = 0, j = 0;
  unsigned long k = start;
  while (i < len1 && j < len2) {
    if (n1[i] < n2[j]) {
      nums[k++] = n1[i++];
    } else {
      nums[k++] = n2[j++];
    }
  }

  while (i < len1) {
    nums[k++] = n1[i++];
  }

  while (j < len2) {
    nums[k++] = n2[j++];
  }
}

template <class T>
void mergeSortBU(std::vector<T> &nums, unsigned long len) {
  for (unsigned long sz = 1; sz <= len; sz += sz) {
    for (unsigned long i = 0; i + sz <= len; i += sz + sz) {
      merge(nums, i, i + sz - 1, std::min(i + sz + sz - 1, len - 1));
    }
  }
}

template <class T>
void mergeSort(std::vector<T> &nums, unsigned long l, unsigned long r) {
  if (l >= r) {
    return;
  }

  unsigned long mid = l + (r - l) / 2;
  mergeSort(nums, l, mid);
  mergeSort(nums, mid + 1, r);
  merge<T>(nums, l, mid, r);
}

int main(int argc, char **argv) {
  std::vector<int> nums = {1, 10, 9, 2, 8, 3, 7, 5};
  print(nums);
  mergeSort(nums, 0, nums.size() - 1);
  print(nums);
  nums = {1, 10, 9, 2, 8, 3, 7, 5};
  print(nums);
  mergeSortBU(nums, nums.size());
  print(nums);
}