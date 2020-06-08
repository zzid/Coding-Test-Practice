import sys
sys.setrecursionlimit(2000)
def Find(x,val,prev):
    global order, time,answer,dp
    if len(order[x]) == 0:
        dp[x] = time[x]
        answer = max(val, answer)
        # return
    for i in order[x]:
        if dp[i] != 0:
            dp[x] = dp[i] + prev
            answer = max(val + dp[i], answer)
        else: Find(i, time[i] + val, time[i])
# answer = 0
t = int(sys.stdin.readline())
for i in range(t):
    n, k = map(int,sys.stdin.readline().split())
    time = [0] * (n+1)
    dp = [0] * (n+1)
    # answer =0
    time[1:] = list(map(int, sys.stdin.readline().split()))
    order = [[] for _ in range(n+1)]
    for j in range(k):
        a, b = map(int, sys.stdin.readline().split())
        order[b].append(a)
    x = int(sys.stdin.readline())
    done = set()
    answer = 0
    while x not in done:
        for a in range(1,n+1):
            if len(order[a]) == 0:
                dp[a] = time[a]
                done.add(a)
                continue
            else:
                for b in order[a]:
                    if b in done:
                        dp[a] += dp[b]

                
                    
    sys.stdout.write(str(answer) +'\n')
    # print(answer)
    # print(dp[1:])
    # print('answer : ', answer)