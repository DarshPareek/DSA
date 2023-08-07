#   Created by Elshad Karimov
#   Copyright © AppMillers. All rights reserved.

# Singly Linked List

class Node:
    def __init__(self, val):
        self.val = val
        self.next = None


class SinglyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None
        self.length = 0

    def push(self, data):
        node = Node(data)
        if self.head == None:
            self.head = node
        else:
            self.tail.next = node
        self.tail = node
        self.length += 1
        return "Success"

    def insert(self, index, data):
        if not self.head and index != 0:
            return False
        else:
            if index == 0:
                node = Node(data)
                node.next = self.head
                self.head = node
                self.length += 1
                return True
            if self.length+1 < index:
                return False
            if index == self.length - 1:
                self.push(data)
                return True
            c = 0
            prev = None
            root = self.head
            while c != index:
                prev = root
                root = root.next
                c += 1
            node = Node(data)
            prev.next = node
            prev.next.next = root
            return True


singlyLinkedList = SinglyLinkedList()
singlyLinkedList.push(5)  # Success
singlyLinkedList.push(10)  # Success
singlyLinkedList.push(15)  # Success
singlyLinkedList.push(20)  # Success
singlyLinkedList.insert(2, 12)  # True
singlyLinkedList.insert(100, 12)  # False
singlyLinkedList.length         # 5
singlyLinkedList.head.val       # 5
singlyLinkedList.head.next.val   # 10
singlyLinkedList.head.next.next.val
singlyLinkedList.head.next.next.next.val
singlyLinkedList.head.next.next.next.next.val
print(singlyLinkedList.insert(5, 25))  # True
singlyLinkedList.head.next.next.next.next.next.val
