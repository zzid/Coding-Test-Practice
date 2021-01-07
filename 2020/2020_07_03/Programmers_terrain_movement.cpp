#include <bits/stdc++.h>

using namespace std;
int n,height, num=1;
typedef pair<int, int> p;
vector<vector<int>> land;
const int dy[4] = {1,-1,0,0};
const int dx[4] = {0,0,-1,1};
int visited[300][300] ={0,};
int parent[90001] = {0,};
bool check;
map<p, int> m;
typedef struct kruskal {
    int from;
    int to;
    int val;
}KS;
struct comp{
    bool operator()(KS &a, KS &b){
        return a.val > b.val;
    }
};
int find(int a){
    if(a == parent[a]) return a;
    return parent[a] = find(parent[a]);
}

void Union(int a, int b){
    check = false;
    a = find(a);
    b = find(b);
    
    if(a == b) return ;
    parent[a] = b;
    check = true;
}

void dfs(p idx){
    int y = idx.first, x = idx.second;
    if(visited[y][x] >0) return;
    visited[y][x] = num;
    for(int i=0; i<4; i++){
        int ny = y + dy[i], nx = x + dx[i];
        if(ny <0 || ny >=n || nx < 0 || nx >=n) continue;
        if(abs(land[ny][nx] - land[y][x]) <= height) dfs({ny,nx});
    }
}

int solution(vector<vector<int>> l, int h) {
    int answer = 0;
    land = l, height = h;
    n = land.size();
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(visited[i][j] == 0){
                dfs({i,j});
                num++;
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j =0; j<n; j++){
            for(int dir=0; dir<4; dir++){
                int ni = i + dy[dir], nj = j + dx[dir];
                if(ni <0 || ni >=n || nj <0 || nj >=n) continue;
                if(visited[i][j] != visited[ni][nj]){
                    int a = visited[i][j], b = visited[ni][nj];
                    m.insert({{a,b},INT_MAX});
                    int temp = abs(land[i][j] - land[ni][nj]);
                    if(m[{a,b}] > temp) m[{a,b}] = temp;
                }
            }
        }
    }
    priority_queue <KS, vector<KS>, comp> pq;
    int cnt =0;
    for(int i=1; i<=num; i++) parent[i] = i;
    for(auto it = m.begin(); it!= m.end(); it++){
        int i =it->first.first, j = it->first.second, val = it->second;
        KS a;
        a.from = i, a.to = j, a.val = val;
        pq.push(a);
        cnt++;
    }
    for(int i=0; i<cnt; i++){
        KS a = pq.top(); pq.pop();
        Union(a.from, a.to);
        if(check) answer += a.val;
    }

    return answer;
}