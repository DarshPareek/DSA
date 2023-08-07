#   Created by Elshad Karimov
#   Copyright © AppMillers. All rights reserved.

# Validate BST

class Node:
    def __init__(self, key):
        self.data = key
        self.left = None
        self.right = None


def insert(node, data):
    if node is None:
        return Node(data)
    else:
        if data <= node.data:
            temp = insert(node.left, data)
            node.left = temp
            temp.parent = node
        else:
            temp = insert(node.right, data)
            node.right = temp
            temp.parent = node
        return node


def helper(root, data=[]):
    if not root:
        return
    helper(root.left)
    data.append(root)
    helper(root.right)
    return data


def inOrderSuccessor(root, n):
    d = helper(root)
    for i in range(len(d)):
        if i == len(d)-1:
            return None
        if d[i].data == n:
            return d[i+1]


root = Node(4)
root.left = Node(2)
root.left.left = Node(1)
root.left.right = Node(3)
root.right = Node(8)
root.right.left = Node(5)
root.right.right = Node(9)
print(inOrderSuccessor(root,9))