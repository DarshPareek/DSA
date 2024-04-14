import timeit


def LRSLength1(X, m, n):

    # return if we have reached the end of either string
    if m == 0 or n == 0:
        return 0

    # if characters at index m and n matches and index is different
    if X[m - 1] == X[n - 1] and m != n:
        return LRSLength1(X, m - 1, n - 1) + 1

    # else if characters at index m and n don't match
    return max(LRSLength1(X, m, n - 1), LRSLength1(X, m - 1, n))


def LRSLength2(X, m, n):
    X = list(X)
    c = 0
    visited = []
    l = 0
    while c != len(X):
        if X.count(X[c]) >= 2 and X[c] not in visited:
            l = l+1
            visited.append(X[c])
        c = c+1
    return "".join(visited)

# Python3 program to find the
# longest repeated subsequence

# This function mainly returns LCS(str, str)
# with a condition that same characters
# at same index are not considered.


def longestRepeatedSubSeq(str):
    # This part of code is same as
    # below post it fills dp[][]
    # https://www.geeksforgeeks.org/longest-repeating-subsequence/
    # OR the code mentioned above
    n = len(str)
    dp = [[0 for i in range(n+1)] for j in range(n+1)]
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            if (str[i-1] == str[j-1] and i != j):
                dp[i][j] = 1 + dp[i-1][j-1]
            else:
                dp[i][j] = max(dp[i][j-1], dp[i-1][j])

    # This part of code finds the result
    # string using dp[][] Initialize result
    res = ''

    # Traverse dp[][] from bottom right
    i = n
    j = n
    while (i > 0 and j > 0):
        # If this cell is same as diagonally
        # adjacent cell just above it, then
        # same characters are present at
        # str[i-1] and str[j-1]. Append any
        # of them to result.
        if (dp[i][j] == dp[i-1][j-1] + 1):
            res += str[i-1]
            i -= 1
            j -= 1

        # Otherwise we move to the side
        # that gave us maximum result.
        elif (dp[i][j] == dp[i-1][j]):
            i -= 1
        else:
            j -= 1

    # Since we traverse dp[][] from bottom,
    # we get result in reverse order.
    res = ''.join(reversed(res))

    return res


# This code is contributed by Soumen Ghosh

# r = []
# r.append(timeit.timeit("longestRepeatedSubSeq('ATAKTKGGA')",
#                        globals=globals(), number=1))
# result = timeit.timeit("LRSLength1('ATAKTKGGA',9,9)",
#                        globals=globals(), number=1)
# r.append(result/1)
# result = timeit.timeit("LRSLength2('ATAKTKGGA',9,9)",
#                        globals=globals(), number=1)
# r.append(result/1)
# print(r)
# print(min(r))
print(longestRepeatedSubSeq('bbabbabbbbabaababab'))
print(LRSLength2("abcdefg"*1999+"gfedcba",0,0))
print(len("bbabbabbbbabaababab"),len("bbabbbbbaaabab"))