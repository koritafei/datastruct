/**
 * @ Description  :
 * @ Version      : 1.0
 * @ Author       : koritafei(koritafei@gmail.com)
 * @ Date         : 2021-06-08 14:53:29
 * @ LastEditors  : koritafei(koritafei@gmail.com)
 * @ LastEditTime : 2021-06-08 15:31:24
 * @ FilePath     : /datastruct/graphpath/dijkstra.h
 * @ Copyright (C) 2021 koritafei(koritafei@gmail.com). All rights reserved.
 * */

#ifndef __DIJSTRA_H__
#define __DIJSTRA_H__

#include <iostream>
#include <stack>
#include <vector>

#include "../weightgraph/edge.h"
#include "MaxIndexHeap.h"

template <typename Graph, typename Weight>
class Dijkstra {
public:
  Dijkstra(Graph& graph, int s) : graph(graph), s(s) {
    visited = std::vector<bool>(graph.V(), false);
    weight  = std::vector<Weight>(graph.V());
    from    = std::vector<Edge<Weight>*>(graph.V(), nullptr);

    MaxIndexHeap<Weight> ipq(graph.V());

    weight[s]  = Weight();
    visited[s] = true;
    ipq.insertItem(s, weight[s]);
    while (ipq.size()) {
      int v = ipq.getIndex();
      // weight[v],表示s到v的最短距离
      visited[v] = true;

      typename Graph::adjIterator adj(graph, v);
      for (Edge<Weight>* e = adj.begin(); !adj.end(); e = adj.next()) {
        int w = e->other(v);
        if (!visited[w]) {
          if (from[w] == nullptr || weight[v] + e->wt() < weight[w]) {
            weight[w] = e->wt() + weight[v];
            from[w]   = e;

            if (ipq.contains(w)) {
              ipq.changeItem(w, weight[w]);
            } else {
              ipq.insertItem(w, weight[w]);
            }
          }
        }
      }
    }
  }

  Weight shortestPathTo(int w) {
    return weight[w];
  }

  bool hasPathTo(int w) const {
    return visited[w];
  }

  void shortestPath(int w, std::vector<Edge<Weight>>& vec) {
    std::stack<Edge<Weight>*> s;
    Edge<Weight>*             e = from[w];
    while (e->v() != e->w()) {
      s.push(e);
      e = from[e->v()];
    }

    while (s.size() > 0) {
      e = s.top();
      vec.push_back(*e);
      s.pop();
    }
  }

private:
  Graph&                     graph;
  int                        s;
  std::vector<Weight>        weight;
  std::vector<bool>          visited;
  std::vector<Edge<Weight>*> from;
};
#endif /* __DIJSTRA_H__ */