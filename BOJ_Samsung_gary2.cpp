#include <bits/stdc++.h>
using namespace std;

// int n =6;
// int pop[7][7] ={{0,0,0,0,0,0,0},
//                 {0,1,2,3,4,1,6},
//                 {0,7,8,9,1,4,2},
//                 {0,2,3,4,1,1,3},
//                 {0,6,6,6,6,9,4},
//                 {0,9,1,9,1,9,5},
//                 {0,1,1,1,1,9,9}};

int n;
int pop[21][21];
const int dy[4] = {1,1,-1,-1};
const int dx[4] = {-1,1,1,-1};
int maps[21][21];
int answer =INT_MAX;
int onev,twov,threev,fourv,fivev;

void calc(){
    for(int i=1; i<=n; i++){
        for(int j =1; j<=n; j++){
            int a = maps[i][j], b = pop[i][j];
            if(a == 1) onev += b;
            else if(a ==2) twov += b;
            else if(a ==3) threev +=b;
            else if(a==4) fourv +=b;
            else fivev +=b;
        }
    }
    vector<int> s;
    s.push_back(onev);
    s.push_back(twov);
    s.push_back(threev);
    s.push_back(fourv);
    s.push_back(fivev);
    sort(s.begin(), s.end());
    answer = min(answer, s[4]-s[0]);
}
void one(int y, int x){ //y+d1 , x
    for(int i=1; i<y; i++){
        for(int j=1; j<=x; j++){
            if(maps[i][j] == 5) break;
            maps[i][j] = 1;
        }
    }
}
void two(int y, int x){ // y+d2, x
    for(int i=1; i<=y; i++){
        for(int j=n; j>=x+1; j--){
            if(maps[i][j] == 5) break;
            maps[i][j] = 2;
        }
    }
}
void three(int y, int x){ // y+d1,x-d1+d2
    for(int i=y; i<=n; i++){
        for(int j=1; j<x; j++){
            if(maps[i][j] == 5) break;
            maps[i][j] =3;
        }
    }
}
void four(int y, int x){ // y+d2,x-d1+d2
    for(int i=y+1; i<=n; i++){
        for(int j=n; j>=x; j--){
            if(maps[i][j] == 5) break;
            maps[i][j] = 4;
        }
    }
}
void five(int y, int x, int d1, int d2){
    for(int i=1; i<=n; i++){for(int j =1; j<=n; j++){ maps[i][j] =0;}}
    maps[y][x] = 5;
    int ny =y, nx = x;
    while(1){
        ny += dy[0], nx += dx[0];
        maps[ny][nx] = 5;
        if(ny == y+d1 && nx == x-d1) break;
    }
    while(1){
        ny += dy[1], nx += dx[1];
        maps[ny][nx] = 5;
        if(ny == y+d1+d2 && nx == x-d1+d2) break;
    }
    while(1){
        ny += dy[2], nx += dx[2];
        maps[ny][nx] = 5;
        if(ny == y+d2 && nx == x+d2) break;
    }
    while(1){
        ny += dy[3], nx += dx[3];
        maps[ny][nx] = 5;
        if(ny == y && nx == x) break;
    }    
}
int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            scanf("%d", pop[i][j]);
        }
    }
    for(int d1=1; d1<=n; d1++){
        for(int d2=1; d2<=n; d2++){
            for(int y=1; y<=n; y++){ 
                for(int x=1; x<=n; x++){
                    if(y+d1+d2>n || x+d2 > n || x-d1 < 1) continue;
                    onev=0,twov=0,threev=0,fourv=0,fivev=0;
                    five(y,x,d1,d2);
                    one(y+d1,x); 
                    two(y+d2,x); 
                    three(y+d1,x-d1+d2); 
                    four(y+d2,x-d1+d2); 
                    calc();
                }
            }
        }
    }
    printf("%d\n", answer);
    return 0;
}