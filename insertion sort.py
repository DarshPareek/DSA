def insertionSort(clist, comp=None):
    if not comp:
        def comp(x, y):
            if x < y:
                return -1
            return 1
    for i in range(1, len(clist)):
        key = clist[i]
        j = i-1
        t = clist[j]
        while j >= 0 and comp(key, t) < 0:
            clist[j+1] = t
            j -= 1
            t = clist[j]
        clist[j+1] = key


nums = [4, 5, 6, 7, 8, 1]
insertionSort(nums)
# [2, 3, 3, 4, 4, 4, 5, 23, 32, 32, 34, 34, 35, 43, 67, 75, 232, 232, 453, 546, 4342]
print(nums)
kit = ['LilBub', 'Garfield', 'Blue', 'Grumpy']


def strComp(a, b):
    if a < b:
        return -1
    if a > b:
        return 1
    return 0


insertionSort(kit, strComp)
print(kit)
