#include <bits/stdc++.h>
using namespace std;
int parent[100001];
int t,n,answer=0;
bool visited[100001];
void dfs(int a, vector<int> v){
    // if(visited[a]){
    //     answer += 1;
    //     return;
    // }
    // visited[a] = true;
    // if(a == parent[a]){
    //     answer += 1;
    //     return;
    // }
    int next = parent[a];
    // bool _end = false;
    for(int i=0; i<v.size(); i++){
        if(v[i] == next){
            if(parent[v[i]] == next) return;
            else {
                answer++;
                return;
            }
            // _end = true;
            // break;
        }
    }
    // if(_end) return;
    v.push_back(next);
    dfs(next, v);
}
void init(){
    answer =0;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> parent[i];
    }
}
void solve(){
    for(int i=1; i<=n; i++){
        //if(visited[i]) continue;
        if(i == parent[i]){
            //visited[i] = true;
            continue;
        }
        vector<int> v;
        v.push_back(i);
        dfs(i, v);
    }
    cout << "answer : " << answer <<endl;
}
int main(){
    cin >> t;
    while(t--){
        init();
        solve();
    }
    return 0;
}
