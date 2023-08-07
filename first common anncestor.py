#   Created by Elshad Karimov
#   Copyright © AppMillers. All rights reserved.

# First Common Ancestor

class Node:
    def __init__(self, value, left=None, right=None):
        self.value = value
        self.right = right
        self.left = left


def inSubTree(root, n):
    if not root:
        return
    if root.value == n:
        return True
    d1 = inSubTree(root.left, n)
    d2 = inSubTree(root.right, n)
    return d1 or d2


def findFirstCommonAncestor(n1, n2, root):
    if not root:
        return
    if (inSubTree(root.left, n1) and inSubTree(root.right, n2)) or (inSubTree(root.right, n1) and inSubTree(root.left, n2)):
        return root
    d1 = findFirstCommonAncestor(n1, n2, root.right)
    d2 = findFirstCommonAncestor(n1, n2, root.left)
    return d1 or d2


node = Node(55)
node.right = Node(77)
node.left = Node(44)
node.left.left = Node(22)
node.left.left.left = Node(35)
node.left.right = Node(99)
node.left.right.left = Node(90)
node.left.right.left.right = Node(33)
node.left.right.right = Node(95)
node.left.left.right = Node(88)
node.left.left.right.left = Node(54)

print(findFirstCommonAncestor(88, 33, node).value)
# print(inSubTree(node,95))
