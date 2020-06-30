#include <bits/stdc++.h>
using namespace std;
int n,answer =INT_MIN;
typedef pair<pair<int, int>,int> pp;
const int dy[4] ={1,-1,0,0};
const int dx[4] ={0,0,1,-1};
int forest[500][500];
bool visited[500][500];
int dp[500][500];
int dfs(int y, int x, int days){
    if(dp[y][x] != 0) return dp[y][x];
    int& ret = dp[y][x];
    for(int i=0; i<4; i++){
        int ny = y + dy[i], nx = x +dx[i];
        if(ny >= n || ny < 0 || nx >= n || nx < 0) continue;
        if(visited[ny][nx]) continue;
        if(forest[ny][nx] > forest[y][x]){
            visited[ny][nx] = true;
            ret = max(ret, dp[y][x] + dfs(ny,nx,days+1));
            visited[ny][nx] = false;
        }
    }
    return 1;
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
            visited[i][j] = true;
            dfs(i,j,1);
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            answer = answer > dp[i][j] ? answer : dp[i][j];
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << answer << "\n";
    return 0;
}
