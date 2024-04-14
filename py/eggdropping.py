INT_MAX = 32767


def printmat(mat):
    for i in mat:
        print(i)


# def eggDrop(n, k):
#     mat = [[0 for _ in range(n+1)] for _ in range(k+1)]
#     for i in range(n+1):
#         mat[0][i] = 0
#     for j in range(k+1):
#         mat[j][0] = 0
#         for i in range(n+1):
#             mat[1][i] = i
#         mat[2][1] = 1
#         for i in range(2, k+1):
#             for j in range(2, n+1):
#                 print(i, j)
#                 mat[i][j] = 1+min(mat[i-1][j-1], mat[i][j-1])
#     printmat(mat)


# eggDrop(36, 2)
INT_MAX = 32767

# Function to get minimum number of trials needed in worst
# case with n eggs and k floors


def eggDrop(n, k):
    # A 2D table where entery eggFloor[i][j] will represent minimum
    # number of trials needed for i eggs and j floors.
    eggFloor = [[0 for x in range(k + 1)] for x in range(n + 1)]

    # We need one trial for one floor and0 trials for 0 floors
    for i in range(1, n + 1):
        eggFloor[i][1] = 1
        eggFloor[i][0] = 0

    # We always need j trials for one egg and j floors.
    for j in range(1, k + 1):
        eggFloor[1][j] = j

    # Fill rest of the entries in table using optimal substructure
    # property
    for i in range(2, n + 1):
        for j in range(2, k + 1):
            eggFloor[i][j] = INT_MAX
            for x in range(1, j + 1):
                res = 1 + max(eggFloor[i-1][x-1], eggFloor[i][j-x])
                eggFloor[i][j] = min(res, eggFloor[i][j])
    printmat(eggFloor)
    # eggFloor[n][k] holds the result
    return eggFloor[n][k]


print(eggDrop(2, 36))
