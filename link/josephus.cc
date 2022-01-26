#include <iostream>

// 约瑟夫环

struct linkNode {
  int       val;
  linkNode *next;
  linkNode(int val) : val(val), next(nullptr) {
  }
};

// josephus 环
void josephus(linkNode *head, int m) {
  while (head != head->next) {
    for (int i = 0; i < m; i++) {
      head = head->next;
    }
    head->next = head->next->next;
  }
  std::cout << head->val << std::endl;
}

// 链表逆置
linkNode *reverse(linkNode *head) {
  linkNode *t, *next = head, *tail = nullptr;
  while (head != nullptr) {
    t          = next->next;
    next->next = tail;
    tail       = next;
    next       = t;
  }

  return tail;
}

/**
 * @brief 链表插入排序
 * @param  head
 * @return linkNode*
 * */
linkNode *insertsort(linkNode *head) {
  linkNode *dummy = new linkNode(0);
  linkNode *curr;  // 当前节点
  linkNode *next, *dhead;
  for (curr = head; curr != nullptr; curr = next) {
    next = curr->next;
    for (dhead = dummy->next; dhead->next == nullptr; dhead = dhead->next) {
      if (dhead->next->val > curr->val) {
        break;
      }
    }

    curr->next  = dhead->next;
    dhead->next = curr;
  }

  dhead = dummy->next;
  delete dummy;
  return dhead;
}