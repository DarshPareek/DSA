#ifndef LINKED_LIST
#define LINKED_LIST

#include <iostream>
#include <ostream>
#include <vector>
template <typename T> class LinkedList;
template <typename T> class SimpleNode {
private:
  friend class LinkedList<T>;

public:
  T data;
  SimpleNode<T> *next;
  SimpleNode(const T &value) {
    data = value;
    next = nullptr;
  }
};
template <typename T> class LinkedList {
private:
  SimpleNode<T> *head;

public:
  LinkedList();
  ~LinkedList();
  void insertAtHead(const T &value);
  void vectorToLinkedList(std::vector<T> vec);
  SimpleNode<T> *middle_node();
  void print();
  LinkedList(const LinkedList &) = delete;
  LinkedList &operator=(const LinkedList &) = delete;
};

template <typename T> LinkedList<T>::LinkedList() : head(nullptr) {}
template <typename T> LinkedList<T>::~LinkedList() {
  SimpleNode<T> *current = head;
  while (current != nullptr) {
    SimpleNode<T> *next_node = current->next;
    delete current;
    current = next_node;
  }
  head = nullptr; // std::cout << "List Deleted" << std::endl;
}

template <typename T> void LinkedList<T>::insertAtHead(const T &value) {
  SimpleNode<T> *new_node = new SimpleNode<T>(value);
  new_node->next = head;
  head = new_node;
}

template <typename T>
void LinkedList<T>::vectorToLinkedList(std::vector<T> vec) {
  int n = vec.size();
  insertAtHead(vec[0]);
  SimpleNode<T> *current = head;
  for (int i = 1; i < n; i++) {
    SimpleNode<T> *next_node = new SimpleNode<T>(vec[i]);
    current->next = next_node;
    current = next_node;
  }
  current->next = nullptr;
}

template <typename T> SimpleNode<T> *LinkedList<T>::middle_node() {
  SimpleNode<T> *fast = head;
  SimpleNode<T> *slow = head;
  while (fast != nullptr && fast->next != nullptr) {
    fast = fast->next;
    if (fast->next != nullptr && fast != nullptr) {
      fast = fast->next;

    } else {
      break;
    }
    slow = slow->next;
  }
  return slow;
}

template <typename T> void LinkedList<T>::print() {
  SimpleNode<T> *current = head;
  std::cout << "[ ";
  while (current != nullptr) {
    std::cout << current->data;
    if (current->next != nullptr) {
      std::cout << " -> ";
    }
    current = current->next;
  }
  std::cout << " ]" << std::endl;
}

template class LinkedList<int>;

#endif
