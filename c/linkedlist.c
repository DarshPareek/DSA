#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
  int data;
  struct node *next;
};

typedef struct node node;

int length(node *head) {
  node *ptr = head;
  int l = 1;
  while (ptr->next != NULL) {
    l++;
    ptr = ptr->next;
  }
  return l;
}

void middle(node *head) {
  if (head->next == NULL) {
    printf("Linked List is Empty\n");
    exit(1);
  }
  node *slow_ptr = head;
  node *fast_ptr = head;
  while (fast_ptr->next != NULL) {
    fast_ptr = fast_ptr->next;
    if (fast_ptr->next != NULL)
      fast_ptr = fast_ptr->next;
    slow_ptr = slow_ptr->next;
  }
  printf("%d\n", slow_ptr->data);
}

void deleteAtEnd(node *head) {
  if (head->next == NULL) {
    printf("Linked List is Empty\n");
    exit(1);
  }
  node *ptr = head;
  while (ptr->next->next != NULL) {
    ptr = ptr->next;
  }
  node *temp = ptr->next;
  ptr->next = NULL;
  free(temp);
}

void deleteAtBegin(node *head) {
  if (head->next == NULL) {
    printf("Linked List is Empty\n");
    exit(1);
  }
  node *temp = head->next;
  head->next = head->next->next;
  free(temp);
}

void deleteAtPos(node *head, int pos) {
  int len = length(head);
  if (pos == 0)
    deleteAtBegin(head);
  else if (pos >= len)
    exit(1);
  else if (pos + 1 == len)
    deleteAtEnd(head);
  else {
    node *p = head;
    node *q = NULL;
    int i = 0;
    for (i = 0; i != pos; i++) {
      q = p;
      p = p->next;
    }
    q->next = p->next;
    free(p);
  }
}

void insertAtPos(node *head, int pos, int data) {
  if (pos == 0) {
    if (head->next == NULL) {
      node *temp = (node *)malloc(sizeof(node));
      temp->data = data;
      temp->next = NULL;
      head->next = temp;
    }
  } else if (pos < length(head)) {
    int p = 0;
    node *ptr = head;
    node *prev = NULL;
    while (p != pos) {
      prev = ptr;
      ptr = ptr->next;
      p++;
    }
    if (ptr->next == NULL) {
      node *temp = (node *)malloc(sizeof(node));
      ptr->next = temp;
      temp->data = data;
      temp->next = NULL;
    } else {
      prev = prev->next;
      ptr = ptr->next;
      node *temp = (node *)malloc(sizeof(node));
      prev->next = temp;
      temp->data = data;
      temp->next = ptr;
    }
  }
}

node *reverse(node *head) {
  int len = length(head);
  if (head == NULL)
    exit(1);
  else if (len == 1)
    return head;
  else if (len == 2) {
    node *temp = head->next;
    node *temp2 = temp->next;
    *temp2->next = *temp;
    temp->next = NULL;
    head->next = temp2;
    return head;
  } else {
    node *p = NULL;
    node *q = NULL;
    node *r = head->next;
    while (r) { // r != NULL
      q = r->next;
      r->next = p;
      p = r;
      r = q;
    }
    head->next = p;
    return head;
  }
}

void findCycle(node *head) {
  node *slow = head, *fast = head;
  while (fast != NULL && fast->next != NULL && fast->next->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) {
      printf("Loop starts at %d", fast->data);
      printf("cycle exists\n");
      exit(1);
    }
  }
  printf("no cylce exists\n");
}

void findMergePoint(node *h1, node *h2) {
  int l1 = length(h1), l2 = length(h2);
  int i;
  node *p1 = h1, *p2 = h2;
  if (l1 > l2) {
    int diff = l1 - l2;
    for (i = 0; i < diff; i++) {
      p1 = p1->next;
    }
  } else if (l2 > l1) {
    int diff = l1 - l2;
    for (i = 0; i < diff; i++) {
      p1 = p1->next;
    }
  }
  while (p1->next != NULL && p2->next != NULL) {
    if (p1 == p2)
      printf("the lists merge at %d\n", p1->data);
    p1 = p1->next;
    p2 = p2->next;
  }
  printf("No merge point\n");
}

void printll(node *head) {
  node *ptr = head;
  while (ptr->next != NULL) {
    ptr = ptr->next;
    printf("%d\t", ptr->data);
  }
  printf("\n");
}

int main(void) {
  printf("Hello, World\n");
  node *head = (node *)malloc(sizeof(node));
  head->next = NULL;
  printll(head);
  insertAtPos(head, 0, 100);
  insertAtPos(head, 1, 200);
  insertAtPos(head, 2, 300);
  insertAtPos(head, 3, 400);
  insertAtPos(head, 3, 500);
  insertAtPos(head, 3, 600);
  insertAtPos(head, 2, 700);
  insertAtPos(head, 2, 800);
  insertAtPos(head, 2, 900);
  printll(head);
  deleteAtPos(head, 5);
  printll(head);
  deleteAtBegin(head);
  printll(head);
  deleteAtEnd(head);
  printll(head);
  head = reverse(head);
  printll(head);
  return 0;
}
