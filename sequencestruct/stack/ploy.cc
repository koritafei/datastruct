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
   int len = source.length();
    std::string   res;
    std::string   number;
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
    size_t      len = source.length();
    std::string result;
    std::string number;
    for (size_t i = 0; i < len; i++) {
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
