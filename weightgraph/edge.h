/**
 * @ Description  :
 * @ Version      : 1.0
 * @ Author       : koritafei(koritafei@gmail.com)
 * @ Date         : 2021-06-07 15:29:48
 * @ LastEditors  : koritafei(koritafei@gmail.com)
 * @ LastEditTime : 2021-06-07 15:36:12
 * @ FilePath     : /datastruct/weightgraph/edge.h
 * @ Copyright (C) 2021 koritafei(koritafei@gmail.com). All rights reserved.
 * */

#ifndef __EDGE_H__
#define __EDGE_H__

#include <iostream>

template <class Weight>
class Edge {
public:
  Edge(int a, int b, Weight weight) : a(a), b(b), weight(weight) {
  }

  ~Edge() {
  }

  int v() const {
    return a;
  }

  int w() const {
    return b;
  }

  Weight wt() const {
    return weight;
  }

  int other(int v) {
    return v == a ? b : a;
  }

  friend std::ostream& operator<<(std::ostream& out, const Edge& e) {
    out << e.a << "-" << e.b << ": " << e.weight;
    return out;
  }

  bool operator<(const Edge& e) const {
    return weight < e.wt();
  }

private:
  int    a, b;
  Weight weight;
};

#endif /* __DENSE_GRAPH__ */
