class Node:
    def __init__(self, value):
        self.value = value
        self.next = None


class Queue:
    def __init__(
        self,
    ):
        self.first = None
        self.last = None
        self.size = 0

    def enqueue(self, data):
        node = Node(data)
        if self.first == None:
            self.first = node
            self.last = node
        else:
            self.last.next = node
            self.last = node
        self.size += 1
        return self.size

    def dequeue(self):
        if self.first == None:
            return None
        temp = self.first
        if self.first == self.last:
            self.last = None
        self.first = self.first.next
        self.size -= 1
        return temp.value


class Stack:
    def __init__(self):
        self.q1 = Queue()
        self.q2 = Queue()

    def push(self, data):
        self.q2.enqueue(data)
        while self.q1.size != 0:
            #print("Worked")
            self.q2.enqueue(self.q1.dequeue())
        self.q1, self.q2 = self.q2, self.q1
        return self

    def pop(self):
        return self.q1.dequeue()


stack = Stack()
stack.push(10).push(20).push(30)
print(stack.pop())  # 30
print(stack.pop())  # 20
print(stack.pop())  # 10
print(stack.pop())  # None
stack.push(30).push(40).push(50)
print(stack.pop())  # 50
stack.push(60)
print(stack.pop())  # 60
