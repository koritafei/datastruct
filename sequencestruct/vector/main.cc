#include "vector/vector.hpp"

int main(int argc, char **argv) {
  Vector<int> v;
  v.push_back(1);
  v.push_back(2);
  std::cout << v.size() << std::endl;
  std::cout << v[0] << "\t" << v[1] << std::endl;
}
