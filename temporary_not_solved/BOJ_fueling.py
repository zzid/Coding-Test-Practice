# https://www.acmicpc.net/problem/1826


# 아마 dp


class car:
    def __init__(self, dest, fuel):
        self.dest = dest
        self.fuel = fuel

def dfs(idx, go, cnt, fuel):
    global stations, dist,n,info

    if info.fuel < 0:
        return
    if go:
        info.fuel += stations[idx][1]
    
    dfs(idx+1, True, cnt+1, fuel + stations[idx][1])
    dfs(idx+1, False, cnt, fuel)
n = int(input())
stations = []
dist = []
for i in range(n): 
    a, b= map(int, input().split())
    if i == 0:
        dist.append(a)
    else: 
        dist.append(a-stations[i-1][0])
    stations.append((a,b))

l, p = map(int, input().split())
dist.append(l-stations[-1][0])
info = car(l,p)
print(dist)
