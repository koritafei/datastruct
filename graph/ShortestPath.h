/**
 * @ Description  :
 * @ Version      : 1.0
 * @ Author       : koritafei(koritafei@gmail.com)
 * @ Date         : 2021-06-06 20:23:33
 * @ LastEditors  : koritafei(koritafei@gmail.com)
 * @ LastEditTime : 2021-06-06 21:03:00
 * @ FilePath     : /datastruct/graph/ShortestPath.h
 * @ Copyright (C) 2021 koritafei(koritafei@gmail.com). All rights reserved.
 * */

#ifndef __SHORTEST_PATH_H__
#define __SHORTEST_PATH_H__

#include <queue>
#include <stack>
#include <vector>

template <class Graph>
class ShortestPath {
public:
  ShortestPath(Graph& graph, int v) : graph(graph), s(v) {
    visited = std::vector<bool>(graph.V(), false);
    from    = std::vector<int>(graph.V(), -1);
    ord     = std::vector<int>(graph.V(), -1);

    std::queue<int> q;
    // 无向图最短路径算法
    q.push(v);
    visited[v] = true;
    ord[v]     = 0;
    while (!q.empty()) {
      int t = q.front();
      q.pop();
      typename Graph::adjIterator adj(graph, t);
      for (int i = adj.begin(); !adj.end(); i = adj.next()) {
        if (!visited[i]) {
          q.push(i);
          visited[i] = true;
          from[i]    = t;
          ord[i]     = ord[t] + 1;
        }
      }
    }
  }

  ~ShortestPath() {
  }

  bool hasPath(int w) const {
    return visited[w];
  }

  void path(int w, std::vector<int>& path) {
    std::stack<int> s;
    int             p = w;
    while (p != -1) {
      s.push_back(p);
      p = from[p];
    }
    vec.clear();
    while (!s.empty()) {
      path.push_back(s.top());
      s.pop();
    }
  }

  void showPath(int w) const {
    std::vector<int>& res;
    path(w, res);
    for (auto item : res) {
      std::cout << item << " ";
    }
    std::cout << "\n";
  }

  int length(int w) const {
    return ord[w];
  }

private:
  Graph&            graph;
  int               s;
  std::vector<bool> visited;
  std::vector<int>  from;
  std::vector<int>  ord;
};

#endif /* __SHORTEST_PATH_H__ */
