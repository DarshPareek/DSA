heights = eval(input())
directions = [[-1,0],[0,-1],[1,0],[0,1]]
m = len(heights)
n = len(heights[0])
tp = []
lp = []
ba = []
ra = []
for i in range(m):
    temp = []
    for j in range(n):
        if i == 0:
            temp.append(True)
        elif heights[i-1][j] <= heights[i][j]:
            temp.append(tp[i-1][j])
        else:
            temp.append(False)
    tp.append(temp)
    ba.append([])
for i in range(n):
    for j in range(m):
        if i == 0:
            lp.append([True])
        elif heights[j][i-1] <= heights[j][i]:
            lp[j].append(lp[j][i-1])
        else:
            lp[j].append(False)
    ra.append([])
for i in range(m-1, -1, -1):
    for j in range(n-1,-1,-1):
        if i == m-1:
            ba[i].append(True)
        elif heights[i+1][j] <= heights[i][j]:
            ba[i].append(ba[i+1][j])
        else:
            ba[i].append(False)
for i in range(n-1,-1,-1):
    for j in range(m-1,-1,-1):
        if i == n-1:
            ra[j].insert(0, True)
        elif heights[j][i+1] <= heights[j][i]:
            ra[j].insert(0,ra[j][(i-n+1)])
        else:
            ra[j].insert(0, False)
res = []
print(tp) 
print(lp) 
print(ba) 
print(ra)
for i in range(n):
    for j in range(m):
        if (tp[i][j] or lp[i][j]) and (ba[i][j] or ra[i][j]):
            res.append([i,j])
print(res)