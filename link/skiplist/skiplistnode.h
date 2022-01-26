#ifndef __SKIPLISTNODE_H__
#define __SKIPLISTNODE_H__

template <typename K, typename V>
class SkipList;

template <typename K, typename V>
class SkipListNode {
public:
  SkipListNode() {
  }

  SkipListNode(K key, V value);

  virtual ~SkipListNode();

  K getKey() const;
  V getValue() const;

private:
  friend class SkipList<K, V>;

  K                    _key;
  V                    _value;
  SkipListNode<K, V> **_forward;
  int                  _nodeLevel;
};

template <typename K, typename V>
SkipListNode<K, V>::SkipListNode(K key, V value)
    : _key(key), _value(value), _nodeLevel(0) {
}

template <typename K, typename V>
SkipListNode<K, V>::~SkipListNode() {
  delete[] _forward;
}

template <typename K, typename V>
K SkipListNode<K, V>::getKey() const {
  return _key;
}

template <typename K, typename V>
V SkipListNode<K, V>::getValue() const {
  return _value;
}

#endif /* __SKIPLISTNODE_H__ */
