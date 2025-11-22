# cook your dish here
import math
sub_id = int(input())
for _ in range(int(input())):
    x1, y1,x2,y2,x3,y3 = map(int, input().split())
    a = math.sqrt((x2-x1)**2 +(y2-y1)**2)
    b = math.sqrt((x3-x2)**2 +(y3-y2)**2)
    c = math.sqrt((x1-x3)**2 +(y1-y3)**2)
    if sub_id == 1:
        if a == b or b == c or c == a:
            print("Isosceles triangle")
        else:
            print("Scalene triangle")
    if sub_id == 2:
        res = ""
        if a == b or b == c or c == a:
            res += "Isosceles"
        else:
            res += "Scalene"
        A = math.degrees(math.acos((b**2 + c**2 - a**2)/2*b*c))
        B = math.degrees(math.acos((a**2 + c**2 - b**2)/2*a*c))
        C = math.degrees(math.acos((a**2 + b**2 - c**2)/2*a*b))
        if A < 90 and B < 90 and C < 90:
            res += " acute"
        elif A > 90 or B > 90 or C > 90:
            res += " obtuse"
        elif A == 90 or B == 90 or C == 90:
            res += " right"
        res += " triangle"
        print(res)
