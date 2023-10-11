def printmat(mat):
    for i in mat:
        print(i)


def findMinOperationBU(s1, s2, tempDict):
    matrix = [[0 for _ in range(len(s2)+1)] for _ in range(len(s1)+1)]
    for i in range(len(matrix)):
        for j in range(len(matrix[i])):
            if i == 0 and j != 0:
                matrix[i][j] = matrix[i][j-1]+1
            if i != 0 and j == 0:
                matrix[i][j] = matrix[i-1][j]+1
    for i in range(len(s1)):
        for j in range(len(s2)):
            if s1[i] == s2[j]:
                matrix[i+1][j+1] = matrix[i][j]
            if s1[i] != s2[j]:
                matrix[i+1][j+1] = min(matrix[i][j],
                                       matrix[i+1][j], matrix[i][j+1]) + 1
    # printmat(matrix)
    return matrix[len(s1)][len(s2)]


print(findMinOperationBU("table", "tbrltt", {}))
# num = 69420  # any number here
# print(sum(list(int(i) for i in str(num))))
