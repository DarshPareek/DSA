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
public:
  SimpleNode<T> *head;
  LinkedList();
  ~LinkedList();
  void insertAtHead(const T &value);
  void vectorToLinkedList(std::vector<T> vec);
  SimpleNode<T> *middle_node(SimpleNode<T> *head);
  void swap(SimpleNode<T> *p1, SimpleNode<T> *p2);
  SimpleNode<T> *Merge(SimpleNode<T> *head, SimpleNode<T> *head2);
  SimpleNode<T> *MergeSort(SimpleNode<T> *head);
  SimpleNode<T> *Partition(SimpleNode<T> *head);
  SimpleNode<T> *QuickSort(SimpleNode<T> *head);
  void print();
  void print(SimpleNode<T> *head);
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

template <typename T>
SimpleNode<T> *LinkedList<T>::middle_node(SimpleNode<T> *head) {
  SimpleNode<T> *fast = head->next;
  SimpleNode<T> *slow = head;
  while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}

template <typename T>
void LinkedList<T>::swap(SimpleNode<T> *p1, SimpleNode<T> *p2) {
  T temp = p2->data;
  p2->data = p1->data;
  p1->data = temp;
}

template <typename T>
SimpleNode<T> *LinkedList<T>::Merge(SimpleNode<T> *head1,
                                    SimpleNode<T> *head2) {
  if (head1 == nullptr)
    return head2;
  if (head2 == nullptr)
    return head1;
  SimpleNode<T> *new_head = nullptr;
  if (head1->data <= head2->data) {
    new_head = head1;
    head1 = head1->next;
  } else {
    new_head = head2;
    head2 = head2->next;
  }
  SimpleNode<T> *curr = new_head;
  while (head1 != nullptr && head2 != nullptr) {
    if (head1->data <= head2->data) {
      curr->next = head1;
      head1 = head1->next;
    } else {
      curr->next = head2;
      head2 = head2->next;
    }
    curr = curr->next;
  }
  if (head1 != nullptr) {
    curr->next = head1;
  } else if (head2 != nullptr) {
    curr->next = head2;
  }
  return new_head;
}

template <typename T>
SimpleNode<T> *LinkedList<T>::MergeSort(SimpleNode<T> *head) {
  if (head == nullptr || head->next == nullptr) {
    return head;
  }
  SimpleNode<T> *mid = middle_node(head);
  SimpleNode<T> *head2 = mid->next;
  mid->next = nullptr;
  SimpleNode<T> *newHead1 = MergeSort(head);
  SimpleNode<T> *newHead2 = MergeSort(head2);
  SimpleNode<T> *finalHead = Merge(newHead1, newHead2);
  print(finalHead);
  return finalHead;
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

template <typename T> void LinkedList<T>::print(SimpleNode<T> *head) {
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

template <typename T> class DoublyLinkedList;
template <typename T> class DoubleNode {
private:
  friend class DoublyLinkedList<T>;

public:
  T data;
  DoubleNode<T> *next;
  DoubleNode<T> *prev;
  DoubleNode(const T &value) {
    data = value;
    next = nullptr;
    prev = nullptr;
  }
};
template <typename T> class DoublyLinkedList {
private:
public:
  DoubleNode<T> *head;
  DoubleNode<T> *tail;
  int size;
  DoublyLinkedList();
  ~DoublyLinkedList();
  void insertAtHead(const T &value);
  void vectorToLinkedList(std::vector<T> vec);
  void swap(DoubleNode<T> *p1, DoubleNode<T> *p2);
  DoubleNode<T> *Partition(DoubleNode<T> *head, DoubleNode<T> *tail);
  DoubleNode<T> *PartitionNew(DoubleNode<T> *head, DoubleNode<T> *tail);
  DoubleNode<T> *QuickSort(DoubleNode<T> *head, DoubleNode<T> *tail);
  void print();
  void print(DoubleNode<T> *head, int rev = 0);
  DoublyLinkedList(const DoublyLinkedList &) = delete;
  DoublyLinkedList &operator=(const DoublyLinkedList &) = delete;
};
template <typename T> DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr) {
  size = 0;
}
template <typename T> DoublyLinkedList<T>::~DoublyLinkedList() {
  DoubleNode<T> *current = head;
  while (current != nullptr) {
    DoubleNode<T> *next_node = current->next;
    delete current;
    current = next_node;
  }
  head = nullptr; // std::cout << "List Deleted" << std::endl;
  size = 0;
}

template <typename T> void DoublyLinkedList<T>::insertAtHead(const T &value) {
  if (head == nullptr) {
    DoubleNode<T> *new_node = new DoubleNode<T>(value);
    new_node->next = head;
    new_node->prev = nullptr;
    head = new_node;
    tail = new_node;
  } else {
    DoubleNode<T> *new_node = new DoubleNode<T>(value);
    new_node->next = head;
    new_node->prev = nullptr;
    head = new_node;
  }
  size++;
}
template <typename T>
void DoublyLinkedList<T>::vectorToLinkedList(std::vector<T> vec) {
  int n = vec.size();
  insertAtHead(vec[0]);
  DoubleNode<T> *current = head;
  for (int i = 1; i < n; i++) {
    DoubleNode<T> *next_node = new DoubleNode<T>(vec[i]);
    current->next = next_node;
    next_node->prev = current;
    current = next_node;
  }
  current->next = nullptr;
  tail = current;
  size = n;
}
template <typename T>
void DoublyLinkedList<T>::swap(DoubleNode<T> *p1, DoubleNode<T> *p2) {
  T temp = p2->data;
  p2->data = p1->data;
  p1->data = temp;
}
template <typename T>
void DoublyLinkedList<T>::print(DoubleNode<T> *head, int rev) {
  if (rev == 0) {
    DoubleNode<T> *current = head;
    std::cout << "[ ";
    while (current != nullptr) {
      std::cout << current->data;
      if (current->next != nullptr) {
        std::cout << " -> ";
      }
      current = current->next;
    }
    std::cout << " ]" << std::endl;
  } else {
    DoubleNode<T> *current = tail;
    std::cout << "[ ";
    while (current != nullptr) {
      std::cout << current->data;
      if (current->prev != nullptr) {
        std::cout << " <- ";
      }
      current = current->prev;
    }
    std::cout << " ]" << std::endl;
  }
}
template <typename T>
DoubleNode<T> *DoublyLinkedList<T>::QuickSort(DoubleNode<T> *l,
                                              DoubleNode<T> *h) {
  if (h != nullptr && l != h && l != h->next) {
    // Partition the list and get the pivot node
    DoubleNode<T> *p = Partition(l, h);

    // Recurse on the left side (from l to p->prev)
    if (p != nullptr && p->prev != nullptr) {
      QuickSort(l, p->prev);
    }

    // Recurse on the right side (from p->next to h)
    if (p != nullptr && p->next != nullptr) {
      QuickSort(p->next, h);
    }
  }
  return head;
}
template <typename T>
DoubleNode<T> *DoublyLinkedList<T>::Partition(DoubleNode<T> *l,
                                              DoubleNode<T> *h) {
  T pivot = h->data;
  DoubleNode<T> *i = l->prev;
  for (DoubleNode<T> *j = l; j != h; j = j->next) {
    if (j->data <= pivot) {
      if (i == nullptr) {
        i = l;
      } else {
        i = i->next;
      }
      swap(i, j);
    }
  }
  if (i == nullptr) {
    i = l;
  } else {
    i = i->next;
  }
  swap(i, h);
  return i;
}
template class DoublyLinkedList<int>;

#endif
