# cook your dish here
for _ in range(int(input())):
    N, M = map(int, input().split())
    arr = list(map(int, input().split()))
    cnt = 0
    for i in range(len(arr)):
        for j in range(i, len(arr)):
            p = sum(arr[j:])
            print(p,arr[j:])
            if p%M==0:
                cnt+=1
    print(cnt)
