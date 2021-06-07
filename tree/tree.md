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
## `trie`字典树
字典树，哈希树的变种。典型应用：统计和排序大量字符串。
基本性质：
1. 根节点不包含字符，除根节点外，每个节点都只包含一个字符；
2. 从根节点到某一节点，路径上经过的字符连接起来，为该节点对应的字符串；
3. 每个节点的所有子节点包含的字符否不相同。

### 应用场景
查找的时间复杂度为: $O(n)$
1. 串快速检索
   给出$N$个单词组成的熟词表，以及一篇全用小写英文书写的文章，请你按照最早出现的顺序写出所有不在熟词表中的生词。
2. 单词自动完成
   编辑代码时，输入字符，自动提示可能的关键字、变量或函数等信息。
3. 最长公共前缀
   对所有串建立字典树，对于两个串的最长公共前缀的长度即他们所在的节点的公共祖先个数，问题转化为最近公共祖先问题。
4. 串排序方面的应用
   给定N个互不相同的仅由一个单词构成的英文名，让你将他们按字典序从小到大输出用字典树进行排序，采用数组的方式创建字典树，这棵树的每个结点的所有儿子很显然地按照其字母大小排序。对这棵树进行先序遍历即可。
### 实现
1. 初始化操作
   根节点初始化为空，所有字符串从下一层开始。
   每个节点有26个指针，指向下一层子节点，每个节点代表一个不同的字符。
   每个节点保存一个`isEnd`变量，用来标识给节点是不是某个字符串的结束位置。
2. 插入字符串
   从根节点向下递归，如果字符串中下一个字母对应的子节点为空，则新建节点继续递归,否则直接递归。
   最后一个节点的`isEnd`置为`1`,表示这个节点是字符串结束的位置。
3. 查询字符串
   从根节点往下递归查找，如果字符串没有遍历结束,但节点已经空了，则节点不存在。否则继续递归，查找到最后一个字符，判断该节点的`isEnd`是否为`1`.
4. 查询字符串前缀
   同查询字符串方法，无需判断`isEnd`的值。
5. 删除字符串
   从上到下递归，将节点放入一个`stack`中，对需要删除的节点有两种判断：
   a. 如果非叶子节点, 将`isEnd`置为`0`;
   b. 对叶子节点，从`stack`开始删除，直到栈顶节点为飞叶子节点，或`isEnd`为1.

## 并查集
对一组数据主要支持两个操作：
1. union(p,q) // 连接p和q
2. find(p) // 查找p




