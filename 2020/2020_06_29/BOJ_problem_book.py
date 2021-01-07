from queue import PriorityQueue
n, m = map(int, input().split())
income = [0 * _ for _ in range(n+1)]
result = [0 * _ for _ in range(n+1)]
arr = [[] * _ for _ in range(n+1)]
for i in range(m):
    a, b = map(int, input().split())
    arr[a].append(b)
    income[b] += 1
q = PriorityQueue()
for i in range(1, n+1):
    if income[i] == 0:
        q.put(i)
for i in range(1, n+1):
    x = q.get()
    result[i] = x
    for j in arr[x]:
        income[j] -= 1
        if income[j] == 0:
            q.put(j)
for i in range(1,n+1):
    print(result[i], end = ' ')
