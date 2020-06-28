n, m = map(int, input().split())
depth = {}
idx = {}
dep = 0
visited = [False * _ for _ in range(n+1)]
for i in range(m):
    front, back = map(int, input().split())
    visited[front] = True
    visited[back] = True
    if front in idx:
        dep = idx[front]
    else :
        idx[front] = 0
        dep = 0

    if back in idx:
        depth[idx[back]].remove(back)
        if idx[back] > dep: 
            idx[back] += 1
        else: 
            idx[back] = dep + 1
        deeper = idx[back]
    else:
        idx[back] = dep + 1
        deeper = dep +1

    if dep not in depth:
        depth[dep] = []
    if front not in depth[dep]:
        depth[dep].append(front)

    if deeper not in depth:
        depth[deeper] = []
    if back not in depth[deeper]:
        depth[deeper].insert(0,back)
sorted(depth.keys())
for i in range(1,n+1):
    if visited[i] == False:
        print(i, end = ' ')
for keys in depth:
    for a in depth[keys]:
        print(a, end= ' ')

