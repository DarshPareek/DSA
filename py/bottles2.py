def maxBottlesDrunk(numBottles: int, numExchange: int) -> int:
    eb = 0
    res = 0
    while(numBottles != 0 or numExchange < eb):
        eb = numBottles
        res += numBottles
        print(res)
        numBottles = 0
        while(eb != 0 and numExchange <= eb):
            numBottles += 1
            eb -= numExchange
            numExchange += 1

maxBottlesDrunk(13, 6)
