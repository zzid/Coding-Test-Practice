#include <bits/stdc++.h>
using namespace std;
typedef pair <int, int> p;
int inp[10], answer = INT_MIN;

int maps[6][22]={
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,-1},
    {10,13,16,19,25,30,35,40,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    {20,22,24,25,30,35,40,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    {30,28,27,26,25,30,35,40,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    {25,30,35,40,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}};

bool onChk(p x, vector<p> h){ // return true if exist >> can't go
    int a = x.first, b = x.second;
    if(a == 0) return false;
    for(int i=0; i<4; i++){
        p t = h[i];
        if(t.first == a && t.second == b) return true;
    }
    return false;
}
p mov(int x, int y){
    if(x==0) return {0,0};
    if(x ==1 && y % 5 == 0){
        if(y/5 <=3){
            x += y / 5;
            y=0;
        }else return {5,3};
    }else if(x ==1 && y>=21) return {0,0};

    if( ( x==2 || x== 4 ) && y>=4 ){x= 5; y = y-4;}
    else if(x==3 && y>=3 ){x= 5;y= y-3;}

    if(maps[x][y] == -1 ) return {0,0};

    return {x,y};
}
void dfs(int idx, int val, vector<p> h){
    if(idx > 9){
        answer = max(answer, val);
        return;
    }
    for(int i=0; i<4; i++){
        vector<p> nh(4);
        nh.assign(h.begin(), h.end());
        p x = nh[i];
        if(x.first == 0) continue;
        p t= mov(x.first, x.second+ inp[idx]);

        if(!onChk(t,nh)){
            nh[i] = t;
            dfs(idx+1, val + maps[t.first][t.second], nh);
        }
        else continue;

    }

}
int main(){
    for(int i=0; i<10; i++) cin >> inp[i];

    vector<p> horse(4, {1,0});
    dfs(0,0, horse);
    cout << answer <<endl;

    return 0;
}