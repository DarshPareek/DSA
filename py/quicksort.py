def pivot(arr, comparator=None, start=1):
    start = 1
    end = len(arr) - 1
    pivot = 0
    if not comparator:
        comparator = lambda x, y: x < y
    while start <= end:
        # print(arr[start], arr[end], arr[pivot], arr)
        if comparator(arr[pivot], arr[start]):
            if comparator(arr[end], arr[pivot]):
                arr[end], arr[start] = arr[start], arr[end]
            else:
                start -= 1
            end -= 1
        start += 1
    arr[pivot], arr[end] = arr[end], arr[pivot]
    pivot = end

    return pivot


def quickSort(arr, comparator=None, start=0, end=0):
    if len(arr) == 1 or len(arr) == 0:
        return arr
    end = len(arr) - 1
    piv = pivot(arr, comparator, start)
    return quickSort(arr[start:piv+1], comparator, 0, piv)+quickSort(arr[piv+1:end+1], comparator, 0, end)


arr1 = [5, 4, 9, 10, 2, 20, 8, 7, 3]
arr2 = [8, 4, 2, 5, 0, 10, 11, 12, 13, 16]
arr3 = ["LilBub", "Garfield", "Blue", "Grumpy"]


def strLength(a, b):
    return len(a) - len(b)


# print(pivot(arr1))  # 3
# print(pivot(arr2))  # 4
# print(pivot(arr3, strLength))  # 1
#print(quickSort([10, 20, 8, 7, 9]))
print(quickSort(arr3))
