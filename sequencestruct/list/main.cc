/**
 * @file main.cc
 * @author koritafei (koritafei@gmail.com)
 * @brief 链表测试程序
 * @version 0.1
 * @date 2020-08-25
 *
 * @copyright Copyright (c) 2020
 *
 */

#include "list/list.hpp"

int main(int argc, char **argv) {
  std::cout << "Hello, linklist" << std::endl;

  List<int> l;
  l.push_back(1);
  std::cout << l.front() << std::endl;
}