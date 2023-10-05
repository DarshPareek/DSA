class Node:
    def __init__(self, data, next=None):
        self.data = data
        self.next = next


class Stack:
    def __init__(self):
        self.first = None
        self.last = None
        self.size = 0

    def push(self, data):
        data = Node(data)
        if self.size == 0:
            self.first = data
            self.first.next = self.last
            self.last = data
        else:
            temp = self.first
            self.first = data
            self.first.next = temp
        self.size += 1
        return self.size

    def pop(self):
        if self.size == 0:
            return None
        temp = self.first
        self.first = self.first.next
        self.size -= 1
        temp.next = None
        return temp.data


stack = Stack()
stack.push(10)
stack.push(100)
stack.push(1000)
removed = stack.pop()
print(removed)  # 1000
print(stack.size)  # 2
stack.pop()
stack.pop()
print(stack.size)  # 0stack = Stack()
stack = Stack()
stack.push(10)
stack.push(100)
stack.push(1000)
removed = stack.pop()
print(removed)  # 1000
print(stack.size)  # 2
stack.pop()
stack.pop()
print(stack.size)  # 0stack.push(10)  # 1
stack = Stack()
stack.push(10)
stack.push(100)
stack.push(1000)
removed = stack.pop()
print(removed)  # 1000
print(stack.size)  # 2
stack.pop()
stack.pop()
print(stack.size)  # 0stack.first.data  # 10
stack = Stack()
stack.push(10)
stack.push(100)
stack.push(1000)
removed = stack.pop()
print(removed)  # 1000
print(stack.size)  # 2
stack.pop()
stack.pop()
print(stack.size)  # 0stack.last.data  # 10
stack = Stack()
stack.push(10)
stack.push(100)
stack.push(1000)
removed = stack.pop()
print(removed)  # 1000
print(stack.size)  # 2
stack.pop()
stack.pop()
print(stack.size)  # 0stack.push(100)  # 2
stack = Stack()
stack.push(10)
stack.push(100)
stack.push(1000)
removed = stack.pop()
print(removed)  # 1000
print(stack.size)  # 2
stack.pop()
stack.pop()
print(stack.size)  # 0stack.first.data  # 100
stack = Stack()
stack.push(10)
stack.push(100)
stack.push(1000)
removed = stack.pop()
print(removed)  # 1000
print(stack.size)  # 2
stack.pop()
stack.pop()
print(stack.size)  # 0stack.last.data  # 10
stack = Stack()
stack.push(10)
stack.push(100)
stack.push(1000)
removed = stack.pop()
print(removed)  # 1000
print(stack.size)  # 2
stack.pop()
stack.pop()
print(stack.size)  # 0stack.push(1000)  # 3
stack = Stack()
stack.push(10)
stack.push(100)
stack.push(1000)
removed = stack.pop()
print(removed)  # 1000
print(stack.size)  # 2
stack.pop()
stack.pop()
print(stack.size)  # 0stack.first.data  # 1000
stack = Stack()
stack.push(10)
stack.push(100)
stack.push(1000)
removed = stack.pop()
print(removed)  # 1000
print(stack.size)  # 2
stack.pop()
stack.pop()
print(stack.size)  # 0stack.last.data  # 10
stack = Stack()
stack.push(10)
stack.push(100)
stack.push(1000)
removed = stack.pop()
print(removed)  # 1000
print(stack.size)  # 2
stack.pop()
stack.pop()
print(stack.size)  # 0
