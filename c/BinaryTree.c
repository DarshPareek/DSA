#include <stdio.h>
// #include <stdio.h>
// #include <stdlib.h>

struct BTnode {
  struct BTnode *left;
  int data;
  struct BTnode *right;
};

typedef struct BTnode node;

int NL(node *t, int *res) {
  if (t == NULL)
    return *res;
  if (t->left == NULL && t->right == NULL) {
    (*res)++;
    return *res;
  }
  return NL(t->left, res) + NL(t->right, res);
}
int numberOfLeafNodes(node *t) {
  int res = 0;
  NL(t, &res);
  return res;
}

int numberOfInternalNodes(node *t) {
  if (t == NULL)
    return 0;
  if (t->left == NULL && t->right == NULL)
    return 0;
  else if (t->left == NULL && t->right != NULL)
    return 1;
  else if (t->left != NULL && t->right == NULL)
    return 1;
  else if (t->left != NULL && t->right != NULL)
    return 1;
  return numberOfInternalNodes(t->left) + numberOfInternalNodes(t->right);
}

int numberOfNodes(node *t) {
  if (t == NULL)
    return 0;
  else if (t->left == NULL && t->right == NULL)
    return 1;
  return (1 + numberOfNodes(t->left) + numberOfNodes(t->right));
}

int heightOfTree(node *t) {
  if (t == NULL)
    return 0;
  else if (t->left == NULL && t->right == NULL)
    return 0;
  else {
    int hl = heightOfTree(t->left);
    int hr = heightOfTree(t->right);
    if (hl > hr)
      return 1 + hl;
    else
      return 1 + hr;
  }
}

int checkTreeEquality(node *t1, node *t2) {
  if (t1 == NULL && t2 == NULL)
    return 1;
  if ((t1 == NULL && t2 != NULL) || (t1 != NULL && t2 == NULL))
    return 0;
  if (t1->data == t2->data) {
    int res = checkTreeEquality(t1->left, t2->left) +
              checkTreeEquality(t1->right, t2->right);
    if (res == 2)
      return 1;
    else
      return 0;
  } else {
    return 0;
  }
}

int checkStrictBinaryTree(node *t) {
  if (t == NULL)
    return 1;
  else if (t->left == NULL && t->right == NULL)
    return 1;
  else {
    if (t->left != NULL && t->right != NULL)
      return (checkStrictBinaryTree(t->left) &&
              checkStrictBinaryTree(t->right));
    else
      return 0;
  }
}

int main() {
  node *t = NULL;
  node *t1 = NULL;
  node *t2 = NULL;
  printf("%d\n", numberOfLeafNodes(t));
  printf("%d\n", numberOfInternalNodes(t));
  node a = {NULL, 10, NULL};
  node b = {NULL, 20, NULL};
  node c = {NULL, 10, NULL};
  node d = {NULL, 20, NULL};
  // t = &a;
  // printf("%d\n", numberOfLeafNodes(t));
  // printf("%d\n", numberOfInternalNodes(t));
  // a.left = &b;
  // printf("%d\n", numberOfLeafNodes(t));
  // printf("%d\n", numberOfInternalNodes(t));
  // a.right = &c;
  // c.left = &d;
  // printf("%d\n", numberOfLeafNodes(t));
  // printf("%d\n", numberOfInternalNodes(t));
  // printf("%d\n", heightOfTree(t));
  // t1 = &a;
  // t2 = &c;
  // a.left = &b;
  // c.left = &d;
  // printf("%d\n", checkTreeEquality(t1, t2));
  t = &a;
  a.left = &b;
  a.right = &c;
  b.left = &d;
  printf("%d\n", checkStrictBinaryTree(t));
  return 0;
}
