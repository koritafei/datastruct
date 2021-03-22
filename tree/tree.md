# 树

## 树节点表示

```cpp
/**
 * @file treenode.hpp
 * @author koritafei (koritafei@gmail.com)
 * @brief tree node define
 * @version 0.1
 * @date 2020-09-13
 *
 * @copyright Copyright (c) 2020
 *
 */

#ifndef __TREENODE__H__
#define __TREENODE__H__

template <typename T>
struct TreeNode {
  T         object_;
  TreeNode *firstChild;   // 第一个儿子
  TreeNode *nextSlibing;  // 下一个兄弟
};

#endif  //!__TREENODE__H__
```

## 二叉树

定义：每个节点的孩子数不超过$2$个。  
性质 1：平均二叉树的深度比节点个数$N$小得多。平均深度为$O(\sqrt{N})$。  
对特殊类型的二叉树，即二叉查找树(binary search tree)，其平均深度的均值为$O(log^N)$。  
二叉树节点定义：

```cpp
/**
 * @file binarytreenode.hpp
 * @author koritafei (koritafei@gmail.com)
 * @brief binary tree node define
 * @version 0.1
 * @date 2020-09-13
 *
 * @copyright Copyright (c) 2020
 *
 */

#ifndef __BINARYTREENODE__H__
#define __BINARYTREENODE__H__

template <typename T>
struct BinaryNode {
  T           object_;
  BinaryNode *left_;
  BinaryNode *right_;
};

#endif  //!__BINARYTREENODE__H__
```
