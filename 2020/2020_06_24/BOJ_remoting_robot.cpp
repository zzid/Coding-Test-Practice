#include <bits/stdc++.h>
using namespace std;
#define MIN -987654321
int maps[1000][1000];
int dp[1000][1000][3];
bool visited[1000][1000];
const int dy[3] = {1,0,0};
const int dx[3] = {0,1,-1};
int n, m;
int dfs(int y, int x, int d){
    if(y == n-1 && x == m-1) return maps[y][x];
    if(dp[y][x][d] != MIN) return dp[y][x][d];

    int& ret = dp[y][x][d];

    for(int i=0; i<3; i++){
        int ny = y + dy[i], nx = x + dx[i];
        if(ny < 0 || ny >=n || nx < 0 || nx >=m) continue;
        if(visited[ny][nx]) continue;
        visited[ny][nx] = true;
        ret = max(maps[y][x] + dfs(ny,nx,i) , ret);
        visited[ny][nx] = false;
    }
    return ret;
}
int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> maps[i][j];
            dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = MIN;
        }
    }
    visited[0][0] = true;
    cout << dfs(0,0,0) <<endl;
    return 0;
}


/*
5 5
10 25 7 8 13
68 24 -78 63 32
12 -69 100 -29 -25
-16 -22 -57 -33 99
7 -76 -11 77 15
*/
//319
