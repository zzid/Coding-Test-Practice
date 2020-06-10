// https://www.acmicpc.net/problem/11404
#include <bits/stdc++.h>
using namespace std;
#define MAX 987654321
int adj[101][101];
int n,m;
void solve(){
    for(int mi=1; mi<=n; mi++){
        for(int f=1; f<=n; f++){
            for(int t=1; t<=n; t++){
                if(adj[f][mi] != MAX && adj[mi][t] != MAX){
                    if(f == t) continue;
                    adj[f][t] = min(adj[f][t], adj[f][mi]+adj[mi][t]);
                }
            }
        }
    }
}
void prtans(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            printf("%d ", adj[i][j] == MAX ? 0 : adj[i][j]);
        }
        printf("\n");
    }
}
// a~c >> a ~ x ... x ~ c
int main(){
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            adj[i][j] = MAX;
        }
    }
    for(int i=0; i<m; i++){
        int a,b,c;
        scanf("%d %d %d", &a, &b, &c);
        adj[a][b] = min(adj[a][b], c);
    }
    solve();
    prtans();
    return 0;
}
