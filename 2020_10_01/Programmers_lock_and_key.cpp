#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>>  vv;
vv l;
int ks,ls,nh=0;
vv rot(vv arr){
    vv temp = arr;
    for(int i=0; i<ks; i++){
        for(int j=0;j<ks; j++){
            temp[j][ks- i -1] = arr[i][j];
        }
    }
    return temp ;
}

bool findkey(int y, int x, vv key){
    int temp =0;
    for(int i=0; i<ks; i++){
        for(int j=0; j<ks; j++){
            if(y+i < ls && y+i >=0&& x+j < ls&& x+j>=0){
                if(l[y+i][x+j] == 1 &&  key[i][j] == 1){
                    temp++;
                }else if(l[y+i][x+j] == 0 &&  key[i][j] == 1){
                    return false;
                }
            }
        }
    }
    if(temp == nh) return true;
    else return false;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    l = lock;
    ks = key.size();
    ls = lock.size();
    for(int i=0; i<ls; i++){
        for(int j=0; j<ls; j++){
            if(l[i][j] == 1) l[i][j] =0;
            else if(l[i][j] == 0){
                l[i][j] =1;
                nh++;
            }
        }
    }
    vv t = key;
    for(int k=0; k<4; k++){
        t = rot(t);
        for(int i=-(ks-1); i<ls; i++){
            for(int j=-(ks-1); j<ls; j++){
                if(findkey(i,j,t)){
                    return true;
                }
            }
        }
    }
    return false;
}