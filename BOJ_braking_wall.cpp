// https://www.acmicpc.net/problem/2206
#include <bits/stdc++.h>
using namespace std;
int n,m,answer =INT_MAX;
int _map[1001][1001];
bool visited[1001][1001];
const int dy[4] ={-1,1,0,0};
const int dx[4] ={0,0,-1,1};
typedef pair<pair<int, int>,pair<int,int>> p;
void bfs(queue<p> q){
    while(!q.empty()){
        p c = q.front(); q.pop();
        int y = c.first.first, x = c.first.second,
            cnt = c.second.first, len  = c.second.second;
        if(visited[y][x]) continue;
        visited[y][x] = true;
        for(int d=0; d<4; d++){
            int ny = y + dy[d], nx = x + dx[d];
            if(ny <1 || ny >n || nx < 1 || nx >m) continue;
            if(cnt >1 ) continue;
            if(ny == n && nx == m) answer = min(answer, len+1);
            if(_map[ny][nx] == 1 && cnt == 0)q.push({{ny,nx},{cnt+1, len+1}});
            else if(_map[ny][nx] == 0) q.push({{ny,nx}, {cnt, len+1}});
        }
    }
}
int main(){
    scanf("%d %d", &n,&m);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            scanf("%1d", &_map[i][j]);
        }
    }
    queue<p> q;
    q.push({{1,1},{0,1}});
    bfs(q);
    printf("%d",answer == INT_MAX ? -1 : answer);
    return 0;
}
