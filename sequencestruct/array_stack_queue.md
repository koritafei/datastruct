# 表、栈和队列
## 表(ADT)
### 向量的实现
```cpp
/**
 * @file vector.hpp
 * @author koritafei (koritafei@gmail.com)
 * @brief 向量的实现
 * @version 0.1
 * @date 2020-08-27
 *
 * @copyright Copyright (c) 2020
 *
 */
#ifndef __VECTOR__H__
#define __VECTOR__H__

#include <iostream>

template <typename T>
class Vector {
public:
  explicit Vector(size_t size = 0)
      : size_(size),
        capacity_(size + SPARE_CAPACITY) {
    data_ = new T[size];
  }

  Vector(const Vector& rhs) : data_(nullptr) {
    operator=(rhs);
  }

  ~Vector() {
    delete[] data_;
  }

  const Vector& operator=(const Vector& rhs) {
    if (this != &rhs) {
      delete[] data_;
      size_     = rhs.size();
      capacity_ = rhs.capacity();
      data_     = new T[capacity_];
      for (size_t i = 0; i < size_; i++) {
        data_[i] = rhs.data_[i];
      }
    }

    return *this;
  }

  void resize(size_t newSize) {
    if (newSize > capacity_) {
      reserve(newSize * 2 + 1);
    }
    size_ = newSize;
  }

  void reserve(size_t newCapacity) {
    if (newCapacity < size_) {
      return;
    }
    T* old_data_ = data_;
    data_        = new T[newCapacity];
    for (size_t i = 0; i < size_; i++) {
      data_[i] = old_data_[i];
    }
    capacity_ = newCapacity;
    delete[] old_data_;
  }

  T& operator[](size_t index) {
    return data_[index];
  }

  const T& operator[](size_t index) const {
    return data_[index];
  }

  int size() const {
    return size_;
  }

  int capacity() const {
    return capacity_;
  }

  bool IsEmpty() const {
    return size_ == 0;
  }

  void push_back(const T& val) {
    if (size_ == capacity_) {
      reserve(size_ * 2 + 1);
    }

    data_[size_++] = val;
  }

  void pop_back() {
    size_--;
  }

  const T& back() const {
    return data_[size_ - 1];
  }

  typedef T*       iterator;
  typedef const T* const_iterator;

  iterator begin() {
    return &data_[0];
  }

  iterator end() {
    return &data_[size()];
  }

  const_iterator begin() const {
    return &data_[0];
  }

  const_iterator end() const {
    return &data_[size()];
  }

  enum { SPARE_CAPACITY = 16 };

private:
  size_t size_;
  size_t capacity_;
  T*     data_;
};

#endif  //!__VECTOR__H__
```
### 链表
```cpp
/**
 * @file list.hpp
 * @author koritafei (koritafei@gmail.com)
 * @brief 链表定义
 * @version 0.1
 * @date 2020-08-25
 *
 * @copyright Copyright (c) 2020
 *
 */

#ifndef __LIST__H__
#define __LIST__H__

#include <iostream>

template <typename T>
class List {
private:
  struct Node {
    T     data_;
    Node *prev_;
    Node *next_;

    Node(const T &d = T(), Node *p = nullptr, Node *n = nullptr)
        : data_(d),
          prev_(p),
          next_(n) {
    }
  };

public:
  class const_iterator {
  public:
    const_iterator() : current(nullptr) {
    }

    const T &operator*() const {
      return retrive();
    }

    const_iterator operator++(int) {
      const_iterator *old = this;
      ++(*this);
      return old;
    }

    bool operator==(const const_iterator &rhs) const {
      return current == rhs.curent;
    }

    bool operator!=(const const_iterator &rhs) const {
      return !(*this == rhs);
    }

  protected:
    Node *current;
    T &   retrive() const {
      return current->data_;
    }
    const_iterator(Node *p) : current(p) {
    }

    friend class List<T>;
  };

  class iterator : public const_iterator {
  public:
    iterator() {
    }

    T &operator*() {
      return const_iterator::retrive();
    }

    const T &operator*() const {
      return const_iterator::operator*();
    }

    iterator &operator++() {
      const_iterator::current = const_iterator::current->next;
      return *this;
    }

    iterator operator++(int) {
      iterator old = *this;
      ++(*this);
      return old;
    }

  protected:
    iterator(Node *p) : const_iterator(p) {
    }
    friend class List<T>;
  };

  List() {
    init();
  }

  ~List() {
    clear();
    delete head_;
    delete tail_;
  }

  List(const List &rhs) {
    init();
    *this = rhs;
  }

  const List &operator=(const List &rhs) {
    if (*this == rhs) {
      return *this;
    }
    clear();
    for (const_iterator iter = rhs.begin(); iter != rhs.end(); iter++) {
      push_back(*iter);
    }
    return *this;
  }

  iterator begin() {
    return iterator(head_->next_);
  }

  const_iterator begin() const {
    return const_iterator(head_->next_);
  }

  iterator end() {
    return iterator(tail_);
  }

  const_iterator end() const {
    return const_iterator(tail_);
  }

  int size() const {
    return size_;
  }

  bool empty() const {
    return size_ == 0;
  }

  void clear() {
    while (!empty()) {
      pop_front();
    }
  }

  T &front() {
    return *begin();
  }

  const T &front() const {
    return *begin();
  }

  T &back() {
    return *--end();
  }

  const T &back() const {
    return *--end();
  }

  void push_front(const T &val) {
    insert(begin(), val);
  }

  void push_back(const T &val) {
    insert(end(), val);
  }

  void pop_front() {
    erase(begin());
  }

  void pop_back() {
    erase(end());
  }

  iterator insert(iterator itr, const T &val) {
    Node *p = itr.current;
    size_++;
    return iterator(p->prev_ = p->prev_->next_ = new Node(val, p->prev_, p));
  }

  iterator erase(iterator itr) {
    Node *   p = itr.current;
    iterator retVal(p->next_);
    p->prev_->next_ = p->next_;
    p->next_->prev_ = p->prev_;
    delete p;
    size_--;

    return retVal;
  }

  iterator erase(iterator start, iterator end) {
    for (iterator itr = start; itr != end;) {
      itr = erase(itr);
    }
    return end;
  }

private:
  size_t size_;
  Node * head_;
  Node * tail_;

  void init() {
    size_        = 0;
    head_        = new Node;
    tail_        = new Node;
    head_->next_ = tail_;
    tail_->prev_ = head_;
  }
};

#endif  //!__LIST__H__
```
### 栈
```cpp
/**
 * @file stack.hpp
 * @author koritafei (koritafei@gmail.com)
 * @brief 链表实现栈
 * @version 0.1
 * @date 2020-08-30
 *
 * @copyright Copyright (c) 2020
 *
 */

#ifndef __STACK__H__
#define __STACK__H__

#include <iostream>

#include "list/list.hpp"

template <typename T>
class Stack {
public:
  Stack() {
  }

  bool IsEmpty() const {
    return data_.empty();
  }

  size_t size() const {
    return data_.size();
  }

  void push(const T &val) {
    data_.push_back(val);
  }

  T pop() {
    T front = data_.front();
    data_.pop_front();
    return front;
  }

  void clear() {
    data_.clear();
  }

  T top() {
    return data_.front();
  }

private:
  List<T> data_;
};

#endif  //!__STACK__H__
```
#### 栈的应用1-括号匹配
```cpp
/**
 * @file bracket_match.cc
 * @author koritafei (koritafei@gmail.com)
 * @brief 栈的应用：括号匹配
 * @version 0.1
 * @date 2020-08-31
 *
 * @copyright Copyright (c) 2020
 *
 */

#include <iostream>
#include <stack>

bool bracket_match(std::string &input) {
  std::stack<char> s;
  size_t           len = input.length();
  for (size_t i = 0; i < len; i++) {
    switch (input[i]) {
      case '(':
      case '{':
      case '[':
        s.push(input[i]);
        break;
      case ')':
        if (!s.empty() && s.top() == '(') {
          s.pop();
          break;
        } else {
          return false;
        }
      case ']':
        if (!s.empty() && s.top() == '[') {
          s.pop();
          break;
        } else {
          return false;
        }
      case '}':
        if (!s.empty() && s.top() == '{') {
          s.pop();
          break;
        } else {
          return false;
        }
      default:
        break;
    }
  }

  return s.empty();
}

int main(int argc, char **argv) {
  std::string s = "((())){{}}jjjksdjksjdk[][]{[()]}";
  std::cout << bracket_match(s) << std::endl;
}
```
#### 栈应用2-表达式求值
前缀表达式：运算符在操作数之前。  
后缀表达式：运算符在操作数之后。
中缀表达式转前缀表达式：
```cpp
/**
 * @file ploy.cc
 * @author koritafei (koritafei@gmail.com)
 * @brief 栈应用2-前/后缀表达式
 * @version 0.1
 * @date 2020-08-31
 *
 * @copyright Copyright (c) 2020
 *
 */

#include <iostream>
#include <map>
#include <sstream>
#include <stack>

class Ploy {
public:
  /**
   * @brief 求前缀表达式
   *
   * @param source
   * @return std::string
   */
  std::string prefix_ploy(std::string &source) {
    int         len = source.length();
    std::string res;
    std::string number;
    for (int i = len - 1; i >= 0; i--) {
      res.clear();
      if (!is_space(source[i])) {
        char_to_string(source[i], res);
        if (is_number(source[i])) {
          number = res + number;
          continue;
        } else {
          stack2.push(number);
          number.clear();
          process_operator(source[i], res);
        }
      }
    }

    // 处理最后一个数
    stack2.push(number);

    while (!stack1.empty()) {
      stack2.push(stack1.top());
      stack1.pop();
    }

    res.clear();
    while (!stack2.empty()) {
      res += stack2.top() + " ";
      stack2.pop();
    }

    return res;
  }

  /**
   * @brief 求后缀表达式
   *
   * @param source
   * @return std::string
   */
  std::string ploy_back(std::string &source) {
    int         len = source.length();
    std::string result;
    std::string number;
    for (int i = 0; i < len; i++) {
      number.clear();
      if (!isspace(source[i])) {
        char_to_string(source[i], number);
        if (is_number(source[i])) {
          result.append(number + " ");
        } else {
          process_operator(source[i], result, number);
        }
      }
    }

    while (!stack1.empty()) {
      result.append(stack1.top());
      stack1.pop();
    }

    return result;
  }

private:
  bool is_space(char ch) const {
    return ch == ' ';
  }

  void process_operator(char ch, std::string &res, std::string &number) {
    switch (ch) {
      case '(':
        stack1.push(number);
        break;
      case ')':
        operator_bracket(res);
        break;
      default:
        operator_compare(res, number);
        break;
    }
  }

  void operator_compare(std::string &res, std::string &number) {
    while (!stack1.empty() && m[stack1.top()] >= m[number] &&
           stack1.top() != "(") {
      res.append(stack1.top() + " ");
      stack1.pop();
    }
    stack1.push(number);
  }

  void operator_bracket(std::string &res) {
    while (!stack1.empty() && stack1.top() != "(") {
      res.append(stack1.top() + " ");
      stack1.pop();
    }
    if (!stack1.empty()) {
      stack1.pop();  // 弹出"("
    }
  }

  void process_operator(char ch, std::string &res) {
    switch (ch) {
      case ')':
        stack1.push(res);
        break;
      case '+':
      case '-':
      case '*':
      case '/':
      case '%':
        operator_compare(res);
        break;
      case '(':
        operator_bracket();
        break;
    }
  }

  bool is_number(char ch) const {
    return ch >= '0' && ch <= '9';
  }

  // char 字符转string
  void char_to_string(char ch, std::string &res) {
    res.push_back(ch);
  }

  void operator_bracket() {
    while (!stack1.empty() && stack1.top() != ")") {
      stack2.push(stack1.top());
      stack1.pop();
    }
    if (!stack1.empty()) {
      stack1.pop();  // 丢弃(
    }
  }

  // 比较操作符优先级
  void operator_compare(std::string target) {
    if (stack1.empty() || stack1.top() == ")" || m[stack1.top()] <= m[target]) {
      // 直接入栈
      stack1.push(target);
    } else {
      // 否则栈顶弹出
      while (!stack1.empty() && m[stack1.top()] > m[target]) {
        stack2.push(stack1.top());
        stack1.pop();
      }
      stack1.push(target);
    }
  }

  std::map<std::string, int> m = {{"+", 0},
                                  {"-", 0},
                                  {"*", 1},
                                  {"/", 1},
                                  {"%", 1}};

  std::stack<std::string> stack1;
  std::stack<std::string> stack2;
};

int main(int argc, char **argv) {
  std::string source = "1 + (2 + 3) * 4 - 5";
  std::cout << "中缀表达式：" << source << std::endl;
  Ploy ploy;
  std::cout << "前缀表达式：" << ploy.prefix_ploy(source)
            << std::endl;  // - + 1 * + 2 3 4 5
  std::cout << "后缀表达式：" << ploy.ploy_back(source)
            << std::endl;  // 1 2 3 + 4 * + 5 -
}
```
### 队列
```cpp
/**
 * @file queue.hpp
 * @author koritafei (koritafei@gmail.com)
 * @brief 双端队列实现
 * @version 0.1
 * @date 2020-09-07
 *
 * @copyright Copyright (c) 2020
 *
 */

#ifndef __QUEUE__H__
#define __QUEUE__H__

#include <cstring>
#include <iostream>

template <typename T>
class Queue {
public:
  Queue() : cap_(capacity), front_(0), back_(capacity - 1) {
    data_ = new T[capacity];
  }

  ~Queue() {
    if (data_) {
      delete[] data_;
    }
    cap_ = 0;
  }

  Queue(Queue &rhs) {
    data_ = rhs.data_;
    cap_  = rhs.cap_;
    delete[] rhs.data_;
    rhs.data_ = nullptr;
    rhs.size_ = 0;
    rhs.cap_  = 0;
  }
  Queue &operator=(Queue &rhs) {
    data_ = rhs.data_;
    cap_  = rhs.cap_;
    delete[] rhs.data_;
    rhs.data_ = nullptr;
    rhs.size_ = 0;
    rhs.cap_  = 0;
  }

  void push_front(T data) {
    if (full()) {
      resize();
    }
    data_[(front_ + cap_ - 1) % cap_] = data;
    front_                            = (front_ + cap_ - 1) % cap_;
  }

  void push_back(T data) {
    if (full()) {
      resize();
    }
    data_[(back_ + cap_ + 1) % cap_] = data;
    back_                            = (back_ + cap_ + 1) % cap_;
  }

  void pop_front() {
    if (!empty()) {
      front_ = (front_ + 1) % cap_;
    }
  }

  void pop_back() {
    if (!empty()) {
      back_ = (back_ + cap_ - 1) % cap_;
    }
  }

  T front() {
    return data_[front_];
  }

  T back() {
    return data_[back_];
  }

  size_t size() {
    return (front_ + cap_ - back_) % cap_;
  }

  bool empty() {
    return front_ == back_;
  }

private:
  /**
   * @brief 扩充队列，每次扩充为原来大小的2倍
   *
   */
  void resize() {
    T *    old     = data_;
    size_t old_cap = cap_;
    cap_ <<= 1;
    data_ = new T[cap_];
    for (size_t i = 0; i < old_cap; i++) {
      data_[i] = old[i];
    }

    delete[] old;
    old = nullptr;
  }

  bool full() {
    return size() == cap_;
  }

  const size_t capacity = 20;
  T *          data_;
  size_t       cap_;
  size_t       front_;
  size_t       back_;
};

#endif  //!__QUEUE__H__
```


