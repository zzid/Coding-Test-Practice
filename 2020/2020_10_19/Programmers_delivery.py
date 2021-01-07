import copy

def minCost(cost, visited, num, adj, cur):
    adj[1][cur] = min(cost, adj[1][cur])
    
    for a in range(2,num):
        # dest = a
        if adj[cur][a] >= 987654321 or visited[a] or cost > adj[1][a] : continue
        # print(cur , ' ',a)
        n_visited = copy.deepcopy(visited)
        n_visited[a] = True
        minCost(cost + adj[cur][a],n_visited, num,adj,a)

def solution(N, road, K):
    adj = [[ 987654321 for _ in range(N+1)] for _ in range(N+1)]
    for x in road:
        adj[x[0]][x[1]] = min(x[2], adj[x[0]][x[1]])
        adj[x[1]][x[0]] = min(x[2], adj[x[0]][x[1]])
    for a in range(1,N+1):
        if adj[a][a] >= 987654321: adj[a][a] = 0
    visited = [False for _ in range(N+1)] 
    visited[1] = True
    # for a in range(2, N+1) :
    minCost(adj[1][1],visited, N+1, adj,1)
    # for i in range(1,N+1):
    #     for j in range(1,N+1):
    #         if adj[i][j] > 10000:
    #             print('*', end= ' ')
    #         else : print(adj[i][j],end = ' ')
    #     print()
    return len(list(filter(lambda x: x <= K, adj[1])))