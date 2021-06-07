/**
 * @ Description  :
 * @ Version      : 1.0
 * @ Author       : koritafei(koritafei@gmail.com)
 * @ Date         : 2021-06-07 20:40:06
 * @ LastEditors  : koritafei(koritafei@gmail.com)
 * @ LastEditTime : 2021-06-07 21:25:07
 * @ FilePath     : /datastruct/weightgraph/kruskalmst.h
 * @ Copyright (C) 2021 koritafei(koritafei@gmail.com). All rights reserved.
 * */

#ifndef __KRUSKAL_MST_H__
#define __KRUSKAL_MST_H__

#include <iostream>
#include <queue>

#include "edge.h"
#include "unionTree.h"

template <typename Graph, typename Weight>
class KrulkalMst {
public:
  KrulkalMst(Graph &graph) {
    std::priority_queue<Edge<Weight>,
                        std::vector<Edge<Weight>>,
                        std::greater<Edge<Weight>>>
        pq;
    for (int i = 0; i < graph.V(); i++) {
      typename Graph::adjIterator adj(graph, i);
      for (Edge<Weight> *e = adj.begin(); !adj.end(); e = adj.next()) {
        if (e->v() < e->w()) {
          pq.push(*e);
        }
      }
    }

    Union un(graph.V());
    while (pq.size() && mst.size() < graph.V() - 1) {
      Edge<Weight> *e = pq.top();
      pq.pop();
      if (un.isConnected(e->v(), e->w())) {
        continue;
      }
      mst.push_back(*e);
      un.unionElement(e->v(), e->w());
    }

    mstWeight = mst[0].wt();
    for (int i = 1; i < mst.size(); i++) {
      mstWeight += mst[i].wt();
    }
  }

  ~KrulkalMst() {
  }

  std::vector<Edge<Weight>> mstEdges() const {
    return mst;
  }

  Weight weight() const {
    return weight;
  }

private:
  std::vector<Edge<Weight>> mst;
  Weight                    mstWeight;
};

#endif /* __KRUSKAL_MST_H__ */
