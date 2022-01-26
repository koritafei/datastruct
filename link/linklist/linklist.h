// 单链表

#ifndef __LINKLIST_H__
#define __LINKLIST_H__

#include <iostream>

class IntSLList {
public:
  IntSLList() : head(nullptr), tail(nullptr) {
  }

  ~IntSLList();

  bool isEmpty() const {
    return head == nullptr;
  }

  void addHead(int);
  void addTail(int);

  int deleteFromHead();
  int deleteFromTail();

  void deleteNode(int);

  bool isInList(int) const;

  void print() {
    IntSLLNode *curr;
    for (curr = head; curr != nullptr; curr = curr->next) {
      std::cout << curr->info << ' ';
    }
    std::cout << std::endl;
  }

private:
  struct IntSLLNode {
    IntSLLNode() : info(0), next(nullptr) {
    }

    IntSLLNode(int el, IntSLLNode *ptr = nullptr) : info(el), next(ptr) {
    }

    int         info;
    IntSLLNode *next;
  };

  IntSLLNode *head, *tail;
};

#endif /* __LINKLIST_H__ */
