# https://www.acmicpc.net/problem/1038

n = input()
n = int(n)
max_v = 9876543210
answer = 10
i = 11
while 1:
    if n <= 10:
        i = n
        break
    i = str(i)
    e = len(i)-1
    flag = True
    p = 0
    #32233
    for x in range(e):
        if i[x] <= i[x+1]:
            p = e-x-1
            flag = False
            break
    i = int(i)
    if flag:
        answer += 1 #if right
        if answer == n:
            break
        i += 1
        continue

    i += pow(10,p)
    if i > max_v: break
if i > max_v: print(-1)
else : print(i)