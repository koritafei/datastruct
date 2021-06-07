/**
 * @ Description  :
 * @ Version      : 1.0
 * @ Author       : koritafei(koritafei@gmail.com)
 * @ Date         : 2021-06-05 20:22:28
 * @ LastEditors  : koritafei(koritafei@gmail.com)
 * @ LastEditTime : 2021-06-06 09:51:48
 * @ FilePath     : /datastruct/graph/Component.h
 * @ Copyright (C) 2021 koritafei(koritafei@gmail.com). All rights reserved.
 * */

#ifndef __COMPONENT_H__
#define __COMPONENT_H__

#include <iostream>
#include <vector>

template <class Graph>
class Component {
public:
  Component(Graph& graph) : graph(graph), count(0) {
    visited = std::vector<bool>(graph.V(), false);
  }

  ~Component() {
  }

  void dfs() {
    for (int i = 0; i < graph.V(); i++) {
      if (!visited[i]) {
        __dfs(i);
        count++;
      }
    }
  }

private:
  void __dfs(int v) {
    visited[v] = true;
    typename Graph::adjIterator adj(graph, v);
    for (int i = adj.begin(); !adj.end(); i = adj.next()) {
      if (!visited[i]) {
        dfs(i);
        count++;
      }
    }
  }

  Graph&            graph;
  std::vector<bool> visited;
  int               count;  // 连通分量个数
};

#endif /* __COMPONENT_H__ */
