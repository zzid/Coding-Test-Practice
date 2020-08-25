#include <bits/stdc++.h>

using namespace std;
int maps[100][100];
bool lad1[100][100]; // horizontal
bool lad2[100][100]; // vertical
int n, l, answer=0;

int verify(int a, int b, string s){
    if(s.length() == 4){// down incline && hor
        int lim = b+l-1;
        if(lim >=n) return -1;
        int pivot = maps[a][b];
        bool flag =false;
        for(int i=b+1; i<b+l; i++){
            if(pivot != maps[a][i]) return -1;
        }
        for(int i=b; i<b+l; i++){
            if(lad1[a][i] == 1) return -1;
            lad1[a][i] = 1; // visited
        }
        return b+l-1;
    }
    else if(s.length() == 2){ // up incline && hor
        int lim = b-l;
        if(lim <0) return -1;
        int pivot = maps[a][b-1];
        bool flag = false;
        for(int i=b-2; i>=b-l; i--){
            if(pivot != maps[a][i]) return -1;
        }
        for(int i=b-1; i>=b-l; i--){
            if(lad1[a][i] == 1) return -1;
            lad1[a][i] =1;
        }
        return b;
    }
}
int verify2(int a, int b, string s){
    //cout << a <<endl;
    if(s.length() == 4){// down incline && ver
        int lim = a+l-1;
        if(lim >=n) return -1;
        int pivot = maps[a][b];
        bool flag =false;
        for(int i=a+1; i<a+l; i++){
            if(pivot != maps[i][b]) return -1;
        }
        for(int i=a; i<a+l; i++){
            if(lad2[i][b] == 1) return -1;
            lad2[i][b] = 1; // visited
        }

        return a+l-1;
    }
    else if(s.length() == 2){ // up incline && ver
        int lim = a-l;
        if(lim <0) return -1;
        int pivot = maps[a-1][b];
        bool flag = false;
        for(int i=a-2; i>=a-l; i--){
            if(pivot != maps[i][b]) return -1;
        }
        for(int i=a-1; i>=a-l; i--){
            if(lad2[i][b] == 1) return -1;
            lad2[i][b] =1;
        }
        return a;
    }


}
void sear(){
    for(int i=0; i<n; i++){
        int x = maps[i][0];
        bool flag = true;
        int j=1;

        while(j < n){// for(int j=1; j<n; j++){
            if(abs(maps[i][j] - maps[i][j-1])> 1){
                flag = false;
                break;
            }
            else if(x > maps[i][j]){ // down incline
                int ret = verify(i,j, "down");
                if(ret <0) {flag = false; break;}
                else{
                    j = ret;
                    x = maps[i][j];
                    continue;
                }
            }else if(x < maps[i][j] ){ // up incline
                int ret = verify(i,j, "up");
                if(ret <0) {flag = false; break;}
                else{
                    j = ret;
                    x = maps[i][j];
                    continue;
                }
            }
            j++;
        }
        if(flag)    answer++;
    }

    for(int j=0; j<n; j++){
        int x = maps[0][j];
        bool flag = true;
        int i=1;

        while(i < n){// for(int j=1; j<n; j++){
            if(abs(maps[i-1][j] - maps[i][j])> 1){
                flag = false;
                break;
            }
            else if(x > maps[i][j]){ // down incline
                int ret = verify2(i,j, "down");
                if(ret <0) {flag = false; break;}
                else{
                    i = ret;
                    x = maps[i][j];
                    continue;
                }
            }else if(x < maps[i][j] ){ // up incline
                int ret = verify2(i,j, "up");
                if(ret <0) {flag = false; break;}
                else{
                    i = ret;
                    x = maps[i][j];
                    continue;
                }
            }
            i++;
        }
        if(flag)    answer++;
    }
    cout << answer <<endl;
}
void input(){
    cin >> n >> l;
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) cin >>  maps[i][j];
}
int main(){
    input();
    sear();
    return 0;
}
