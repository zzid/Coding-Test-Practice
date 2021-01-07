#include <bits/stdc++.h>
using namespace std;
const int dy[4] ={1,-1,0,0}, dx[4] ={0,0,-1,1};
int n,m,p;
int arr[300][300];
typedef struct po{
    int y,x,cnt;
};
typedef pair<int, int> pii;
vector<pii> ice;
void parts(pii idx, bool visited[300][300]){
    queue<pii> q;
    q.push(idx);
    visited[idx.first][idx.second] = 1;
    while(!q.empty()){
        auto yx = q.front(); q.pop();
        int y = yx.first, x = yx.second;
        for(int i=0; i<4; i++){
            int ny = y+ dy[i], nx = x +dx[i];
            if(ny >= n-1 || ny <1 || nx >=m-1 ||nx <1) continue;
            if(visited[ny][nx]) continue;
            if(arr[ny][nx] != 0){
                q.push({ny,nx});
                visited[ny][nx] = 1;
            }
        }
    }

}
void resolve(){
    vector<po> lis;
    for(auto x : ice){
        int i = x.first, j = x.second;
        int cnt =0;
        for(int d=0; d<4; d++){
            int ny = i + dy[d], nx = j +dx[d];
            if(ny >= n || ny <0 || nx >=m ||nx <0) continue;
            if(arr[ny][nx] ==0) cnt++;
        }
        lis.push_back({i,j,cnt});
    }
    ice.clear();
    for(auto a : lis){
        arr[a.y][a.x] -= a.cnt;
        if(arr[a.y][a.x] < 0) arr[a.y][a.x] = 0;
        else if(arr[a.y][a.x] > 0) ice.push_back({a.y,a.x});
    }
}
int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
            if(arr[i][j] != 0) ice.push_back({i,j});
        }
    }
    int step = 0;
    while(1){
        step++;
        p =0;
        resolve();
        if(ice.size() == 0){
            cout << 0 <<endl;
            return 0;
        }
        
        bool visited[300][300]= {0,};
        for(auto x : ice){
            int i = x.first, j = x.second;
            if(visited[i][j]) continue;
            if(p > 0){
                cout << step <<endl;
                return 0;
            }
            parts({i,j},visited);
            p++;
        }
    }
    return 0;
}
