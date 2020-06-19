#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
typedef pair<p,int> pp;
const int dy[4] = {-1,1,0,0};
const int dx[4] = {0,0,-1,1};
int mod = 1e9 + 7;
p cur,home;
int t_lim, num;
// map<p,int> obstacle;
// map<pp, int> dp;
int obstacle[401][401];
int dp[401][401][201];
int answer =0;
int dfs(int x, int y, int t){
    if(x == home.first && y == home.second && t <= t_lim) return 1;
    if(abs(home.first - x) + abs(home.second - y) > t_lim - t) return 0;
    if(obstacle[x][y] == 1) return 0;
    if(dp[x][y][t] > 0 ) return dp[x][y][t] % mod;

    for(int i=0; i<4; i++){
        int nx = x + dx[i], ny = y + dy[i];
        if(obstacle[nx][ny] != 1){
            dp[x][y][t] = (dp[x][y][t] + dfs(nx,ny, t+1))%mod;
        }
    }
    if(x == cur.first && y == cur.second) answer = (answer + dp[x][y][t]) % mod;
    return dp[x][y][t] % mod;
}

int main(){
    scanf("%d %d", &cur.first, &cur.second);
    p mov = {200 -cur.first, 200- cur.second};
    cur.first = 200, cur.second = 200;
    dp[200][200][0] = 1;
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
    queue<pp> q;
    q.push({cur, 0});
    // dfs(cur.first, cur.second, 0); 
    dp[cur.first][cur.second][0] = 1;
    while(!q.empty()){
        auto c = q.front(); q.pop();
        int x = c.first.first, y =c.first.second, t = c.second;
        if(abs(home.first - x) + abs(home.second - y) > t_lim - t-1) continue;
        for(int i=0; i<4; i++){
            int ny = y + dy[i], nx = x + dx[i];
            if(ny < 0 || ny >400 || nx < 0 || nx >400) continue;
            if(nx == home.first && ny == home.second && t<= t_lim){
                answer = (answer + dp[x][y][t]) %mod;
            }
            if(obstacle[nx][ny] == 1) continue;
            dp[nx][ny][t+1] = (dp[nx][ny][t] + dp[x][y][t]) % mod;
            q.push({{nx,ny},t+1});
        }
    }
    // while(!q.empty()){
    //     auto c = q.front(); q.pop();
    //     if(c.second +1 +abs(home.first - c.first.first) + abs(home.second - c.first.second) > t_lim){
    //         continue;
    //     }
    //     for(int d =0; d<4; d++){
    //         p idx ={ c.first.first + dx[d], c.first.second + dy[d] };
    //         pair<p, int> n = {idx, c.second+1};
    //         if(idx.first > 100000 || idx.first < -100000 || idx.second > 100000 || idx.second < -100000){
    //             continue;
    //         }
    //         if(n.first.first == home.first && n.first.second == home.second){
    //             if( n.second < t_lim){
    //                 dp[{n.first.first, n.first.second}]
    //                 = (dp[{n.first.first, n.first.second}] + dp[{c.first.first, c.first.second}]) % mod;
    //             }
    //             continue;
    //         }
    //         if(n.second + abs(home.first - n.first.first) + abs(home.second - n.first.second) > t_lim){
    //             continue;
    //         }
    //         if(obstacle.count({n.first.first, n.first.second}) == 1){ //- minval
    //             continue;
    //         }
    //         else{
    //             dp[ {n.first.first, n.first.second} ]
    //             =(dp[{c.first.first, c.first.second}] + dp[ {n.first.first, n.first.second} ]) % mod;
    //             q.push(n);
    //         }
    //     }
    // }
    printf("%d", answer% mod);
    // printf("%d", answer);
    return 0;
}
