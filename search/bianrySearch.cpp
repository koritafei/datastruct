/**
 * @file: bianrySearch.cpp
 * @description: 
 * @author: koritafei
 * @create: 2021-05-31 13:49
 * @version v0.1
 * */

#include <iostream>
#include <vector>

template<class T>
int bianrySearch(std::vector<T> &nums, int key) {
  int left = 0, right = nums.size() - 1;
  while (left <= right) {
    int middle = left + (right - left) / 2;
    if (nums[middle] == key) {
      return middle;
    } else if (nums[middle] < key) {
      left = middle + 1;
    } else if (nums[middle] > key) {
      right = middle - 1;
    }
  }

  return -1;
}

template<class T>
int floor(std::vector<T> &nums, int key) {
  // 最大比key小的值
  int left = 0, right = nums.size() - 1;
  while (left <= right) {
    int middle = left + (right - left) / 2;
    if (nums[middle] == key) {
      return middle;
    } else if (nums[middle] > key) {
      right = middle - 1;
    } else if (nums[middle] < key) {
      left = middle + 1;
    }
  }

  return right;
}

template<class T>
int ceil(std::vector<T> &nums, int key) {
  // 最小的比key大的值
  int left = 0, right = nums.size() - 1;
  while (left <= right) {
    int middle = left + (right - left) / 2;
    if (nums[middle] == key) {
      return middle;
    } else if (nums[middle] > key) {
      right = middle -1;
    } else if (nums[middle] < key) {
      left = middle + 1;
    }
  }

  return left;
}


int main(int argc, char **argv) {
  std::vector<int> nums = {1, 4, 6, 7, 9, 10, 15, 1100};
  int key = 1100;
  std::cout << bianrySearch(nums, key) << std::endl;
  key = 8;
  std::cout << bianrySearch(nums, key) << std::endl;
  std::cout << floor(nums, key) << std::endl;
  std::cout << ceil(nums, key) << std::endl;
}
