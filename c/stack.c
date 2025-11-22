#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
int stack[5];
int stack_len = 5;
int top = -1;

int arr_of_stacks[9];
int len_of_arr = 9;
int number_of_stack = 3;
int init0 = -1;
int init1 = 2;
int init2 = 5;
int p1 = -1;
int p2 = 2;
int p3 = 5;

struct node {
  int data;
  struct node *next;
};

typedef struct node node;

node *head = NULL;

int isFull(int stack_len, int top) {
  if (top == stack_len - 1)
    return 1;
  return 0;
}

int isEmpty(int stack_len, int top) {
  if (top == -1)
    return 1;
  return 0;
}

void push(int x, int stack_len, int top, int *stack) {
  if (isFull(stack_len, top))
    exit(1);
  top++;
  stack[top] = x;
}

int pop(int stack_len, int *top, int *stack) {
  if (isEmpty(stack_len, *top))
    return 0;
  int temp = stack[*top];
  (*top)--;
  return temp;
}

void printStack(int *stack, int top) {
  int l = top;
  while (l != -1) {
    printf("%d\t", stack[l]);
    l--;
  }
  printf("\n");
}

void printArrOfStack() {
  int i;
  for (i = 0; i < len_of_arr; i++) {

    printf("%d\t", arr_of_stacks[i]);
    if ((i + 1) % number_of_stack == 0)
      printf("|");
  }
  printf("\n");
}

void push_toaos(int *p, int i, int x, int top) {
  if (*p == top)
    exit(1);
  (*p)++;
  arr_of_stacks[*p] = x;
}

int pop_toaos(int *p, int i, int top) {
  if (*p == top)
    exit(1);
  int temp = arr_of_stacks[*p];
  (*p)--;
  return temp;
}

void pushll(node **head, int data) {
  node *temp = (node *)malloc(sizeof(node));
  if (temp == NULL)
    exit(1);
  temp->data = data;
  temp->next = NULL;
  if (*head == NULL)
    *head = temp;
  else {
    temp->next = *head;
    *head = temp;
  }
}

int popll(node **head) {
  if (*head == NULL)
    exit(1);
  node *temp = *head;
  (*head) = temp->next;
  int val = temp->data;
  free(temp);
  return val;
}

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

// int main() {
// //   printStack();
// //   push(5);
// //   printStack();
// //   push(7);
// //   printStack();
// //   printf("%d\n", pop());
// //   printStack();
// //  printArrOfStack();
// //  push_toaos(&p2, 1, 10, init2);
// //  printArrOfStack();
// //  push_toaos(&p2, 1, 30, init2);
// //  printArrOfStack();
// //  pop_toaos(&p2, 1, init1);
// //  printArrOfStack();
// //  push_toaos(&p1, 0, 10, init1);
// //  printArrOfStack();
// //  push_toaos(&p3, 2, 30, len_of_arr);
// //  printArrOfStack();
// //  pop_toaos(&p2, 1, init1);
// //  printArrOfStack();
// printll(head);
// pushll(&head, 10);
// printll(head);
// pushll(&head, 20);
// printll(head);
// pushll(&head, 30);
// printll(head);
// popll(&head);
// printll(head);
// return 0;
// }
