class node:
    def __init__(self, num):
        self.num = num
        self.adj = []
        # self.parent = parent
        # self.children = []
def check():
    global visit,n
    for i in range(n, 0, -1):
        if visit[i] == False:
            return False
    return True
n = int(input())
visit = [ False for _ in range(n+1) ]

nodes = {}
for i in range(n-1):
    f, t = map(int , input().split())
    if f not in nodes:
        temp1 = node(f)
        nodes[f] = temp1
    if t not in nodes[f].adj:
        nodes[f].adj.append(t)

    if t not in nodes:
        temp2 = node(t)
        nodes[t] = temp2 
    if f not in nodes[t].adj:
        nodes[t].adj.append(f)
arr = sorted(nodes.values(), key = lambda x : len(x.adj), reverse= True)
answer =0
# all_visit = 2 ** n - 1
# visit = 0
cnt = 0
for i in arr:
    answer += 1
    # if i.parent == i.num: # root
    #     cnt += 1
    # cnt += len(nodes[i.num].children)
    # if cnt >= n:
    #     print(answer)
    #     break

    # visit |= nodes[i.num].bit
    for j in nodes[i.num].adj:
        visit[j] = True
    if check():
        print(answer)
        break

# print(answer)
# for i in arr:
#     print(i.children)

# for keys in nodes:
#     print(keys, ' ' , nodes[keys].parent, ' ' , nodes[keys].children)