#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> p;
int gear[4][8];
vector<p> rotation; // 1 : clock wise, -1 : counter CW
int k, answer=0;

void rot(int num, int dir){
    if(dir == 1){
        int temp = gear[num][7];
        for(int i=6; i>=0; i--){
            gear[num][i+1] = gear[num][i];
        }
        gear[num][0] = temp;
    }else if (dir == -1){
        int temp = gear[num][0];
        for(int i=1; i<8; i++){
            gear[num][i-1] = gear[num][i];
        }
        gear[num][7] = temp;
    }
}
void solve(){
    for(int i=0; i<k; i++){
        int num = rotation[i].first-1, dir = rotation[i].second;
        int dirs[4]={0,};
        dirs[num] = dir;
        if(num == 0){
            for(int a=0; a<3; a++){
                if(gear[a][2] == gear[a+1][6]) break;
                else dirs[a+1] = dir * pow(-1,a+1);
            }
        }else if(num == 1){
            if(gear[0][2] != gear[1][6]) dirs[0] = (-1) * dir;
            if(gear[1][2] != gear[2][6]){
                dirs[2] = (-1) * dir;
                if(gear[2][2] != gear[3][6]) dirs[3] = dir;
            }
        }else if(num == 2){
            if(gear[3][6] != gear[2][2]) dirs[3] =  (-1) * dir;
            if(gear[2][6] != gear[1][2]){
                dirs[1] = (-1) * dir;
                if(gear[0][2] != gear[1][6]) dirs[0] = dir;
            }
        }else{
            for(int a=3; a>=0; a--){
                if(gear[a][6] == gear[a-1][2]) break;
                else dirs[a-1] = dir * pow(-1,a+2);
            }
        }
        for(int a=0; a<4; a++) rot(a,dirs[a]);
    }
}
void sum(){
    for(int i=0; i<4; i++){
        if(gear[i][0] == 1) answer += (1 << i);
    }
    cout << answer<<endl;
}
void input(){
    // string a;
    for(int i=0; i<4; i++){
        // cin >> a;
        for(int j=0; j<8; j++){
            int a;
            scanf("%1d", &a);
            gear[i][j] = a;
        }
    }
    cin >> k;
    for(int i=0; i<k; i++){
        int x, y;
        cin >> x >>y;
        rotation.push_back({x,y});
    }
}
int main(){
    input();
    solve();
    sum();
    return 0;
}
