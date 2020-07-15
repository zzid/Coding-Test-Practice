# | 2020-07-temp |[BOJ] 음악프로그램 ( 2623 번 ) |https://tinyurl.com/y73eb4tc|

def bfs():
    global indegree, n,answer, nodes,visited
    change = True
    while change:
        q = []
        change = False
        for i in range(1,n+1):
            if indegree[i] == 0 and visited[i-1] == False:
                change = True
                q.append(i)
        for i in range(len(q)):
            for j in range(1,n+1):
                while q[i] in nodes[j]:
                    nodes[j].remove(q[i])
                    indegree[j] -= 1
            visited[q[i]-1] = True
            answer.append(q[i])
    

n, m = map(int, input().split())
dic = {}
answer = []
order = [[] for _ in range(m)]
indegree = [ 0 for _ in range(n+1)]
visited = [ False for _ in range(n)]
nodes = [[] for _ in range(n+1)]
for i in range(m):
    temp = list(map(int, input().split()))
    # dic[i] = temp[0]
    for a in range(1,len(temp)):
        order[i].append(temp[a])

for i in range(m):
    for j in range(1,len(order[i])):
        if order[i][j-1] not in nodes[order[i][j]]:
            nodes[order[i][j]].append(order[i][j-1])
            indegree[order[i][j]] += 1
bfs()
if len(answer) != n:
    print(0)
else:
    for i in range(len(answer)):
        print(answer[i])

