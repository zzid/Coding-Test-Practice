# https://www.acmicpc.net/problem/1987

def dfs(y,x,cur):
    global answer
    answer = max(answer,cur)
    if answer == 26: return
    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]
        if ny < 0 or ny >= r or nx <0 or nx >= c: continue
        if visited[ord(maps[ny][nx])-65] == True: continue
        visited[ord(maps[ny][nx])-65] = True
        dfs(ny,nx,cur+1)
        visited[ord(maps[ny][nx])-65] = False

r,c = map(int, input().split())
maps = []
for i in range(r):
    temp = input()
    maps.append(temp)
visited = [False] * 26
y,x = 0,0
visited[ord(maps[y][x]) -65] = True

dy, dx = (-1,1,0,0), (0,0,-1,1)
answer = 0
dfs(0,0,1)
print(answer)

# 5 5
# IEFCJ
# FHFKC
# FFALF
# HFGCF
# HMCHH
# 10

# 2 4
# CAAB
# ADCB 
# 3

# 12 16
# ABCDEFGHIJKLMNOP
# BCDEFGHIJKLMNOPQ
# CDEFGHIJKLMNOPQR
# DEFGHIJKLMNOPQRS
# EFGHIJKLMNOPQRST
# FGHIJKLMNOPQRSTU
# GHIJKLMNOPQRSTUV
# HIJKLMNOPQRSTUVW
# IJKLMNOPQRSTUVWX
# JKLMNOPQRSTUVWXY
# KLMNOPQRSTUVWXYZ
# LMNOPQRSTUVWXYZA
# 26