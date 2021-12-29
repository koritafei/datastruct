/**
 * @ Description  : 邻接矩阵表示图
 * @ Version      : 1.0
 * @ Author       : koritafei(koritafei@gmail.com)
 * @ Date         : 2021-06-03 17:08:25
 * @ LastEditors  : koritafei(koritafei@gmail.com)
 * @ LastEditTime : 2021-06-05 20:12:04
 * @ FilePath     : /datastruct/graph/DenseGraph.h
 * @ Copyright (C) 2021 koritafei(koritafei@gmail.com). All rights reserved.
 * */

#ifndef __DENSE_GRAPH__
#define __DENSE_GRAPH__

#include <iostream>
#include <vector>

class DenseGraph {
public:
  DenseGraph(int n, bool directed) : n(n), directed(directed) {
    edge = std::vector<std::vector<bool>>(n, std::vector<bool>(n, false));
  }

  ~DenseGraph() {
  }

  int V() {
    return n;
  }

  int E() {
    return m;
  }

  void addEdge(int v, int w) {
    if (hasEdge(v, w)) {
      return;
    }

    edge[v][w] = true;
    if (!directed) {
      edge[w][v] = true;
    }

    m++;
  }

  bool hasEdge(int v, int w) {
    return edge[v][w];
  }

  class adjIterator {
  public:
    adjIterator(DenseGraph &g, int v) : graph(g), v(v), index(-1) {
    }

    ~adjIterator() {
    }

    int begin() {
      index = -1;
      return next();
    }

    int next() {
      for (index += 1; index < graph.V(); index++) {
        if (graph.edge[v][index]) {
          return index;
        }
      }

      return -1;
    }

    bool end() {
      return index >= graph.V();
    }

  private:
    DenseGraph &graph;
    int         index;
    int         v;
  };

private:
  int  n, m;                            // 顶点与边数
  bool directed;                        // 有向图(true),否则为无向图
  std::vector<std::vector<bool>> edge;  // 边的矩阵
};

#endif /* __DENSE_GRAPH__ */
