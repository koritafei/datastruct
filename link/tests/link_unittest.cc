#include <iostream>

#include "../linklist/linklist.h"

int main(int argc, char **argv) {
  IntSLList list;
  list.addTail(1);
  list.addTail(2);
  list.addTail(3);
  list.print();
  list.addHead(4);
  list.print();
  list.deleteFromTail();
  list.print();
  list.deleteFromHead();
  list.print();

  list.deleteNode(2);
  list.print();
  std::cout << list.isInList(1) << std::endl;
  std::cout << list.isEmpty() << std::endl;
}
