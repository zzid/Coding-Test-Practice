#include <bits/stdc++.h>
using namespace std;
vector<int> weight(10001);
vector<int> nodes[10001];
int dp[10001][2], n;
vector<int> travel;

int recur(int cur, int prv, bool flag){
    int& ret = dp[cur][flag];
    if(ret != -1) return ret;
    ret = 0;

    if(flag){ // Must not to go adj lists
        ret += weight[cur];
        for(auto i : nodes[cur]){
            if(i == prv) continue; // this prevent the cycle
            ret += recur(i, cur, 0);
        }
    }else{
        for(auto i : nodes[cur]){
            if(i==prv) continue;
            ret += max(recur(i, cur, 0), recur(i, cur, 1));
        }
    }
    return ret;
}
void where(int cur,int prv, bool flag){
    if(flag){
        travel.push_back(cur);
        for(auto i : nodes[cur]){
            if(i == prv) continue;
            where(i,cur,0);
        }

    }
    else{
        for(auto i : nodes[cur]){
            if(i == prv) continue;
            if(dp[i][0] >= dp[i][1]) where(i,cur,0);
            else where(i,cur,1);
        }
    }
}
int main(){
    scanf("%d", &n);
    weight.resize(n+1);
    for(int i=1; i<=n; i++) scanf("%d", &weight[i]);
    for(int i=0; i<n-1; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        nodes[a].push_back(b);
        nodes[b].push_back(a);
    }
    memset(dp, -1, sizeof dp);
    int a = recur(1,0,0),
        b = recur(1,0,1);
    
    if(a>=b) where(1,0,0);
    else where(1,0,1);

    sort(travel.begin(), travel.end());
    printf("%d\n", max(a, b));
    for(int i=0; i<travel.size(); i++){
        printf("%d ", travel[i]);
    }
    return 0;
}
