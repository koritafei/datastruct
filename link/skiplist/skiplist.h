#ifndef __SKIPLIST_H__
#define __SKIPLIST_H__

#include <iostream>
#include <random>

#include "skiplistnode.h"

template <typename K, typename V>
class SkipList {
public:
  SkipList(K footerkey) {
    createList(footerkey);
  }

  ~SkipList() {
    freeList();
  }

  SkipListNode<K, V> *search(K key) const;

  bool insert(K key, V value);

  bool remove(K key, V &value);

  int size() const {
    return _nodeCount;
  }

  int getLevel() const {
    return _level;
  }

private:
  // 初始化列表
  void createList(K footerKey);

  // 释放表
  void freeList();

  // 创建新的节点层数为level
  void createNode(int level, SkipListNode<K, V> *&node);
  void createNode(int level, SkipListNode<K, V> *&node, K key, V value);

  // 随机生成一个level
  int getRandomLevel();

  void dumpAllNodes();

  void dumpNodeDetail(SkipListNode<K, V> *node, int level);

  int                 _level;
  SkipListNode<K, V> *_header;
  SkipListNode<K, V> *_footer;
  size_t              _nodeCount;
  static const int    MAXLEVEL = 16;
};

template <typename K, typename V>
int SkipList<K, V>::getRandomLevel() {
}
#endif /* __SKIPLIST_H__ */
