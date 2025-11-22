#include <stdio.h>
#include <stdlib.h>

int queue[7];
int queue_len = 7;
int front = -1;
int rear = -1;

struct node {
  int data;
  struct node *next;
};

typedef struct node node;
node *frontll = NULL;
node *rearll = NULL;

void enqueue(int x) {
  if (rear == queue_len - 1)
    exit(1);
  else if (front == -1 && rear == -1) {
    front++;
    rear++;
    queue[rear] = x;
  } else {
    rear++;
    queue[rear] = x;
  }
}

int dequeue() {
  if (front > rear)
    exit(1);
  int temp = queue[front];
  front++;
  if (front == rear) {
    front = -1;
    rear = -1;
  }
  return temp;
}

void printQueue() {
  int i = 0;
  for (; i < queue_len; i++) {
    printf("%d\t", queue[i]);
  }
  printf("\n");
}

void enqueueCQ(int x) {
  if ((rear + 1) % queue_len == front)
    exit(1);
  else if (front == -1 && rear == -1) {
    front++;
    rear++;
    queue[rear] = x;
  } else {
    rear = (rear + 1) % queue_len;
    queue[rear] = x;
  }
}

int dequeueCQ() {
  if (front == -1)
    exit(1);
  int temp = queue[front];
  front = (front + 1) % queue_len;
  if (front == rear) {
    front = -1;
    rear = -1;
  }
  return temp;
}

void printQueueLL(node *front, node *rear) {
  node *ptr = front;
  while (ptr != rear) {
    printf("%d\t", ptr->data);
    ptr = ptr->next;
  }
  printf("\n");
}

void enqueueLL(node **front, node **rear, int x) {
  node *temp;
  temp = (node *)malloc(sizeof(node));
  if (temp == NULL)
    exit(1);
  temp->data = x;
  temp->next = NULL;
  if (*rear == NULL) {
    front = NULL;
    *rear = NULL;
  } else {
    (*rear)->next = temp;
    *rear = temp;
  }
  temp = NULL;
}

int dequeueLL(node **front, node **rear) {
  node *p = *front;
  if (*front == NULL)
    exit(1);
  int x = (*front)->data;
  if (*front == *rear) {
    front = NULL;
    rear = NULL;
  } else {
    *front = (*front)->next;
  }
  free(p);
  p = NULL;
  return x;
}

int main() {
  // enqueue(10);
  // printQueue();
  // enqueue(20);
  // printQueue();
  // dequeue();
  // printQueue();
  // dequeue();
  // printQueue();
  // dequeue();
  // printQueue();
  // enqueueCQ(10);
  // printQueue();
  // enqueueCQ(20);
  // printQueue();
  // enqueueCQ(30);
  // printQueue();
  // enqueueCQ(40);
  // printQueue();
  // enqueueCQ(20);
  // printQueue();
  // enqueueCQ(30);
  // printQueue();
  // enqueueCQ(40);
  // printQueue();
  // dequeueCQ();
  // dequeueCQ();
  // enqueueCQ(50);
  // printQueue();
  return 0;
}
