#   Created by Elshad Karimov
#   Copyright © AppMillers. All rights reserved.

# Zero One Knapsack Problem

class Item:
    def __init__(self, profit, weight):
        self.profit = profit
        self.weight = weight


def printmat(mat):
    for i in mat:
        print(i)


def zoKnapsack(items, capacity, currentIndex, tempDict):
    dk = str(currentIndex) + str(capacity)
    if capacity <= 0 or currentIndex < 0 or currentIndex >= len(items):
        return 0
    elif dk in tempDict:
        return tempDict[dk]
    elif items[currentIndex].weight <= capacity:
        p1 = items[currentIndex].profit+zoKnapsack(
            items, capacity-items[currentIndex].weight, currentIndex+1, tempDict)
        p2 = zoKnapsack(items, capacity, currentIndex+1, tempDict)
        tempDict[dk] = max(p1, p2)
        return tempDict[dk]
    else:
        return 0


profits = [31, 26, 72, 17]
weights = [3, 1, 5, 2]
items = []
for (i, j) in zip(profits, weights):
    items.append(Item(i, j))
print(zoKnapsack(items, 7, 0, {}))
