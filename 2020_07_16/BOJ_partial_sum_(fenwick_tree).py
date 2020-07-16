'''
<first impression> (wrong! maybe..)
# maybe have to use 'map'
# if one value has changed, should be cascading the map elements
'''
'''
Study!!!
# Have to use segment tree or penwick tree
'''
def update(idx, val):
    global fenwick_tree
    while idx < len(fenwick_tree):
        fenwick_tree[idx] += val
        idx += (idx & (-idx)) # idx & (-idx) >> find the lower bit 

def make_fenwick_tree():
    for i in range(1, n+1):
        update(i, nums[i])

def sum_(idx):
    global fenwick_tree
    result = 0
    while idx >0:
        result += fenwick_tree[idx]
        idx -= (idx & (-idx))
    return result


n, m, k = map(int, input().split())
nums = [0]

go = []
for i in range(n):
    nums.append(int(input()))
for i in range(m+k):
    a, b, c = map(int, input().split())
    go.append((a,b,c))
fenwick_tree = [0 for _ in range(len(nums))]

make_fenwick_tree()

for i in go:
    a,b,c = i
    if a == 1:
        diff = c - nums[b]
        nums[b] = c
        update(b,diff)
    else:
        print(sum_(c) - sum_(b-1))