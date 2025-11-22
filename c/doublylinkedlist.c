#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
  struct node *prev;
  int data;
  struct node *next;
};

typedef struct node node;

node *head = NULL;

void printll(node *head) {
  if (head == NULL)
    return;
  node *ptr = head;
  while (ptr != NULL) {
    printf("%d\t", ptr->data);
    ptr = ptr->next;
  }
  printf("\n");
}

void printllCircular(node *head) {
  if (head == NULL)
    return;
  node *ptr = head;
  do {
    printf("%d\t", ptr->data);
    ptr = ptr->next;
  } while (ptr != head);
  printf("\n");
}

void insertAtBegin(node **head, int data) {
  node *temp = (node *)malloc(sizeof(node));
  temp->prev = NULL;
  temp->data = data;
  if (*head == NULL) {
    temp->next = NULL;
    *head = temp;
  } else {
    temp->next = *head;
    *head = temp;
  }
}

void insertAtEnd(node **head, int data) {
  node *temp = (node *)malloc(sizeof(node));
  temp->prev = NULL;
  temp->data = data;
  if (*head == NULL) {
    temp->next = NULL;
    *head = temp;
  } else {
    node *ptr = *head;
    while (ptr->next != NULL) {
      ptr = ptr->next;
    }
    temp->prev = ptr;
    temp->next = NULL;
    ptr->next = temp;
    (*head)->prev = temp;
  }
}

void insertAtBeginCircular(node **head, int data) {
  node *temp = (node *)malloc(sizeof(node));
  temp->data = data;
  if (*head == NULL) {
    temp->next = temp;
    temp->prev = temp;
    *head = temp;
  } else if ((*head)->next == *head) {
    temp->next = *head;
    temp->prev = *head;
    (*head)->next = temp;
    (*head)->prev = temp;
    *head = temp;
  } else {
    node *ptr = (*head)->prev;
    temp->next = ptr->next;
    temp->prev = ptr;
    ptr->next = temp;
    *head = temp;
  }
}

void insertAtEndCircular(node **head, int data) {
  node *temp = (node *)malloc(sizeof(node));
  temp->data = data;
  if (*head == NULL) {
    temp->next = temp;
    temp->prev = temp;
    *head = temp;
  } else if ((*head)->next == *head) {
    temp->next = *head;
    temp->prev = *head;
    (*head)->next = temp;
    (*head)->prev = temp;
  } else {
    node *ptr = (*head)->prev;
    while (ptr->next != *head) {
      ptr = ptr->next;
    }
    temp->next = ptr->next;
    temp->prev = ptr;
    ptr->next = temp;
    (*head)->prev = temp;
  }
}

void deleteAtEnd(node **headd) {
  node *head = *headd;
  if (head == NULL)
    exit(1);
  else {
    if (head->next == NULL) {
      free(head);
      *headd = NULL;
    } else {
      node *p, *q = head;
      while (q->next != NULL) {
        p = q;
        q = q->next;
      }
      p->next = NULL;
      q->prev = NULL;
      free(q);
      p = NULL;
      q = NULL;
    }
  }
}

void deleteAtBegin(node **headd) {
  node *head = *headd;
  if (head == NULL)
    exit(1);
  else {
    if (head->next == NULL) {
      free(head);
      *headd = NULL;
    } else {
      node *temp = head->next;
      free(*headd);
      *headd = temp;
    }
  }
}

void deleteAtBeginCircular(node **head) {
  if (*head == NULL)
    exit(1);
  else {
    if ((*head)->next == (*head)) {
      free(*head);
      *head = NULL;
    } else {
      node *p = (*head)->prev;
      p->next = (*head)->next;
      free(*head);
      *head = p->next;
      (*head)->prev = p;
    }
  }
}

void deleteAtEndCircular(node **head) {
  if (*head == NULL)
    exit(1);
  else {
    if ((*head)->next == (*head)) {
      free(*head);
      *head = NULL;
    } else {
      node *p = (*head)->prev;
      p->prev->next = (*head);
      (*head)->prev = p->prev;
      free(p);
    }
  }
}

int main() {
  //  printll(head);
  //  insertAtBegin(&head, 10);
  //  printll(head);
  //  insertAtBegin(&head, 20);
  //  printll(head);
  //  insertAtEnd(&head, 10);
  //  printll(head);
  //  insertAtEnd(&head, 20);
  //  printll(head);
  //  deleteAtEnd(&head);
  //  printll(head);
  //  deleteAtEnd(&head);
  //  printll(head);
  //  deleteAtBegin(&head);
  //  printll(head);
  //  deleteAtBegin(&head);
  //  printll(head);
  printllCircular(head);
  insertAtBeginCircular(&head, 10);
  printllCircular(head);
  insertAtBeginCircular(&head, 20);
  printllCircular(head);
  insertAtBeginCircular(&head, 30);
  printllCircular(head);
  insertAtBeginCircular(&head, 40);
  printllCircular(head);
  insertAtEndCircular(&head, 10);
  printllCircular(head);
  insertAtEndCircular(&head, 20);
  printllCircular(head);
  insertAtEndCircular(&head, 30);
  printllCircular(head);
  insertAtEndCircular(&head, 40);
  printllCircular(head);
  deleteAtBeginCircular(&head);
  printllCircular(head);
  deleteAtBeginCircular(&head);
  printllCircular(head);
  deleteAtBeginCircular(&head);
  printllCircular(head);
  deleteAtEndCircular(&head);
  printllCircular(head);
  deleteAtEndCircular(&head);
  printllCircular(head);
  deleteAtEndCircular(&head);
  printllCircular(head);
  deleteAtBeginCircular(&head);
  deleteAtEndCircular(&head);
  printll(head);
  deleteAtEndCircular(&head);
  return 0;
}
