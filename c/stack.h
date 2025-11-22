#ifndef STACK_H_
#define STACK_H_
int isEmpty(int stack_len, int top);
int isFull(int stack_len, int top);
void printStack(int *stack, int top);
void push(int x, int stack_len, int top, int *stack);
int pop(int stack_len, int *top, int *stack);
#endif
