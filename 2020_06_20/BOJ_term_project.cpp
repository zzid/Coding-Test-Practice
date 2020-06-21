#include <bits/stdc++.h>
using namespace std;
int parent[100001];
int from[100001];
int visited[100001];
int t,n,answer;
int dfs(int f, int a, int cnt){
    if(visited[a]){
        if(from[a] != f) return 0;
        return cnt - visited[a];
    }
    from[a] = f;
    visited[a] = cnt;
    return dfs(f, parent[a], cnt+1);
}
void init(){
    cin >> n;
    answer = n;
    for(int i=1; i<=n; i++){
        cin >> parent[i];
        visited[i] = from[i] = 0;
    }
}
void solve(){
    for(int i=1; i<=n; i++){
        if(visited[i]) continue;
        answer -= dfs(i, i, 1);
    }
    cout << answer <<endl;
}
int main(){
    cin >> t;
    while(t--){
        init();
        solve();
    }
    return 0;
}
