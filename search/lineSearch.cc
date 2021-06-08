/**
 * @ Description  :
 * @ Version      : 1.0
 * @ Author       : koritafei(koritafei@gmail.com)
 * @ Date         : 2021-06-08 17:24:40
 * @ LastEditors  : koritafei(koritafei@gmail.com)
 * @ LastEditTime : 2021-06-08 17:28:25
 * @ FilePath     : /datastruct/search/lineSearch.cc
 * @ Copyright (C) 2021 koritafei(koritafei@gmail.com). All rights reserved.
 * */

#include <iostream>
#include <vector>

template <typename T>
int lineSearch(std::vector<T> &vec, T target) {
  int len = vec.size();
  for (int i = 0; i < len; i++) {
    if (vec[i] == target) {
      return i;
    }
  }

  return -1;
}

int main(int argc, char **argv) {
  std::vector<int> vec    = {1, 8, 3, 0, 2, 8, 2, 1, 6};
  int              target = 0;
  std::cout << lineSearch(vec, target) << std::endl;
}
