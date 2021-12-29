/**
 * @ Description  : 并查集
 * @ Version      : 1.0
 * @ Author       : koritafei(koritafei@gmail.com)
 * @ Date         : 2021-06-02 15:22:22
 * @ LastEditors  : koritafei(koritafei@gmail.com)
 * @ LastEditTime : 2021-06-02 15:58:48
 * @ FilePath     : /datastruct/tree/union.cpp
 * @ Copyright (C) 2021 koritafei(koritafei@gmail.com). All rights reserved.
 * */

#include <iostream>

class Union {
public:
  Union(int n) : count(n) {
    id    = new int[n];
    count = n;
    for (int i = 0; i < n; i++) {
      id[i] = i;
    }
  }

  ~Union() {
    delete[] id;
  }

  int find(int p) const {
    return id[p];
  }

  bool isConnected(int p, int q) const {
    return find(p) == find(q);
  }

  void unionElements(int p, int q) {
    int qId = find(q);
    int pId = find(p);
    if (qId == pId) {
      return;
    }

    for (int i = 0; i < count; i++) {
      if (id[i] == pId) {
        id[i] = qId;
      }
    }
  }

private:
  int *id;
  int  count;
};

int main(int argc, char **argv) {
  Union *un = new Union(10);
  un->unionElements(0, 9);
  un->unionElements(3, 9);

  std::cout << un->isConnected(0, 3) << std::endl;

  delete un;
  un = nullptr;
}
