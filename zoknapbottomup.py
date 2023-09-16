def printmat(mat):
    for i in mat:
        print(i)


def zoKnapsackBU(profits, weights, capacity):
    matrix = [[0 for _ in range(capacity+1)] for _ in range(len(weights)+1)]
    for i in range(1, len(matrix)):
        for j in range(len(matrix[i])):
            if j-weights[i-1] >= 0:
                matrix[i][j] = max(
                    matrix[i-1][j], (matrix[i-1][j-weights[i-1]])+profits[i-1])
    return matrix[len(matrix)-1][len(matrix[0])-1]


profits = [31, 26, 72, 17]
weights = [3, 1, 5, 2]
capacity = 7
zoKnapsackBU(profits, weights, capacity)
