/**
 * @file binarysearch.hpp
 * @author koritafei (koritafei@gmail.com)
 * @brief 二叉搜索树
 * @version 0.1
 * @date 2020-09-15
 *
 * @copyright Copyright (c) 2020
 *
 */

#ifndef __BINARY_SEARCH_TREE_
#define __BINARY_SEARCH_TREE_

#include <iostream>

const int Nan = -1;

template <typename T, typename compare = std::less<T>>
class BinarySearchTree {
public:
  BinarySearchTree();
  BinarySearchTree(const BinarySearchTree &rhs);
  ~BinarySearchTree();

  const T &findMin() const;
  const T &findMax() const;
  bool     contains(const T &x) const;
  bool     isEmpty() const;
  void     printTree() const;

  void makeEmpty();
  void insert(const T &x);
  void remove(const T &x);

  const BinarySearchTree &operator=(const BinarySearchTree &rhs);

private:
  struct BinaryNode {
    T           element;
    BinaryNode *left;
    BinaryNode *right;

    BinaryNode(const T &data, BinaryNode *lt, BinaryNode *rt)
        : element(data),
          left(lt),
          right(rt) {
    }
  };

  BinaryNode *root;
  compare     isLessThan;

  void        insert(const T &x, BinaryNode *&t);
  void        remove(const T &x, BinaryNode *&t);
  BinaryNode *findMin(BinaryNode *t) const {
    if (nullptr == t) {
      return nullptr;
    } else if (t->left == nullptr) {
      return t;
    } else {
      return findMin(t->left);
    }
  }
  BinaryNode *findMax(BinaryNode *t) const {
    if (nullptr != t) {
      while (nullptr != t->right) {
        t = t->right;
      }
    }
    return t;
  }
  bool        contains(const T &x, BinaryNode *&t) const;
  void        makeEmpty(BinaryNode *&t);
  void        printTree(BinaryNode *t) const;
  BinaryNode *clone(BinaryNode *t);
};

template <typename T, typename compare>
bool BinarySearchTree<T, compare>::contains(const T &x) const {
  return contains(x, root);
}

template <typename T, typename compare>
void BinarySearchTree<T, compare>::insert(const T &x) {
  insert(x, root);
}

template <typename T, typename compare>
void BinarySearchTree<T, compare>::remove(const T &x) {
  remove(x, root);
}

template <typename T, typename compare>
bool BinarySearchTree<T, compare>::contains(const T &x, BinaryNode *&t) const {
  if (t == nullptr) {
    return false;
  } else if (isLessthen(x < t->element)) {
    return contains(x, t->left);
  } else if (isLessThan(x > t->element)) {
    return contains(x, t->right);
  } else {
    return true;
  }
}

template <typename T, typename compare>
const T &BinarySearchTree<T, compare>::findMin() const {
  BinaryNode *res = findMin(root);
  if (nullptr != res) {
    return res->element;
  }
  return Nan;
}

template <typename T, typename compare>
const T &BinarySearchTree<T, compare>::findMax() const {
  return findMax(root);
}

template <typename T, typename compare>
void BinarySearchTree<T, compare>::insert(const T &x, BinaryNode *&t) {
  if (nullptr != t) {
    if (x < t->element) {
      insdert(x, t->element);
    } else if (x > t->element) {
      insert(x, t->right);
    } else {
      return;
    }
  } else {
    t = new BinaryNode(x, nullptr, nullptr);
  }
}

#endif  // !__BINARY_SEARCH_TREE_
