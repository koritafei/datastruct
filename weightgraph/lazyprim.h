/**
 * @ Description  : 最小生成树算法
 * @ Version      : 1.0
 * @ Author       : koritafei(koritafei@gmail.com)
 * @ Date         : 2021-06-07 16:11:31
 * @ LastEditors  : koritafei(koritafei@gmail.com)
 * @ LastEditTime : 2021-06-07 17:06:54
 * @ FilePath     : /datastruct/weightgraph/lazyprim.h
 * @ Copyright (C) 2021 koritafei(koritafei@gmail.com). All rights reserved.
 * */

#ifndef __LAZY_PRIM_H__
#define __LAZY_PRIM_H__

#include <queue>
#include <vector>

#include "edge.h"

template <typename Graph, typename Weight>
class LazyPrim {
public:
  LazyPrim(Graph &g) : g(g) {
    minHeap = std::priority_queue<Edge<Weight>,
                                  std::vector<Edge<Weight>>,
                                  std::greater<Edge<Weight>>>(g.E());
    visited = std::vector<bool>(g.V(), false);
    // 最小树生成算法
    mstTree(0);
    while (minHeap.size()) {
      Edge<Weight> e = minHeap.front();
      minHeap.pop_front();
      if (visited[e.v()] == visited[e.w()]) {
        continue;
      }
      mst.push_back(e);
      if (!visited[e.v()]) {
        visited(e.v());
      } else {
        visited(e.w());
      }
    }

    mstWeight = mst[0].wt();
    for (int i = 1; i < mst.size(); i++) {
      mstWeight += mst[i].wt();
    }
  }

  ~LazyPrim() {
  }

  std::vector<Edge<Weight>> mstEdges() const {
    return mst;
  }

  Weight result() const {
    return mstWeight;
  }

private:
  void mstTree(int v) {
    visited[v] = true;
    typename Graph::adjIterator adj(g, v);
    for (Edge<Weight> *i = adj.begin(); !adj.end(); i = adj.next()) {
      if (!visited[i->other(v)]) {
        minHeap.push(*i);
      }
    }
  }

  Graph &g;
  std::priority_queue<Edge<Weight>,
                      std::vector<Edge<Weight>>,
                      std::greater<Edge<Weight>>>
                            minHeap;
  std::vector<bool>         visited;
  std::vector<Edge<Weight>> mst;
  Weight                    mstWeight;
};

#endif /* __LAZY_PRIM_H__ */
