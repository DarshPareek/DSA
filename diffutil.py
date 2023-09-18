# S1 = 'face'
# S2 = 'book'
S1 = 'XMJYAUZ'
S2 = 'XMJAATZ'
lookup = [[0 for x in range(len(S2) + 1)] for y in range(len(S1) + 1)]


def printmat(mat):
    for i in mat:
        print(i)


def LCSLength(S1, S2, m, n, lookup):
    for i in range(m + 1):
        lookup[i][0] = 0
    for j in range(n + 1):
        lookup[0][j] = 0
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if S1[i - 1] == S2[j - 1]:
                lookup[i][j] = lookup[i - 1][j - 1] + 1
            else:
                lookup[i][j] = max(lookup[i - 1][j], lookup[i][j - 1])


LCSLength(S1, S2, len(S1), len(S2), lookup)


def diff(S1, S2, m, n, lookup):
    LCSLength(S1, S2, len(S1), len(S2), lookup)
    res = ''
    if lookup[len(S1)][len(S2)] == 0:
        for i in S1:
            res += "-"+i
        for i in S2:
            res += "+"+i
    if lookup[len(S1)][len(S2)] != 0:
        for i in range(1, len(lookup)):
            for j in range(1, len(lookup[i])):
                if lookup[i][j] == lookup[i-1][j-1] + 1:
                    res += S1[i-1]
        printmat(lookup)
    print(res)


diff(S1, S2, len(S1), len(S2), lookup)
