# https://www.acmicpc.net/problem/1003
t = int(input())
n = [0] * t
for i in range(t): n[i] = int(input())

maxv = max(n)

fib = [(1,0),(0,1)]
for i in range(2,maxv+1):
    fib.append((fib[i-1][0] + fib[i-2][0],fib[i-1][1] + fib[i-2][1] ))

for i in range(t):
    if n[i] == 0: print(fib[0][0], fib[0][1])
    elif n[i] == 1: print(fib[1][0], fib[1][1])
    else: print(fib[n[i]][0], fib[n[i]][1])