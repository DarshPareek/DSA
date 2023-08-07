#   Created by Elshad Karimov
#   Copyright © AppMillers. All rights reserved.

# Singly Linked List
def printll(head):
    while head:
        print(head.val)
        head = head.next


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

    def rotate(self, number):
        if number < 0:
            lt = self.length + number
        else:
            lt = number
        print("lt = ", lt,self.length)
        prev = None
        root = self.head
        self.tail.next = self.head
        c = 0
        while c != lt:
            prev = root
            root = root.next
            c += 1
        self.head = root
        self.tail = prev
        self.tail.next = None


singlyLinkedList = SinglyLinkedList()
singlyLinkedList.push(5)  # Success
singlyLinkedList.push(10)  # Success
singlyLinkedList.push(15)  # Success
singlyLinkedList.push(20)  # Success
singlyLinkedList.push(25)  # Success
printll(singlyLinkedList.head)
print("######")
singlyLinkedList.rotate(-1)
printll(singlyLinkedList.head)
print(singlyLinkedList.head.val, singlyLinkedList.tail.val,
      singlyLinkedList.tail.next)
