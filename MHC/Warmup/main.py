def lookup(n, l):
    for i in range(len(l)-1,-1,-1):
        if l[i] == n:
            return i
    return -1
def solve(n, curr, fin, index):
    res = 0
    data = []
    for i in range(n):
        if curr[i] > fin[i]:
            res = -1
            break
        elif curr[i] == fin[i]:
            continue
        else:
            t = lookup(fin[i], curr)
            if t > -1 :
                res+=1
                data.append([i+1, index[t]+1])
                curr[i] = fin[i]
            else:
                res = -1
                break
    return (res, data)


with open('./input.txt', 'r') as file:
    # Read all lines into a list
    lines_list = file.readlines()
for i in range(len(lines_list)):
    lines_list[i] = lines_list[i].strip()
inp = lines_list

test_cases = int(inp[0])
t = 1
for i in range(test_cases):
    dishes_num = int(inp[t])
    t+=1
    current_temp = list(map(int, inp[t].split()))
    t+=1
    needed_temp = list(map(int, inp[t].split()))
    t+=1
    # print(dishes_num)
    # print(current_temp)
    # print(needed_temp)
    pairs = []
    for j in range(len(current_temp)):
        pairs.append((j, current_temp[j], needed_temp[j]))
    pairs.sort(key=lambda x: x[1])
    # print(pairs)
    index = []
    current_temp = []
    needed_temp = []
    for j in pairs:
        index.append(j[0])
        current_temp.append(j[1])
        needed_temp.append(j[2])
    result = solve(dishes_num,current_temp,needed_temp, index)
    if result[0] == -1:
        print(f"Case #{i+1}:", result[0])
    else: 
        print(f"Case #{i+1}:", result[0])
        if len(result[1]) != 0:
            for i in result[1]:
                print(i[1], i[0])