/**
 * @ Description  :
 * @ Version      : 1.0
 * @ Author       : koritafei(koritafei@gmail.com)
 * @ Date         : 2021-06-07 15:37:23
 * @ LastEditors  : koritafei(koritafei@gmail.com)
 * @ LastEditTime : 2021-06-07 16:06:28
 * @ FilePath     : /datastruct/weightgraph/SparseGraph.h
 * @ Copyright (C) 2021 koritafei(koritafei@gmail.com). All rights reserved.
 * */

#ifndef __SPARSE_GRAPH_H__
#define __SPARSE_GRAPH_H__

#include <iostream>
#include <vector>

#include "edge.h"

template <typename Weight>
class SparseGraph {
public:
  SparseGraph(int n, bool directed) : n(n), m(0), directed(directed) {
    edges = std::vector<std::vector<Edge<Weight> *>>(
        n,
        std::vector<Edge<Weight> *>(n, nullptr));
  }

  ~SparseGraph() {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < edges[i].size(); j++) {
        delete edges[i][j];
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
    edges[v].push_back(new Edge<Weight>(v, w, weight));
    if (!directed) {
      edges[w].push_back(new Edge<Weight>(w, v, weight));
    }
    m++;
  }

  bool hasEdge(int v, int w) {
    for (int i = 0; i < edges[v].size(); i++) {
      if (edges[v][i]->other(v) == w) {
        return true;
      }
    }

    return false;
  }

  class adjIterator {
  public:
    adjIterator(SparseGraph &g, int v) : graph(g), v(v), index(-1) {
    }

    ~adjIterator() {
    }

    Edge<Weight> *begin() {
      index = 0;
      if (graph[v].size()) {
        return graph[v][index];
      }
      return nullptr;
    }

    Edge<Weight> *next() {
      index += 1;
      if (graph[v].size()) {
        return graph[v][index];
      }

      return nullptr;
    }

    bool end() {
      return index >= graph[v].size();
    }

  private:
    SparseGraph &graph;
    int          v;
    int          index;
  };

private:
  int                                      n, m;
  bool                                     directed;
  std::vector<std::vector<Edge<Weight> *>> edges;
};

#endif /* __SPARSE_GRAPH_H__ */
