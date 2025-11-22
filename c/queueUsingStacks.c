#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
int S1[5];
int S2[5];
int T1 = -1;
int T2 = -1;
int SL1 = 5;
int SL2 = 5;

void enqueue(int *S1, int *T1, int SL1, int x) {
  if (isFull(SL1, *T1))
    exit(1);
  push(x, SL1, *T1, S1);
  (*T1)++;
}

int dequeue(int *S1, int *S2, int *T1, int *T2, int SL1, int SL2) {
  if (isEmpty(SL2, *T2)) {
    return pop(SL2, T2, S2);
  } else {
    while (isEmpty(SL1, *T1)) {
      push(pop(SL1, T1, S1), SL2, *T2, S2);
    }
    return pop(SL2, T2, S2);
  }
}

int main() {
  printStack(S1, T1);
  printStack(S2, T2);
  enqueue(S1, &T1, SL1, 5);
  enqueue(S1, &T1, SL1, 6);
  enqueue(S1, &T1, SL1, 7);
  enqueue(S1, &T1, SL1, 8);
  printStack(S1, T1);
  printStack(S2, T2);
  printf("%d\n", dequeue(S1, S2, &T1, &T2, SL1, SL2));
  enqueue(S1, &T1, SL1, 9);
  printStack(S1, T1);
  printStack(S2, T2);
  printf("%d\n", dequeue(S1, S2, &T1, &T2, SL1, SL2));
  return 0;
}
