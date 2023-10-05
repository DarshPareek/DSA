class Node:
    def __init__(self, val, next=None):
        self.val = val
        self.next = next


class Queue:
    def __init__(self):
        self.first = None
        self.last = None
        self.size = 0

    def enqueue(self, data):
        if self.size == 0:
            self.last = Node(data)
            self.first = self.last
        else:
            self.last.next = Node(data)

        self.last = Node(data)
        self.size += 1
        return self.size

queue = Queue()
queue.enqueue(10)
print(queue.last.val)  # 1
queue.size  # 1
queue.enqueue(100)
print(queue.last.val)  # 2
queue.size  # 2
queue.enqueue(1000)  # 3
queue.size  # 3
print(queue.last.val)
