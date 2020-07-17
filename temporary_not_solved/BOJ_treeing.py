import sys
file = open('./input.txt','r')
input = file.readline

mod = 1000000007
answer = 1
class fenwickTree:
    def __init__(self, max_leng):
        self.cnt = [0 for _ in range(max_leng+1)] # #of trees, which are positioned left side
        self.value = [0 for _ in range(max_leng+1)] # sum of values of tress, ""
        self.max_leng = max_leng
    def update(self, idx, val):
        while idx <= self.max_leng:
            self.cnt[idx] += 1
            self.value[idx] += val
            # if self.value[idx] > 0: self.value[idx] % mod
            idx += idx & (-idx)

    def sum(self, idx, isCnt):
        result = 0
        while idx:
            if isCnt:
                result += self.value[idx]
            else:
                result += self.cnt[idx]
            # if result > 0: result %= mod
            idx -= idx & (-idx)
        return result
n = int(input())
zero = int(input()) + 1
tree = fenwickTree(200000)
tree.update(zero,zero)
diff = zero

for i in range(2, n+1):
    num = int(input()) + 1
    go = tree.sum(num, 1)
    negative = tree.sum(num,0)
    temp = ((2 * go + 1 - i) * num ) - negative
    temp += diff -negative
    temp %= mod
    diff += num
    answer = (answer * temp) % mod
    tree.update(num,num)
print(tree.cnt[:n+2])
print(tree.value[:n+2])
print('correct answer : ', int(input()))
print(answer % mod if answer>0 else answer)