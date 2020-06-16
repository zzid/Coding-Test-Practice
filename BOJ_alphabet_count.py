# https://www.acmicpc.net/problem/10808
s = input()
answer = [0] * 26
for i in range(len(s)):
    answer[ord(s[i]) -97] += 1
for i in range(26):
    print(answer[i], end =' ')