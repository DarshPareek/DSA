def swap(clist, i1, i2):
    clist[i1], clist[i2] = clist[i2], clist[i1]


def pivot(clist, pivIndex=0, endIndex=0, comp=None):
    if not comp:
        def comp(x, y):
            if x < y:
                return -1
            return 1
    sIndex = pivIndex
    for i in range(pivIndex+1, endIndex+1):
        if comp(clist[i], clist[pivIndex]) < 0:
            sIndex += 1
            swap(clist, sIndex, i)
    swap(clist, pivIndex, sIndex)
    return sIndex


def quickSort(clist, l=0, r=0, comp=None):
    if not comp:
        def comp(x, y):
            if x < y:
                return -1
            return 1
    if l < r:
        pivIndex = pivot(clist, l, r)
        quickSort(clist, l, pivIndex-1)
        quickSort(clist, pivIndex+1, r)
    return clist


arr = [3, 7, 4, 2, 1]
print(quickSort(arr, l=0, r=len(arr)))
