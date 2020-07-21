#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> inp[1000001],nodes[1000001];
int dp[1000001][2];
void pruning(int cur, int prv){
    for(auto i : inp[cur]){
        if( i != prv){
           nodes[cur].push_back(i);
           pruning(i, cur);
        }
    }
}
int recur(int cur, bool visit){
    int& ret = dp[cur][visit];
    if(ret != -1) return ret;
    ret = 0;
    if(visit){
        for(auto i : nodes[cur]){
            ret += min(recur(i,0), recur(i,1));
        }
        ret++;
    }else{
        for(auto i : nodes[cur]){
            ret += recur(i,1);
        }
    }
    return ret;
}
int main(){
    scanf("%d", &n);
    for(int i=0; i<n-1; i++){
        int a,b;
        scanf("%d %d", &a, &b);
        inp[b].push_back(a);
        inp[a].push_back(b);
    }
    pruning(1,0);
    memset(dp,-1, sizeof dp);
    printf("%d", min(recur(1,0), recur(1,1)));
    return 0;
}
/* Was try with Python3 but failed */

// ###################################
// # import sys
// # file = open('./input.txt', 'r')
// # input = file.readline
// ###################################

// def pruning(cur, prv):
//     global nodes,nex
//     for nxt in nodes[cur]:
//         # print('-----------')
//         # print(f'cur : {cur}, nxt : {nxt}, prv : {prv} ')
//         # print(f'nxt_bin : {bin(nxt)} , prv_bin : {bin(prv)} , result : { nxt ^ prv } || {nxt & prv}')
//         # print('-----------')
//         if nxt ^ prv:
//             nex[cur].append(nxt)
//             pruning(nxt, cur)

// # if this one is early apater
// # adjs don't need to be EA
// # but in other case, adjs must be EA all

// def solution(cur, visit):
//     global dp,nex
//     if dp[cur][visit] != -1:
//         return dp[cur][visit]
//     dp[cur][visit] = 0
//     if not visit:
//         for i in nex[cur]:
//             dp[cur][visit] += solution(i, 1)
//     else:
//         for i in nex[cur]:
//             dp[cur][visit] += min(solution(i, 0),solution(i, 1))
//         dp[cur][visit] += 1
//     return dp[cur][visit]

// n = int(input())
// nodes = [ [] for _ in range(n+1)]
// nex = [ [] for _ in range(n+1)]
// dp = [[-1 for _ in range(2)] for _ in range(n+1)]

// for i in range(n-1):
//     f, t = map(int , input().split())
//     nodes[f].append(t)
//     nodes[t].append(f)

// pruning(1,0)

// answer = min(solution(1,0), solution(1,1))
// print(answer)

// ###################################
// # correct = int(input())
// # if answer == correct:
// #     print("CORRECT")
// # else:
// #     print("WA")
// ###################################