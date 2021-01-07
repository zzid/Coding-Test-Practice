#include <bits/stdc++.h>
using namespace std;
int n, answer =INT_MIN;
const int dy[4] ={1,-1,0,0};
const int dx[4] ={0,0,1,-1};
int forest[500][500];
bool visited[500][500];
int dp[500][500];
int dfs(int y, int x){
    if(dp[y][x] != 0) return dp[y][x];
    bool change = false;
    for(int i=0; i<4; i++){
        int ny = y + dy[i], nx = x +dx[i];
        if(ny >= n || ny < 0 || nx >= n || nx < 0) continue;
        if(visited[ny][nx]) continue;
        if(forest[ny][nx] > forest[y][x]){
            change = true;
            visited[ny][nx] = true;
            dp[y][x] = max(dp[y][x], dfs(ny,nx) + 1 );
            visited[ny][nx] = false;
        }
    }
    if(!change) return dp[y][x] = 1;
    return dp[y][x];
}
int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> forest[i][j];
            dp[i][j] = 0;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            dfs(i,j);
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            answer = answer > dp[i][j] ? answer : dp[i][j];
        }
    }
    cout << answer << "\n";
    return 0;
}
