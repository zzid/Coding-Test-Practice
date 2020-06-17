#include <bits/stdc++.h> 
using namespace std; 
vector<vector<int> > order;
int t[1001];
int dp[1001];
 
int Find(int cur){
    int &ret = dp[cur];
    if(ret != -1) return ret;
    ret = t[cur];
    for(int i : order[cur]) ret = max(ret, t[cur]+Find(i));
    return ret;
}
 
int main(){
    int T;
    scanf("%d",&T);
    for(int i=0; i<T; i++){
        int n,k;
        scanf("%d %d",&n,&k);
        order.resize(n+1);
        memset(dp,-1,sizeof(dp));
        for(int q=1; q<=n; q++) scanf("%d",&t[q]);
        for(int j=0; j<k; j++){
            int a,b;
            scanf("%d %d",&a,&b);
            order[b].push_back(a);
        }
        int p;
        scanf("%d",&p);
        printf("%d\n", Find(p));
        order.clear();
    }
    return 0;
}
