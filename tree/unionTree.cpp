/**
 * @ Description  :
 * @ Version      : 1.0
 * @ Author       : koritafei(koritafei@gmail.com)
 * @ Date         : 2021-06-02 15:59:46
 * @ LastEditors  : koritafei(koritafei@gmail.com)
 * @ LastEditTime : 2021-06-03 16:29:44
 * @ FilePath     : /datastruct/tree/unionTree.cpp
 * @ Copyright (C) 2021 koritafei(koritafei@gmail.com). All rights reserved.
 * */
#include <iostream>

class Union {
public:
  Union(int n) : count(n) {
    parent = new int[n];
    sz     = new int[n];
    for (int i = 0; i < n; i++) {
      parent[i] = i;
      rank[i]   = 1;
    }
  }

  ~Union() {
    delete[] parent;
    delete[] rank;
    count = 0;
  }

  int find(int p) {
    // while (p != parent[p]) {
    //   parent[p] = parent[parent[p]];  // 简单路径压缩
    //   p         = parent[p];
    // }

    if (p != parent[p]) {
      parent[p] = find(parent[p]);
    }

    return parent[p];
  }

  bool isConnected(int p, int q) {
    return find(p) == find(q);
  }

  void unionElement(int p, int q) {
    int pRoot = find(p);
    int qRoot = find(q);
    if (pRoot == qRoot) {
      return;
    }

    if (rank[pRoot] < rank[qRoot]) {
      parent[pRoot] = qRoot;
    } else if (rank[pRoot] > rank[qRoot]) {
      parent[qRoot] = pRoot;
    } else {
      parent[pRoot] = qRoot;
      rank[qRoot]++;
    }
  }

private:
  int* parent;
  int  count;
  int* rank;  // sz[i]表示以i为根节点的并查集中的元素
};

int main(int argc, char** argv) {
}