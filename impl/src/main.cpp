#include "Algorithms.cpp"
#include "LinkedList.cpp"
#include <iostream>
#include <ostream>
#include <vector>
int main(int argc, char *argv[]) {
  // LinkedList<int> l;
  // std::cout << "Adding Data to linked list" << std::endl;
  // l.insertAtHead(5);
  // l.insertAtHead(6);
  // l.print();
  // auto mid = m.middle_node(m.head);
  // std::cout << mid->data << std::endl;
  // m.swap(mid, m.head);
  // m.print();
  // m.head = m.MergeSort(m.head);
  // m.print();
  // int arr[5] = {7, 3, 1, 5, 2};
  // print_array(arr, 5);
  // MergeSort(arr, 0, 5);
  // print_array(arr, 5);
  // LinkedList<int> m;
  // std::vector<int> v = {4, 2, 7, 4, 3, 6, 1};
  // m.vectorToLinkedList(v);
  // m.print();
  // m.head = m.MergeSort(m.head);
  DoublyLinkedList<int> m;
  m.vectorToLinkedList({7, 3, 1, 5, 2});
  m.print(m.head);
  m.print(m.head, 1);
  m.QuickSort(m.head, m.tail);
  m.print(m.head);
  return 0;
}
