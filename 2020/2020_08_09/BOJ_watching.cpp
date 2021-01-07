#include <bits/stdc++.h>

using namespace std;
#define For(a,b,i) for(int i=a; i<b; i++)
typedef pair<int, int> p;
const int dy[4] = {-1,1,0,0};
const int dx[4] = {0,0,-1,1};
int n,m,answer=INT_MAX;
int og[8][8];
vector<p> cams;
void zeros(int maps[8][8]){
    int temp =0;
    For(0,n,i) For(0,m,j) if(maps[i][j] == 0) temp++;
    answer = min(answer, temp);
}

void marking(int maps[8][8], p a, int i){
    p c = a;
    while(1){
        int ny = c.first+dy[i], nx = c.second+dx[i];
        if(ny >= n || ny<0 || nx >=m || nx<0) break;
        if(maps[ny][nx] == 6) break;
        if(maps[ny][nx] == 0) maps[ny][nx] = -1;
        c.first = ny, c.second = nx;
    }
}

void input(){
    cin >> n >> m;
    For(0,n,i){
        For(0,m,j){
            cin >> og[i][j];
            if(og[i][j] != 0 && og[i][j] != 6){
                cams.push_back({i,j});
            }
        }
    }
}
void dfs(int copied[8][8], int i){
    if(i == cams.size()){
        zeros(copied);
        return;
    }
    p q = cams[i];
    int cat = og[q.first][q.second];
    if(cat == 1){ // 4 cases
        int next[8][8];
        copy(&copied[0][0], &copied[0][0]+(8*8), &next[0][0]);
        marking(next,q,0);
        dfs(next,i+1);

        int next2[8][8];
        copy(&copied[0][0], &copied[0][0]+(8*8), &next2[0][0]);
        marking(next2,q,1);
        dfs(next2,i+1);

        int next3[8][8];
        copy(&copied[0][0], &copied[0][0]+(8*8), &next3[0][0]);
        marking(next3,q,2);
        dfs(next3,i+1);

        int next4[8][8];
        copy(&copied[0][0], &copied[0][0]+(8*8), &next4[0][0]);
        marking(next4,q,3);
        dfs(next4,i+1);
    }
    else if(cat == 2){ // 2 cases
        int next[8][8];
        copy(&copied[0][0], &copied[0][0]+(8*8), &next[0][0]);
        marking(next,q,0); marking(next,q,1);
        dfs(next,i+1);

        int next2[8][8];
        copy(&copied[0][0], &copied[0][0]+(8*8), &next2[0][0]);
        marking(next2,q,2); marking(next2,q,3);
        dfs(next2,i+1);
    }else if(cat == 3){ // 4 casses
        int next[8][8];
        copy(&copied[0][0], &copied[0][0]+(8*8), &next[0][0]);
        marking(next,q,0); marking(next,q,3);
        dfs(next,i+1);

        int next2[8][8];
        copy(&copied[0][0], &copied[0][0]+(8*8), &next2[0][0]);
        marking(next2,q,1); marking(next2,q,3);
        dfs(next2,i+1);

        int next3[8][8];
        copy(&copied[0][0], &copied[0][0]+(8*8), &next3[0][0]);
        marking(next3,q,1); marking(next3,q,2);
        dfs(next3,i+1);

        int next4[8][8];
        copy(&copied[0][0], &copied[0][0]+(8*8), &next4[0][0]);
        marking(next4,q,0); marking(next4,q,2);
        dfs(next4,i+1);
    }else if(cat == 4){ // 4 casses
        int next[8][8];
        copy(&copied[0][0], &copied[0][0]+(8*8), &next[0][0]);
        marking(next,q,0); marking(next,q,2); marking(next,q,3);
        dfs(next,i+1);

        int next2[8][8];
        copy(&copied[0][0], &copied[0][0]+(8*8), &next2[0][0]);
        marking(next2,q,1); marking(next2,q,2); marking(next2,q,3);
        dfs(next2,i+1);

        int next3[8][8];
        copy(&copied[0][0], &copied[0][0]+(8*8), &next3[0][0]);
        marking(next3,q,0); marking(next3,q,1); marking(next3,q,2);
        dfs(next3,i+1);

        int next4[8][8];
        copy(&copied[0][0], &copied[0][0]+(8*8), &next4[0][0]);
        marking(next4,q,0); marking(next4,q,1); marking(next4,q,3);
        dfs(next4,i+1);
    }else if(cat == 5){
        For(0,4,i) marking(copied, q, i);
        dfs(copied,i+1);
    }
}
void solve(){
    dfs(og, 0);
    cout << answer <<endl;

}
int main(){
    input();
    solve();
    return 0;
}
