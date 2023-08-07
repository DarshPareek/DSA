#   Created by Elshad Karimov
#   Copyright © AppMillers. All rights reserved.

# List of Depth
class LinkedList:
    def __init__(self, val):
        self.val = val
        self.next = None

    def add(self, val):
        if self.next == None:
            self.next = LinkedList(val)
        else:
            self.next.add(val)

    def __str__(self):
        return "({val})".format(val=self.val) + str(self.next)


class BinaryTree:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None


def depth(tree):
    if tree is None:
        return 0
 
    else:
 
        # Compute the depth of each subtree
        lDepth = depth(tree.left)
        rDepth = depth(tree.right)
 
        # Use the larger one
        if (lDepth > rDepth):
            return lDepth+1
        else:
            return rDepth+1



def treeToLinkedList(tree, custDict={}, d=None):
    pass


root = BinaryTree(1)
root.left = BinaryTree(2)
root.right = BinaryTree(3)
root.left.left = BinaryTree(4)
root.left.right = BinaryTree(5)
print(depth(root))