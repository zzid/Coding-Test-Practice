#include <bits/stdc++.h>
using namespace std;
int maps[1000][1000];
int dp[1000][1000]={0,};
bool visited[1000][1000];
// const int dy[3] = {1,0,0};
// const int dx[3] = {0,1,-1};
int n, m;
void prt(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << dp[i][j] << " ";
        }
        cout <<endl;
    }
}
// void dfs(int y, int x, int prev){
//     if(y == n-1 && x == m-1) return;
//     if(dp[y][x] > prev + maps[y][x]) return;
//     dp[y][x] = max(prev+ maps[y][x], dp[y][x]);
//     for(int i=0; i<3; i++){
//         int ny = y + dy[i], nx = x + dx[i];
//         if(ny < 0 || ny >=n || nx < 0 || nx >=m) continue;
//         if(visited[ny][nx]) continue;
// //        if(dp[ny][nx] > dp[y][x] + maps[ny][nx]) continue;
// //        dp[ny][nx] = max(dp[y][x] + maps[ny][nx] , dp[ny][nx]);
//         //prt();
//         visited[ny][nx] = true;
//         dfs(ny,nx,dp[y][x]);
//         //cout << "here" <<endl;
//         visited[ny][nx] = false;
//     }
// }
int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> maps[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            dp[i][j] = -987654321;
        }
    }

    for(int i=0; i<m; i++){ // x
        if(i==0) dp[0][i] = maps[i][j];
        else dp[0][i] += (dp[0][i-1] + maps[0][i]);
        visited[0][i] = true;
    }
    for(int i=1; i<n; i++){
        for(int j=0; j<m; j++){

        }
    }


    cout << dp[n-1][m-1] <<endl;
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