#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
  int data;
  struct node *next;
};

typedef struct node node;

node *head = NULL;
int length(node *head) {
  if (head == NULL)
    return 0;
  node *temp = head;
  if (temp->next == head)
    return 1;
  int l = 1;
  temp = temp->next;
  l += 1;
  while (temp != head) {
    temp = temp->next;
  }
  return l;
}

void insertAtBegin(node **head, int data) {
  node *temp = (node *)malloc(sizeof(node));
  temp->data = data;
  if (*head == NULL) {
    *head = temp;
    (*head)->next = *head;
  } else {
    node *ptr = *head;
    while (ptr->next != *head) {
      ptr = ptr->next;
    }
    ptr->next = temp;
    temp->next = *head;
    *head = temp;
  }
}

void insertAtEnd(node **head, int data) {
  node *temp = (node *)malloc(sizeof(node));
  temp->data = data;
  if (*head == NULL) {
    *head = temp;
    (*head)->next = *head;
  } else {
    node *ptr = *head;
    while (ptr->next != *head) {
      ptr = ptr->next;
    }
    ptr->next = temp;
    temp->next = *head;
  }
}

void deleteAtEnd(node **head) {
  node *h = *head;
  if (*head == NULL) {
    printf("Nothing to delete\n");
    exit(1);
  } else {
    int len = length(h);
    if (len == 1) {
      node *temp = *head;
      free(temp);
      *head = NULL;
      temp = NULL;
    } else {
      node *p, *q = h;
      while (q->next != h) {
        p = q;
        q = q->next;
      }
      p->next = h;
      free(q);
      q = NULL;
      p = NULL;
    }
  }
}

void deleteAtBegin(node **head) {
  node *h = *head;
  if (*head == NULL) {
    printf("Nothing to delete\n");
    exit(1);
  } else {
    int len = length(h);
    if (len == 1) {
      node *temp = *head;
      free(temp);
      *head = NULL;
      temp = NULL;
    } else {
      node *p = h;
      while (p->next != h) {
        p = p->next;
      }
      p->next = h->next;
      node *temp = *head;
      free(temp);
      *head = p->next;
      p = NULL;
      temp = NULL;
    }
  }
}

void printll(node *head) {
  if (head == NULL)
    return;
  node *ptr = head;
  do {
    printf("%d\t", ptr->data);
    ptr = ptr->next;
  } while (ptr != head);
  printf("\n");
}

int main() {
  insertAtBegin(&head, 10);
  printll(head);
  insertAtBegin(&head, 20);
  printll(head);
  insertAtEnd(&head, 20);
  printll(head);
  deleteAtEnd(&head);
  printll(head);
  deleteAtEnd(&head);
  printll(head);
  deleteAtEnd(&head);
  printll(head);
  insertAtBegin(&head, 10);
  printll(head);
  insertAtBegin(&head, 20);
  printll(head);
  insertAtEnd(&head, 20);
  printll(head);
  deleteAtBegin(&head);
  printll(head);
  deleteAtBegin(&head);
  printll(head);
  deleteAtBegin(&head);
  printll(head);

  return 0;
}
