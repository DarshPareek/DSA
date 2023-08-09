def bubbleSort(clist, comp=None):
    if not comp:
        def comp(x, y):
            if x < y:
                return -1
            return 1
    for i in range(0, len(clist)):
        for j in range(i+1, len(clist)):
            if comp(clist[i], clist[j]) > 0:
                clist[i], clist[j] = clist[j], clist[i]


arr = [4, 20, 12, 10, 7, 8]
bubbleSort(arr)
print(arr)  # [4, 7, 8, 10, 12, 20]
kit = ['LilBub', 'Garfield', 'Blue', 'Grumpy']


def strComp(a, b):
    if a < b:
        return -1
    if a > b:
        return 1
    return 0


bubbleSort(kit, strComp)
print(kit)
