#include<bits/stdc++.h>
using namespace std;
typedef pair< pair <int, int>, int> p;
const int dy[4] = {1,-1,0,0};
const int dx[4] = {0,0,-1,1};

int n,m, answer =INT_MAX;
vector<vector<int> > maps;
queue<p> q;
bool visited[100][100] ={0,};
void bfs(){
    while(!q.empty()){
        auto a = q.front(); q.pop();
        int y = a.first.first, x = a.first.second, cnt = a.second;
        if(visited[y][x]) continue;
        visited[y][x] = true;
        for(int d=0; d<4; d++){
            int ny = y+dy[d], nx = x+dx[d];
            if(ny <0 || ny >=n || nx<0 || nx >=m) continue;
            if(ny == n-1 && nx == m-1) answer = min(answer,cnt+1);
            if(maps[ny][nx] ==1){
                // cout << ny << " " << nx <<endl;
                q.push({{ny,nx},cnt+1});
            }
        }
    }
}
int solution(vector<vector<int> > ma)
{
    maps =ma;
    n = ma.size(), m = ma[0].size(); 
    q.push({{0,0},1});
    bfs();
    if(answer == INT_MAX) return -1;
    return answer;
}