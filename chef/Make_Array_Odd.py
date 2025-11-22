# cook your dish here
for _ in range(int(input())):
    N, X = map(int, input().split())
    arr = []
    ei = []
    oi = []
    narr = list(map(int,input().split()))
    res = 0
    for i in range(N):
        arr.append(narr[i])
        if narr[i]%2 == 0:
            ei.append(i)
        else:
            oi.append(i)
    if X%2 == 0:
        res += len(ei)
        if len(oi) == 0:
            res = -1
    else:
        l = len(ei)
        t = l//2
        q = l%2
        res += t+q
    print(res)


