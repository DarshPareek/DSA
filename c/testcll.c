#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
  int data;
  struct node *next;
};

typedef struct node node;

node *head = NULL; // Initialize head to NULL

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

int length(node *head) {
  if (head == NULL)
    return 0;
  node *temp = head;
  int l = 1;
  while (temp->next != head) {
    temp = temp->next;
    l++;
  }
  return l;
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

void freeList(node *head) {
  if (head == NULL)
    return;
  node *temp = head;
  node *nextNode;
  do {
    nextNode = temp->next;
    free(temp);
    temp = nextNode;
  } while (temp != head);
}

int main() {
  printll(head);
  printf("Length: %d\n", length(head));
  insertAtBegin(&head, 10);
  printll(head);
  printf("%d\n", head->data);
  printf("Length: %d\n", length(head));
  insertAtBegin(&head, 20);
  printll(head);
  printf("Length: %d\n", length(head));

  // Free the allocated memory
  freeList(head);
  return 0;
}
