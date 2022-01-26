/**
 * @ Description  :
 * @ Version      : 1.0
 * @ Author       : koritafei(koritafei@gmail.com)
 * @ Date         : 2021-05-23 10:25:39
 * @ LastEditors  : koritafei(koritafei@gmail.com)
 * @ LastEditTime : 2021-05-23 17:10:02
 * @ FilePath     : /datastruct/sort/QiuckSort.cpp
 * @ Copyright (C) 2021 koritafei(koritafei@gmail.com). All rights reserved.
 * */

#include <iostream>
#include <vector>

template <class T>
unsigned long __paration(std::vector<T> &nums,
                         unsigned long   start,
                         unsigned long   end) {
  T             v = nums[start];
  unsigned long j = start;
  for (unsigned long i = start + 1; i <= end; i++) {
    if (nums[i] < v) {
      std::swap(nums[j++], nums[i]);
    }
  }

  std::swap(nums[j], v);
  return j;
}

template <class T>
void __quicksort(std::vector<T> &nums, unsigned long start, unsigned long end) {
  if (start >= end) {
    return;
  }

  unsigned long p = __paration(nums, start, end);
  __quicksort(nums, start, p - 1);
  __quicksort(nums, p + 1, end);
}

template <class T>
void quicksort(std::vector<T> &nums) {
  __quicksort(nums, 0, nums.size() - 1);
}

// 改进快排，针对含有大量的重复元素
template <class T>
unsigned long __paration2(std::vector<T> &nums,
                          unsigned long   start,
                          unsigned long   end) {
  T             key = nums[start];
  unsigned long i = start + 1, j = end;
  while (true) {
    while (i <= end && nums[i] < key) {
      i++;
    }
    while (j >= start + 1 && nums[j] > key) {
      j--;
    }

    if (i > j) {
      break;
    }

    std::swap(nums[i++], nums[j--]);
  }

  std::swap(nums[start], nums[j]);

  return j;
}

template <class T>
void __quicksort2(std::vector<T> &nums,
                  unsigned long   start,
                  unsigned long   end) {
  if (start >= end) {
    return;
  }

  unsigned long p = __paration2(nums, start, end);
  __quicksort2(nums, start, p - 1);
  __quicksort2(nums, p + 1, end);
}

template <class T>
void quicksort2(std::vector<T> &nums) {
  __quicksort2(nums, 0, nums.size() - 1);
}

// 三路归并

template <class T>
void __quicksort3Ways(std::vector<T> &nums, unsigned long l, unsigned long r) {
  if (l >= r) {
    return;
  }

  unsigned long lt  = l;
  unsigned long gt  = r;
  unsigned long i   = l + 1;
  T             key = nums[l];

  while (i < gt) {
    if (nums[i] < key) {  // nums[l...lt] < key
      std::swap(nums[i++], nums[lt + 1]);
      lt++;
    } else if (nums[i] > key) {  // nums[gt...r] > key
      std::swap(nums[i], nums[gt--]);
      // gt--;
    } else {  // nums[lt...i] == key
      i++;
    }
  }
  std::swap(nums[l], nums[lt]);
  __quicksort3Ways(nums, l, lt - 1);
  __quicksort3Ways(nums, gt, r);
}

template <class T>
void quicksort3Ways(std::vector<T> &nums) {
  unsigned long len = nums.size();
  __quicksort3Ways(nums, 0, len - 1);
}

int main(int argc, char **argv) {
  std::vector<int> nums = {1, 10, 9, 2, 8, 3, 7, 5};
  for (auto item : nums) {
    std::cout << item << " ";
  }
  std::cout << "\n";
  quicksort(nums);
  for (auto item : nums) {
    std::cout << item << " ";
  }
  std::cout << "\n";

  nums = {1, 10, 9, 2, 8, 3, 7, 5};
  for (auto item : nums) {
    std::cout << item << " ";
  }
  std::cout << "\n";
  quicksort2(nums);
  for (auto item : nums) {
    std::cout << item << " ";
  }
  std::cout << "\n";

  nums = {1, 1, 9, 2, 44, 3, 7, 5, 7, 7, 7, 7};
  for (auto item : nums) {
    std::cout << item << " ";
  }
  std::cout << "\n";
  quicksort3Ways(nums);
  for (auto item : nums) {
    std::cout << item << " ";
  }
  std::cout << "\n";
}
