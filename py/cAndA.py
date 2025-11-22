for _ in range(int(input())):
    N, M, X, Y = map(int, input().split())
    rem_n = N - 1
    rem_m = M - 1
    is_possible = False
    if rem_n % X == 0 and rem_m % Y == 0:
        is_possible = True
    if not is_possible and rem_n > 0 and rem_m > 0:
        if (rem_n - 1) % X == 0 and (rem_m - 1) % Y == 0:
            is_possible = True
    if is_possible:
        print("Chefirnemo")
    else:
        print("Pofik")
