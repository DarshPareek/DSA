# cook your dish here
for _ in range(int(input())):
    N, M = map(int, input().split())
    s = list(map(int, input()))
    aw = sum(s)
    bw = M-aw
    matches_left = N-M
    print(aw, bw, matches_left)
    if matches_left == 0:
        if aw == bw:
            print("Yes")
        else:
            print("No")
    elif matches_left%2 == 0:
        if aw == bw:
            print("Yes")
        elif aw != bw and abs(aw-bw)%2 == 0:
            print("Yes")
        else:
            print("No")
    else:
        if aw != bw and abs(aw - bw)%2 == 1 and matches_left > 2:
            print("Yes")
        else:
            print("No")

