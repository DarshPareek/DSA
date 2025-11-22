def solve():
    n = int(input())
    s = input()
    if n == 0:
        print(0)
        return
    w_blocks = 0
    b_blocks = 0
    if s[0] == 'W':
        w_blocks += 1
    else:
        b_blocks += 1
    for i in range(1, n):
        if s[i] != s[i-1]:
            if s[i] == 'W':
                w_blocks += 1
            else:
                b_blocks += 1
    print(min(w_blocks, b_blocks))
t = int(input())
for _ in range(t):
    solve()
