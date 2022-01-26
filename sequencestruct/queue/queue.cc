#include "queue.h"

int main(int argc, char **argv) {
  std::cout << "Hello, Queue" << std::endl;
  Queue<int> q;
  q.push_front(12);
  std::cout << q.front() << "\t" << q.back() << std::endl;
  q.push_back(23);
  std::cout << q.front() << "\t" << q.back() << std::endl;
  q.push_front(34);
  std::cout << q.front() << "\t" << q.back() << std::endl;
  q.pop_front();
  std::cout << q.front() << "\t" << q.back() << std::endl;
  q.pop_back();
  std::cout << q.front() << "\t" << q.back() << std::endl;
}