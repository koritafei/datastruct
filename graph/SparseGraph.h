/**
 * @ Description  :
 * @ Version      : 1.0
 * @ Author       : koritafei(koritafei@gmail.com)
 * @ Date         : 2021-06-03 17:40:57
 * @ LastEditors  : koritafei(koritafei@gmail.com)
 * @ LastEditTime : 2021-06-05 19:55:22
 * @ FilePath     : /datastruct/graph/SparseGraph.h
 * @ Copyright (C) 2021 koritafei(koritafei@gmail.com). All rights reserved.
 * */

#ifndef __SPARSE_GRAPH_H__
#define __SPARSE_GRAPH_H__

#include <iostream>
#include <vector>

class SparseGraph {
public:
  SparseGraph(int n, bool directed) : n(n), m(0), directed(directed) {
    edge = std::vector<std::vector<int>>(n, std::vector<int>(n, -1));
  }

  ~SparseGraph() {
  }

  int V() const {
    return n;
  }

  int E() const {
    return m;
  }

  void addEdge(int v, int w) {
    if (!hasEdge(v, w)) {
      edge[v].push_back(w);
      if (v != w && !directed) {
        edge[w].push_back(v);
      }
    }
    m++;
  }

  bool hasEdge(int v, int w) const {
    for (int i = 0; i < edge[v].size(); i++) {
      if (edge[v][i] == w) {
        return true;
      }
    }
    return false;
  }

  class adjIterator {
  public:
    adjIterator(SparseGraph &g, int v) : graph(g), v(v), index(0) {
    }

    ~adjIterator() {
    }

    int begin() {
      index = 0;
      if (graph.edge[v].size()) {
        return graph.edge[v][index];
      }

      return -1;
    }

    int next() {
      index++;
      if (index < graph.edge[v].size()) {
        return index;
      }
      return -1;
    }

    bool end() const {
      return index >= graph.edge[v].size();
    }

  private:
    SparseGraph &graph;
    int          index;
    int          v;
  };

private:
  int n,
      m;                                   // 顶点数和边数
  bool                          directed;  // 是否为有向图
  std::vector<std::vector<int>> edge;      // 边
};

#endif /* __SPARSE_GRAPH_H__ */