// problem 1: if assign max val as INT_MAX, casue overflow
// problem 2: TSP(0,0), for(int i=0;) >> wrong answer

// solve : TSP(0,1), for(int i=1;)

#include <bits/stdc++.h>
using namespace std;
int n,answer =INT_MAX;
int adj[16][16], dp[16][1 << 16];

int TSP(int cur, int visited){
    if(visited == (1<<n) -1){
        if(adj[cur][0] == 0) return 987654321;
        return adj[cur][0]; // if visited all vertex
    }
    int& temp = dp[cur][visited];
    if(temp != 0) return temp;
    temp = 987654321;
    for(int i=1; i<n; i++){
        if(visited & (1<<i)) continue; // Test with AND operation
        if(adj[cur][i] == 0) continue; // if cur and i aren't adj
        temp = min(temp, TSP(i, visited + (1<<i))+ adj[cur][i]);
    }
    return temp;
}
int main(){
    scanf("%d" , &n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &adj[i][j]);
        }
    }
    printf("%d" , TSP(0,1));
    return 0;
}
