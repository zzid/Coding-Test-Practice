#include <bits/stdc++.h>
using namespace std;
const int dy[4] = {1,-1,0,0}, dx[4] = {0,0,1,-1};
int arr[101][101];
bool v[101][101];
int h,w,o,f,xs,ys,xe,ye;
bool result = false;

typedef struct{
    int y; int x; int p;
} data;
void bfs(int y, int x, int p){
    queue<data> q;
    q.push({y,x,p});
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        int y= cur.y, x = cur.x, p = cur.p;
        if(v[y][x]) continue;
        v[y][x] =1;
//        || (abs(ye-y)+ abs(xe-x)) > p
        if(p <=0 ) continue;
        if(y == ye && x == xe){
            result = 1;
            return;
        }
//        cout<< y << " " << x <<endl;
        for(int i=0; i<4; i++){
            int ny = y+dy[i], nx = x+dx[i];
            if(ny<1 || ny> h || nx<1 || nx>w) continue;
            if(arr[ny][nx] - arr[y][x] > p) continue;
            q.push({ny,nx,p-1});
        }
    }
}
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        for(int i=1; i<=h; i++){
            for(int j=1; j<=w; j++){
                arr[i][j] =0;
                v[i][j] =0;
            }
        }
        result = 0;
        scanf("%d %d %d %d %d %d %d %d",&h, &w, &o, &f, &ys, &xs, &ye, &xe);
        for(int i=0; i<o; i++){
            int y,x,l;
            scanf("%d %d %d", &y, &x, &l);
            arr[y][x] = l;
        }
        bfs(ys,xs,f);
        string str = result ? "잘했어!!" : "인성 문제있어??";
        cout << str <<endl;
    }
    return 0;
}
