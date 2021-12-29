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
private:
  std::vector<Edge<Weight>> mst;
  Weight                    mstWeight;
};

#endif /* __KRUSKAL_MST_H__ */
