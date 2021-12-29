/**
 * @file: bst.cpp
 * @description:
 * @author: koritafei
 * @create: 2021-05-31 14:42
 * @version v0.1
 * */

#include <iostream>
#include <queue>

template <class Key, class Value>
class BST {
public:
  BST() : _root(nullptr), _count(0) {
  }

  ~BST() {
  }

  bool empty() const {
    return _root == nullptr;
  }

  int size() const {
    return _count;
  }

  void insert(Key key, Value value) {
    _root = __insert(_root, key, value);
  }

  bool contain(Key key) const {
    return __contain(_root, key);
  }

  void *searchBST(Key key) {
    void *ret = nullptr;
    if (nullptr == _root) {
      return ret;
    }

    if (key == _root->_key) {
      return static_cast<void *>(&(_root->value));
    } else if (key < _root->_key) {
      return searchBST(_root->left);
    } else if (key > _root->_key) {
      return searchBST(_root->right);
    }

    return ret;
  }

  void inOrder() {
    // 中序
    if (nullptr != _root) {
      __inOrder(_root);
      std::cout << "\n";
    }
  }

  void preOrder() {
    // 前序

    if (nullptr != _root) {
      __preOrder(_root);
      std::cout << "\n";
    }
  }

  void postOrder() {
    // 后序

    if (nullptr != _root) {
      __postOrder(_root);
      std::cout << "\n";
    }
  }

  void destroy() {
    if (nullptr != _root) {
      destroy(_root->left);
      destroy(_root->right);

      delete _root;
      _root = nullptr;
    }
  }

  // 层序遍历
  void levelOrder() {
    if (nullptr != _root) {
      __levelOrder(_root);
    }
  }

  // 寻找最小值
  Key minium() {
    Node *node = minium(_root);
    if (node == nullptr) {
      return 0;
    }

    return node->_key;
  }

  // 寻找最大值
  Key maxium() {
    Node *node = maxiumNode(_root);
    if (node == nullptr) {
      return 0;
    }

    return node->_key;
  }

  // 删除最小值节点
  void deleteMinium() {
    _root = deleteMinium(_root);
  }

  // 删除最大值节点
  void deleteMaxium() {
    _root = deleteMaxium(_root);
  }

  // 删除任意节点
  void deleteNode(Key key) {
    _root = deleteNode(_root, key);
  }

private:
  struct Node {
    Key   _key;
    Value _value;
    Node *left, *right;

    Node(Key key, Value value) : _key(key), _value(value) {
      this->left = this->right = nullptr;
    }

    Node(Node *n) {
      this->left   = n->left;
      this->right  = n->right;
      this->_value = n->_value;
      this->_key   = n->_key;
    }
  };

  Node *deleteNode(Node *node, Key key) {
    if (nullptr == node) {  // 没有找到，直接返回
      return;
    }

    if (key < node->_key) {
      // 删除节点比当前节点小，继续删除左子树
      node->left = deleteNode(node->left, key);
      return node;
    } else if (key > node->_key) {
      // 当前节点key比给定值小，删除右子树
      node->right = deleteNode(node->right);
      return node;
    } else if (key == node->_key) {
      // 只有左子树
      if (nullptr == node->right) {
        Node *leftNode = node->left;
        _count--;
        delete node;
        return leftNode;
      }

      // 只有右子树
      if (nullptr == node->left) {
        Node *rightNode = node->right;
        _count--;
        delete node;
        return rightNode;
      }

      // 同时含有左右子树
      // 取右子树的最小节点，替换当前节点
      Node *curr  = new Node(miniumNode(node->right));
      curr->right = deleteMinium(node->right);
      curr->left  = node->left;
      _count--;
      delete node;

      return curr;
    }
  }

  Node *deleteMinium(Node *node) {
    if (nullptr == node->left) {
      Node *right = node->right;
      return right;
    }

    node->left = deleteMinium(node->left);
    return node;
  }

  Node *deleteMaxium(Node *node) {
    if (nullptr == node->right) {
      Node *left = node->left;
      return left;
    }

    node->right = deleteMaxium(node->right);
    return node;
  }

  Node *miniumNode(Node *node) {
    if (node->left == nullptr) {
      return node;
    }

    return miniumNode(node->left);
  }

  Node *maxumNode(Node *node) {
    if (node->right == nullptr) {
      return node;
    }

    return maxumNode(node->right);
  }

  void __levelOrder(Node *node) {
    std::queue<Node *> q;
    q.push(node);
    while (!q.empty()) {
      Node *t = q.front();
      q.pop();
      std::cout << t->_value << " ";
      if (t->left) {
        q.push(t->left);
      }
      if (t->right) {
        q.push(t->right);
      }
    }

    std::cout << "\n";
  }

  void __inOrder(Node *node) {
    __inOrder(node->left);
    std::cout << node->_value << " ";
    __inOrder(node->right);
  }

  void __preOrder(Node *node) {
    std::cout << node->_value << " ";
    __preOrder(node->left);
    __preOrder(node->right);
  }

  void __postOrder(Node *node) {
    __postOrder(node->left);
    __postOrder(node->right);
    std::cout << node->_value << " ";
  }

  bool __contain(Node *node, Key key) {
    if (key == node->_key) {
      return true;
    } else if (key > node->_key) {
      return __contain(node->right, key);
    } else if (key < node->key) {
      return __contain(node->left, key);
    }
  }

  Node *__insert(Node *node, Key key, Value value) {
    if (nullptr == node) {
      return new Node(key, value);
    }

    if (key == node->key) {
      node->value = value;
    } else if (key < node->key) {
      node->left = __insert(node->left, key, value);
    } else if (key > node->key) {
      node->right = __insert(node->right, key, value);
    }

    return node;
  }

  Node *_root;
  int   _count;
};

int main(int argc, char **argv) {
}
