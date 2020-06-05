# https://www.acmicpc.net/problem/1004

t = int(input())
for i in range(t):
    x1, y1, x2,y2 = map(int, input().split())
    n = int(input())
    in1, in2 =0,0
    for j in range(n):
        a, b, c = map(int, input().split())
        d1 = ((a-x1)**2)+ ((b-y1)**2)
        d2 = ((a-x2)**2)+ ((b-y2)**2)
        r2 = (c**2)
        if d1 <= r2 and d2 <=r2: continue
        if d1 <= r2: in1 += 1
        if d2 <= r2: in2 += 1
    print(in1 + in2)