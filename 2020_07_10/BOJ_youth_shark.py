from copy import deepcopy
di = [[-1,0],[-1,-1],[0,-1],[1,-1],[1,0],[1,1],[0,1],[-1,1]]
class fish:
    def __init__(self, y, x, d, num):
        self.y = y
        self.x = x
        self.d = d
        self.num = num
        self.arrive = True
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

def fish_mov():
    global lis,sh,m
    for i in lis:
        # i is fish object
        if i.arrive == False: continue
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
            if ny == sh.y and nx == sh.x:
                i.d = rot(i.d)
                flag = True
        
        temp = deepcopy(m[(i.y,i.x)])
        m[(i.y,i.x)] = m[(ny,nx)]
        m[(ny,nx)] = temp
        for a in lis:
            if a.y == ny and a.x == nx:
                a.y = i.y 
                a.x = i.x
                break 
        i.y = ny
        i.x = nx
def shark_mov():
    global lis,sh,m
    y = sh.y
    x = sh.x
    max_num = 0
    go_y = 0
    go_x = 0
    for i in range(4):
        ny = y + di[sh.d][0]
        nx = x + di[sh.d][1]
        if ny < 0 or ny >=4 or nx < 0 or nx >=4: break
        if m[(ny,nx)].arrive and m[(ny,nx)].num > max_num:
            go_y = ny
            go_x = nx
            max_num = m[(ny,nx)].num
        y = ny
        x = nx
    
    if m[(go_y,go_x)].arrive:
        sh.val += m[(go_y,go_x)].num
        sh.d = m[(go_y,go_x)].d
        for i in lis:
            if i.num == m[(go_y,go_x)].num:
                print('i : ', i.num, i.y,i.x)
                i.arrive = False
                break       



m = {}
for i in range(4):
    line = list(map(int, input().split(' ')))
    for j in range(4):
        num = line.pop(0)
        d = line.pop(0)
        m[(i,j)] = fish(i,j,d-1,num)
sh = shark(0,0,m[(0,0)].d, m[(0,0)].num)
lis = sorted(m.values(),key = (lambda a : a.num))
for i in lis:
    if i.num == m[(0,0)].num:
        i.arrive = False
        break
print(sh.val)
for i in range(4):
    for j in range(4):
        if m[(i,j)].arrive: print(m[(i,j)].num, end= ' ' )
        else:print(0, end = ' ')
    print()
while 1:
    pivot = sh.val
    fish_mov()
    shark_mov()
    print(sh.val)
    for i in range(4):
        for j in range(4):
            if m[(i,j)].arrive: print(m[(i,j)].num, end= ' ' )
            else:print(0, end = ' ')
        print()
    if pivot == sh.val: break

print(sh.val)


