# https://www.acmicpc.net/problem/1002
t = int(input())
for i in range(t):
    x1, y1, r1, x2, y2, r2 = map(int, input().split(' '))
    if x1 == x2 and y1 == y2:
        if r1 == r2: print(-1)
        else: print(0)
        continue
    d = ((x1-x2) **2 + (y1-y2) **2) ** (1/2)
    R = max(r1,r2)
    r = min(r1,r2)
    print(1 if R+r == d or d+r == R else 0 if d+r <R or r+R < d else 2)
    