/**
 * @ Description  :
 * @ Version      : 1.0
 * @ Author       : koritafei(koritafei@gmail.com)
 * @ Date         : 2021-06-06 19:47:40
 * @ LastEditors  : koritafei(koritafei@gmail.com)
 * @ LastEditTime : 2021-06-06 20:12:37
 * @ FilePath     : /datastruct/graph/path.h
 * @ Copyright (C) 2021 koritafei(koritafei@gmail.com). All rights reserved.
 * */
#ifndef __PATH_H__
#define __PATH_H__

#include <stack>
#include <vector>

template <class Graph>
class Path {
public:
  Path(Graph& graph, int s) : graph(graph), s(s) {
    visited = std::vector<bool>(graph.V(), false);
    from    = std::vector<int>(graph.V(), -1);
  }

  ~Path() {
  }

  bool hasPath(int w) {
    return visited[w];
  }

  void path(int w, std::vector<int>& vec) {
    std::stack<int> s;
    int             p = w;
    while (p != -1) {
      s.push_back(p);
      p = from[p];
    }
    vec.clear();
    while (!s.empty()) {
      vec.push_back(s.top());
      s.pop();
    }
  }

  void showPath(int w) {
    std::vector<int>& res;
    path(w, res);
    for (auto item : res) {
      std::cout << item << " ";
    }
    std::cout << "\n";
  }

private:
  void dfs(int w) {
    visited[w] = true;
    typename Graph::adjIterator adj(graph, w);
    for (int i = adj.begin(); !adj.end(); i = adj.next()) {
      if (!visited[i]) {
        from[i] = i;
        dfs(i);
      }
    }
  }

  int               s;
  Graph&            graph;
  std::vector<bool> visited;
  std::vector<int>  from;
};
#endif /* __PATH_H__*/