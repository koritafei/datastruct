/**
 * @ Description  : trie 树
 * @ Version      : 1.0
 * @ Author       : koritafei(koritafei@gmail.com)
 * @ Date         : 2021-06-01 11:17:50
 * @ LastEditors  : koritafei(koritafei@gmail.com)
 * @ LastEditTime : 2021-06-01 14:55:34
 * @ FilePath     : /datastruct/tree/trie.cpp
 * @ Copyright (C) 2021 koritafei(koritafei@gmail.com). All rights reserved.
 * */

#include <iostream>
#include <stack>
#include <vector>

class Trie {
public:
  Trie() : _isEnd(false) {
    _next = std::vector<Trie *>(26, 0);
  }

  ~Trie() {
    for (auto t : _next) {
      delete t;
    }
  }

  void insert(std::string &word) {
    Trie *node = this;
    for (auto w : word) {
      if (nullptr == node->_next[w - 'a']) {
        node->_next[w - 'a'] = new Trie();
      }
      node = node->_next[w - 'a'];
    }

    node->_isEnd = true;
  }

  bool search(std::string &word) {
    Trie *node = this;
    for (auto w : word) {
      if (nullptr == node->_next[w - 'a']) {
        return false;
      }
      node = node->_next[w - 'a'];
    }

    return node->_isEnd;
  }

  bool startWith(std::string &word) {
    Trie *node = this;
    for (auto w : word) {
      if (nullptr == node->_next[w - 'a']) {
        return false;
      }
      node = node->_next[w - 'a'];
    }

    return true;
  }

  bool isLeaf(Trie *node) {
    for (auto item : node->_next) {
      if (!item) {
        return false;
      }
    }

    return true;
  }

  void del(std::string &word) {
    std::stack<Trie *> st;
    Trie *             node = this;
    for (auto w : word) {
      node = node->_next[w - 'a'];
      st.push(node);
      if (nullptr == node) {
        return;
      }
    }

    if (!node->_isEnd) {
      return;
    }

    if (!isLeaf(node)) {
      node->_isEnd = false;
      return;
    }

    delete node;
    st.pop();
    while (!st.empty()) {
      node = st.top();
      st.pop();
      if (isLeaf(node) && !node->_isEnd) {
        delete node;
      } else {
        break;
      }
    }
  }

private:
  bool                _isEnd;
  std::vector<Trie *> _next;
};

int main(int argc, char **argv) {
  Trie *      trie = new Trie();
  std::string word = "hello";
  trie->insert(word);
  word = "worddd";
  trie->insert(word);
  word = "wordwordword";
  trie->insert(word);
  word = "word";
  std::cout << trie->search(word) << std::endl;
  std::cout << trie->startWith(word) << std::endl;
  delete trie;
  trie = nullptr;
}