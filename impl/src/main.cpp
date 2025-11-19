#include "LinkedList.cpp"
#include <iostream>
#include <ostream>
#include <vector>
int main(int argc, char *argv[]) {
  LinkedList<int> l;
  std::cout << "Adding Data to linked list" << std::endl;
  l.insertAtHead(5);
  l.insertAtHead(6);
  l.insertAtHead(7);
  l.print();
  LinkedList<int> m;
  std::vector<int> v = {1, 2, 3, 4, 5, 6, 7};
  m.vectorToLinkedList(v);
  m.print();
  auto mid = m.middle_node();
  std::cout << mid->data << std::endl;
  return 0;
}
