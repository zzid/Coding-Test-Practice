#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> arr;
const int dy[4] = {-1,0,1,0}, dx[4] = {0,-1,0,1};
int answer = 987654321,n;
class idx{
public:
    int y,x,d,cost;
    idx(int y, int x, int d, int cost){
        this->y = y;
        this->x = x;
        this->d = d;
        this->cost = cost;
    }
};
void bfs(int y, int x, int d, int cost){
    deque<idx> q;
    q.push_back(idx(y,x,d,cost));
    arr[y][x] = 1;
    while(!q.empty()){
        idx index = q.front(); q.pop_front();
        int y = index.y, x= index.x, d = index.d, cost = index.cost;
        
        if(y == n-1 && x == n-1){
            answer = min(answer,cost);
            continue;
        }
        
        for(int i=0; i<4; i++){
            int ny = y + dy[i], nx = x + dx[i];
            if(ny < 0 || ny >=n || nx < 0 || nx >=n) continue;
            if(arr[ny][nx] == 1) continue;
            int c;
            if(d == i || d == -1) c = 100;
            else c = 600;
            
            if(arr[ny][nx] == 0){
                arr[ny][nx] = cost+c;
                q.push_back(idx(ny,nx,i,cost+c));
            }
            else if(arr[ny][nx] >= cost+c){
                arr[ny][nx] = cost+c;
                q.push_back(idx(ny,nx,i,cost+c));
            }
        }
    }
}
int solution(vector<vector<int>> board) {
    n = board.size();
    arr = board;
    bfs(0,0,-1,0);
    return answer;
}