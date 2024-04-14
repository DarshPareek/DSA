class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


class BST:
    def __init__(self):
        self.root = None

    def insert(self, data):
        if self.root == None:
            self.root = Node(data)
        else:
            node = self.root
            while True:
                if data < node.data:
                    if node.left is None:
                        node.left = Node(data)
                        return self
                    else:
                        node = node.left
                if data > node.data:
                    if node.right is None:
                        node.right = Node(data)
                        return self
                    else:
                        node = node.right

    def find(self, data):
        if self.root == None:
            None
        else:
            node = self.root
            while node != None:
                # print(node.data)
                if data == node.data:
                    return node
                if data < node.data:
                    if node.data == data:
                        return node
                    else:
                        node = node.left
                elif data > node.data:
                    if node.data == data:
                        return node
                    else:
                        node = node.right
            return None

    def depthFirstSearchPreOrder(self, parameters=None):
        if not self.root:
            return None
        else:
            node = self.root

            def preOrder(node):
                if not node:
                    return None
                print(node.data)
                preOrder(node.left)
                preOrder(node.right)

            preOrder(node)

    def depthFirstSearchInOrder(self, rootNode, data=[]):
        if rootNode == None:
            return None
        else:
            self.depthFirstSearchInOrder(rootNode.left, data)
            data.append(rootNode.data)
            self.depthFirstSearchInOrder(rootNode.right, data)
            return data

    def depthFirstSearchPostOrder(self, rootNode, data=[]):
        if rootNode == None:
            return None
        else:
            self.depthFirstSearchPostOrder(rootNode.left, data)
            self.depthFirstSearchPostOrder(rootNode.right, data)
            data.append(rootNode.data)
            return data

    def minValue(self, node):
        current = node

        # loop down to find the leftmost leaf
        while current is not None:
            if current.left is None:
                break
            current = current.left

        return current

    def removeNode(self, nodeValue, node=None):
        if self.root is None:
            return None
        if node is None:
            node = self.root
        if nodeValue < node.data:
            node.left = self.removeNode(nodeValue, node.left)
        elif nodeValue > node.data:
            node.right = self.removeNode(nodeValue, node.right)
        else:
            if node.left is None:
                temp = node.right
                node = None
                return temp

            if node.right is None:
                temp = node.left
                node = None
                return temp

            temp = self.minValue(node.right)
            node.data = temp.data
            node.right = self.removeNode(temp.data, node.rightChild)
        return node

    def max_depth(self, node):
        if node is None:
            return 0

        else:

            # Compute the depth of each subtree
            lDepth = self.max_depth(node.left)
            rDepth = self.max_depth(node.right)

            # Use the larger one
            if (lDepth > rDepth):
                return lDepth+1
            else:
                return rDepth+1

    def isBalanced(self):
        if self.root is None:
            return None
        else:
            rootNode = self.root
            l_depth = self.max_depth(rootNode.left)
            r_depth = self.max_depth(rootNode.right)

            res = l_depth - r_depth
            if res > 1:
                return False
            else:
                return True


# bsTree = BST()
# bsTree.insert(15)
# bsTree.insert(20)
# bsTree.insert(10)
# bsTree.insert(12)
# # print(bsTree.root.data)  # 15
# # print(bsTree.root.right.data)  # 20
# # print(bsTree.root.left.right.data)  # 12}
# # print(bsTree.find(20).data)  # 20
# # print(bsTree.find(20).right)  # None
# # print(bsTree.find(20).left)  # None
# # print(bsTree.find(100))  # None
# bsTree = BST()
# bsTree.insert(15)
# bsTree.insert(20)
# bsTree.insert(10)
# bsTree.insert(12)
# bsTree.depthFirstSearchPreOrder()
# bsTree = BST()
# bsTree.insert(15)
# bsTree.insert(20)
# bsTree.insert(10)
# bsTree.insert(12)
# print(bsTree.depthFirstSearchInOrder(bsTree.root))  # [10, 12, 15, 20]
# bsTree = BST()
# bsTree.insert(15)
# bsTree.insert(20)
# bsTree.insert(10)
# bsTree.insert(12)
# print(bsTree.depthFirstSearchInOrder(bsTree.root))
# bsTree.removeNode(12)
# print(bsTree.depthFirstSearchInOrder(bsTree.root, []))
# print(bsTree.root.right.data)  # 20
# print(bsTree.root.left.data)  # 10
# print(bsTree.root.left.right.data)  # None
bsTree = BST()
bsTree.insert(15)
bsTree.insert(20)
bsTree.insert(10)
bsTree.insert(12)
print(bsTree.isBalanced())  # True
