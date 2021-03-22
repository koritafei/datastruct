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