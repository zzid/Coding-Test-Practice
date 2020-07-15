#include <bits/stdc++.h>
using namespace std;
int n, m, fuel, y, x, answer;
int arr[21][21];
const int dy[4] = {1,-1,0,0}, dx[4] = {0,0,-1,1};
typedef pair<int, int> p;
typedef struct idx{
    int y,x,val;
}idx;
typedef struct yx{
    int y,x;
}yx;
vector<yx> start, dest;

bool comp(p a, p b){
    if(a.second == b.second){
        if(start[a.first].y == start[b.first].y){
            return start[a.first].x < start[b.first].x;
        }
        return start[a.first].y < start[b.first].y;
    }
    return a.second < b.second;
}

int path(p from, p to){
    queue<idx> q;
    bool visited[21][21]={0,};
    q.push({from.first, from.second, 0});
    visited[from.first][from.second] = 1;
    while(!q.empty()){
        auto a = q.front(); q.pop();
        int y_ = a.y, x_ = a.x, val = a.val;
        if(y_ == to.first && x_ == to.second){
            return val;
        }
        for(int i=0; i<4; i++){
            int ny = y_ + dy[i], nx = x_ + dx[i];
            if(ny <= 0 || ny > n || nx <=0 || nx > n) continue;
            if(arr[ny][nx] == 1 || visited[ny][nx]) continue;
            visited[ny][nx] = 1;
            q.push({ny,nx,val+1});
        }
    }
    return -1;
}
int main(){
    cin >> n >> m >> fuel;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> arr[i][j];
        }
    }
    cin >> y >> x;
    for(int i=0; i<m; i++){
        yx temp1, temp2;
        cin >> temp1.y >> temp1.x >> temp2.y >> temp2.x;
        start.push_back(temp1);
        dest.push_back(temp2);
    }

    bool visit[400] = {0,};
    vector<p> dist;
    for(int a=0; a<m; a++){
        dist.clear();
        for(int i=0; i<m; i++){
            int temp;
            if(visit[i]) continue;
            else{
                temp = path({y,x}, {start[i].y, start[i].x});
                if(temp == -1){
                    cout << -1 <<endl;
                    return 0;
                }
            }
            dist.push_back({i, temp});
        }
        sort(dist.begin(), dist.end(), comp);
        int id = dist[0].first;
        visit[id] = 1;
        fuel -= dist[0].second; // taking guest
        y = start[id].y, x = start[id].x;
        if(fuel < 0){
            answer = -1;
            break;
        }
        int temp = path({y,x}, {dest[id].y, dest[id].x});
        y = dest[id].y, x = dest[id].x;
        fuel -= temp;
        if(fuel < 0){
            answer = -1;
            break;
        }
        fuel += (temp *2);
    }

    answer = answer == -1 ? -1 : fuel;
    cout << answer << '\n';
    return 0;
}
