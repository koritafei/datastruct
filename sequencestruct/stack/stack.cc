#include "stack/stack.hpp"

int main(int argc, char **argv) {
  Stack<int> s;
  s.push(1);
  s.push(2);
  std::cout << s.top() << std::endl;
}
