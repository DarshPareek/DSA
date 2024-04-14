class Pair(object):
    def __init__(self, a, b):
        self.a = a
        self.b = b


def maxChainLength(arr, n):
    arr.sort(key=lambda p: p.b)
    l = 1
    prev = arr[0]
    for i in range(1, n):
        if prev.b < arr[i].a:
            l += 1
    return l


arr = []
for i in [[5, 24], [39, 60], [15, 28], [27, 40], [50, 90]]:
    arr.append(Pair(i[0], i[1]))
print(maxChainLength(arr, len(arr)))
