from copy import deepcopy
di = [[-1,0],[-1,-1],[0,-1],[1,-1],[1,0],[1,1],[0,1],[-1,1]]
class fish:
    def __init__(self, y, x, d, num):
        self.y = y
        self.x = x
        self.d = d
        self.num = num
        self.alive = True
class shark:
    def __init__(self, y,x,d,val):
        self.y = y
        self.x = x
        self.d = d
        self.val = val

def rot(i):
    i += 1
    if(i==8): i = 0
    return i

def fish_mov(shk_y, shk_x):
    global lis
    for i in lis:
        if i.alive == False: continue
        ny = i.y + di[i.d][0]
        nx = i.x + di[i.d][1]
        flag = True
        while flag:
            flag = False
            ny = i.y + di[i.d][0]
            nx = i.x + di[i.d][1]
            if ny < 0 or ny >=4 or nx < 0 or nx >=4:
                i.d = rot(i.d)
                flag = True
                continue
            if ny == shk_y and nx == shk_x:
                i.d = rot(i.d)
                flag = True
                continue

        # arr[i.y][i.x] == i.num at this moment 
        # >> arr[i.y][i.x] == arr[ny][nx].num  >> gonna change like this
        cur = deepcopy(i.num)
        nex = deepcopy(arr[ny][nx])
        y = deepcopy(i.y)
        x = deepcopy(i.x)
        nidx = [lis[arr[ny][nx]-1].y , lis[arr[ny][nx]-1].x , lis[arr[ny][nx]-1].num]
        # lis[nidx-1] <> lis[i.num-1]
        lis[arr[ny][nx]-1].y = lis[i.num-1].y
        lis[arr[ny][nx]-1].x = lis[i.num-1].x
        lis[i.num-1].y = nidx[0]
        lis[i.num-1].x = nidx[1]

        arr[ny][nx] = cur
        arr[y][x] = nex
def dfs(y,x,d,val):
    global lis,answer,arr
    nex_fish = deepcopy(lis)
    nex_arr = deepcopy(arr)
    fish_mov(y,x)
    
    for i in range(1,4):
        ny = y + (di[d][0] * i)
        nx = x + (di[d][1] * i)
        if ny < 0 or ny >=4 or nx < 0 or nx >=4: break
        if lis[arr[ny][nx]-1].alive:
            lis[arr[ny][nx]-1].alive = False
            dfs(ny, nx, lis[arr[ny][nx]-1].d, val + lis[arr[ny][nx]-1].num)
            lis[arr[ny][nx]-1].alive = True
            # lis = deepcopy(nex_fish)
    answer = max(val, answer)
    lis = deepcopy(nex_fish)
    arr = deepcopy(nex_arr)
    return 


arr = [[ _ for _ in range(4) ] for _ in range(4)] 
lis = []
answer = 0
for i in range(4):
    line = list(map(int, input().split()))
    for j in range(4):
        num = line.pop(0)
        d = line.pop(0)
        arr[i][j] = num
        lis.append(fish(i,j,d-1,num))
lis.sort(key = lambda x : x.num)
lis[arr[0][0]-1].alive = False
# ----------- never need to change

dfs(0,0,lis[arr[0][0]-1].d, lis[arr[0][0]-1].num)
print(answer)

