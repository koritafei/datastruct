/**
 * @ Description  :
 * @ Version      : 1.0
 * @ Author       : koritafei(koritafei@gmail.com)
 * @ Date         : 2021-06-08 15:50:48
 * @ LastEditors  : koritafei(koritafei@gmail.com)
 * @ LastEditTime : 2021-06-08 16:12:02
 * @ FilePath     : /datastruct/graphpath/BellmanFord.h
 * @ Copyright (C) 2021 koritafei(koritafei@gmail.com). All rights reserved.
 * */

#ifndef __BELL_MAN_FORD_H__
#define __BELL_MAN_FORD_H__

#include <stack>
#include <vector>

#include "../weightgraph/edge.h"

template <typename Graph, typename Weight>
class BellmanFord {
public:
  BellmanFord(Graph& graph, int s) : graph(graph), s(s) {
    weight = std::vector<Weight>(graph.V());
    from   = std::vector<Edge<Weight>*>(graph.V(), nullptr);

    // Bellman-Ford
    weight[s] = Weight();
    for (int pass = 1; pass <= graph.V(); pass++) {
      for (int i = 0; i < graph.V(); i++) {
        typename Graph::adjIterator adj(graph, i);
        for (Edge<Weight>* e = adj.begin(); !adj.end(); e = adj.next()) {
          if (!from[e->w()] || weight[e->v()] + e->wt() < weight[e->w()]) {
            weight[e->w()] = weight[e->v()] + e->wt();
            from[e->w()]   = e;
          }
        }
      }
    }
  }

  bool negativeCycle() const {
    return hasNegativeCycle;
  }

  Weight shortestPathTo(int w) const {
    return weight[w];
  }

  bool hasPathTo(int w) const {
    return from[w];
  }

  void shortestPath(int w, std::vector<Edge<Weight>>& vec) {
    std::stack<Edge<Weight>*> stack;
    Edge<Weight>*             e = from[w];
    while (e->w() != this->s) {
      stack.push(e);
      e = from[e->v()];
    }
    stack.push(e);

    while (stack.size()) {
      Edge<Weight>* e = stack.top();
      vec.push(e);
      stack.pop();
    }
  }

private:
  Graph&                     graph;
  int                        s;
  std::vector<Weight>        weight;
  std::vector<Edge<Weight>*> from;
  bool                       hasNegativeCycle;
};

#endif /* __BELL_MAN_FORD_H__ */