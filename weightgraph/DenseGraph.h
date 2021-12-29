/**
 * @ Description  :
 * @ Version      : 1.0
 * @ Author       : koritafei(koritafei@gmail.com)
 * @ Date         : 2021-06-07 15:37:11
 * @ LastEditors  : koritafei(koritafei@gmail.com)
 * @ LastEditTime : 2021-06-07 15:49:36
 * @ FilePath     : /datastruct/weightgraph/DenseGraph.h
 * @ Copyright (C) 2021 koritafei(koritafei@gmail.com). All rights reserved.
 * */

#ifndef __DENSE_GRAPH_H__
#define __DENSE_GRAPH_H__

#include <vector>

#include "edge.h"

template <typename Weight>
class DenseGraph {
public:
  DenseGraph(int n, bool directed) : n(n), m(0), directed(directed) {
    g = std::vector<std::vector<Edge<Weight> *>>(
        n,
        std::vector<Edge<Weight> *>(n, nullptr));
  }

  ~DenseGraph() {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (g[i][j]) {
          delete g[i][j];
        }
      }
    }
  }

  int V() const {
    return n;
  }

  int E() const {
    return m;
  }

  void addEdge(int v, int w, Weight weight) {
    if (hasEdge(v, w)) {
      return;
    }

    g[v][w] = new Edge<Weight>(v, w, weight);
    if (!directed) {
      g[w][v] = new Edge<Weight>(w, v, weight);
    }
    m++;
  }

  bool hasEdge(int v, int w) {
    return g[v][w] != nullptr;
  }

  class adjIterator {
  public:
    adjIterator(DenseGraph &g, int v) : graph(g), v(v), index(-1) {
    }

    Edge<Weight> *begin() {
      index = -1;
      return next();
    }

    Edge<Weight> *next() {
      for (index += 1; index < graph.V(); index++) {
        if (graph[v][index]) {
          return graph[v][index];
        }
      }
      return nullptr;
    }

    bool end() {
    }

  private:
    DenseGraph &graph;
    int         v;
    int         index;
  };

private:
  int                                      n, m;
  bool                                     directed;
  std::vector<std::vector<Edge<Weight> *>> g;
};

#endif /* __DENSE_GRAPH_H__ */
