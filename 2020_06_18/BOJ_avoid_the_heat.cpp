#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
typedef pair<p,int> pp;
const int dy[4] = {-1,1,0,0};
const int dx[4] = {0,0,-1,1};
int t_lim, num, answer =0, mod = 1e9 + 7;
int obstacle[401][401], dp[401][401][201];
p cur,home;
int dfs(int x, int y, int t){
    if(x == home.first && y == home.second && t <= t_lim) return 1;
    if(abs(home.first - x) + abs(home.second - y) > t_lim - t) return 0;
    // if(y <0 || y > 400 || x < 0 || x > 400) return 0;
    if(obstacle[x][y] == 1) return 0;
    
    if(dp[x][y][t] > 0 ) return dp[x][y][t]; //?

    for(int i=0; i<4; i++){
        int nx = x + dx[i], ny = y + dy[i];
        dp[x][y][t] = (dp[x][y][t] + dfs(nx,ny, t+1)) % mod;
    }
    if(x == cur.first && y == cur.second) answer = (answer + dp[x][y][t]) % mod;
    return dp[x][y][t] % mod;
}

int main(){
    scanf("%d %d", &cur.first, &cur.second);
    p mov = {200 -cur.first, 200- cur.second};
    cur.first = 200, cur.second = 200;
    // dp[200][200][0] = 1;
    scanf("%d", &t_lim);
    scanf("%d %d", &home.first, &home.second);
    home.first += mov.first, home.second += mov.second;
    scanf("%d", &num);
    for(int i=0; i<num; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        a += mov.first, b +=mov.second;
        if(a < 0 || a > 400 || b < 0 || b >400) continue;
        obstacle[a][b] = 1;
    }
    dfs(200,200,0);
    printf("%d", answer% mod);
    return 0;
}