import sys
file = open('./input.txt','r')
input = file.readline

mod = 1000000007
n = int(input())
answer = 1
def update(idx, val):
    while idx < len(tree):
        tree[idx] = (tree[idx] + val)
        if tree[idx] > 0: tree[idx] % mod
        idx += idx & (-idx)

def sum(idx):
    result = 0
    while idx > 0:
        result = (result + tree[idx])
        if result > 0:
            result %= mod
        idx -= idx & (-idx)
    return result
nums = [0] *(n+1)
for i in range(1,n+1):
    nums[i] = int(input())
tree = [0] * (n+1)
tree2 = [0] * (n+1)
diff = 0
for i in range(2, n+1):
    
    diff = (diff + nums[i] - nums[i-1])
    if diff > 0: diff %= mod
    update(i,diff)
for i in range(2,n+1):
    answer =(answer * sum(i))
    if answer > 0: answer %= mod
print(answer % mod if answer>0 else answer)