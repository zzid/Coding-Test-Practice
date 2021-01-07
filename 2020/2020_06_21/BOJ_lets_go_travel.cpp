#include <bits/stdc++.h>
using namespace std;
int n,m;
int adj[201][201];
int plan[1001];
void input(){
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> adj[i][j];
        }
    }
    for(int i=1; i<=m; i++) cin >> plan[i];
}
void floyd(){
    for(int a=1; a<=n; a++){
        for(int f=1; f<=n; f++){
            for(int t=1; t<=n; t++){
                if(adj[f][a] != 0 && adj[a][t] != 0){
                    if(f==t) continue;
                    adj[f][t] = adj[f][a] + adj[a][t];
                }
            }
        }
    }
}
void solve(){
    for(int i=1; i<m; i++){
        if(plan[i] == plan[i+1]) continue;
        if(adj[plan[i]][plan[i+1]] == 0){
            cout << "NO" <<endl;
            return;
        }
    }
    cout << "YES"<<endl;
}
int main(){
    input();
    floyd();
    solve();
    return 0;
}
