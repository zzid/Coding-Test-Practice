#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> brd;
int n;
int rect1[3][2][3] ={
    {{1,-1,-1},
     {1,1,1}},
    {{-1,1,-1},
     {1,1,1}},
    {{-1,-1,1},
     {1,1,1}},
};
int rect2[2][3][2]={
    {{-1,1},
     {-1,1},
     {1,1}},
    {{1,-1},
     {1,-1},
     {1,1}},

};
bool check1(int y, int x, int c){
    int val = -100;
    for(int i=0; i<2; i++){
        for(int j=0; j<3; j++){
            if(x+j >= n || y+i >= n) return false;
            if(rect1[c][i][j] == -1){
                if(brd[y+i][x+j] != -1) return false;
            }else{
                if(brd[y+i][x+j] <= 0) return false;
                if(val == -100) val = brd[y+i][x+j];
                else{
                    if(val != brd[y+i][x+j]) return false;
                }
            }
        }
    }
    for(int i=0; i<2; i++){
        for(int j=0; j<3; j++){
            brd[y+i][x+j] = 0;       
        }
    }
    return true;
}
bool check2(int y, int x, int c){
    int val= -100;
    for(int i=0; i<3; i++){
        for(int j=0; j<2; j++){
            if(x+j >= n || y+i >= n) return false;
            if(rect2[c][i][j] == -1){
                if(brd[y+i][x+j] != -1) return false;
            }else{
                if(brd[y+i][x+j] <= 0) return false;
                if(val == -100) val = brd[y+i][x+j];
                else{
                    if(val != brd[y+i][x+j]) return false;
                }
            }
        }
    }
    for(int i=0; i<3; i++){
        for(int j=0; j<2; j++){
            brd[y+i][x+j] = 0;       
        }
    }
    return true;
}
int solution(vector<vector<int>> board) {
    int answer = 0;
    n = board.size();
    brd = board;
    for(int i=0; i<200; i++){
        bool change = false;
        for(int x=0; x<n; x++){
            for(int y =0; y<n; y++){
                if(brd[y][x] == 0 || brd[y][x] == -1) brd[y][x] = -1;
                else break;
            }
        }
        for(int y=0; y<n; y++){
            for(int x=0; x<n; x++){
                for(int c=0; c<3; c++){
                    if(check1(y,x,c)){
                        answer++; change = true; break;
                    }
                }
                for(int c=0; c<2; c++){
                    if(check2(y,x,c)){
                        answer++; change = true; break;
                    }
                }
                if(change) break;
            }
            if(change) break;
        }
        if(!change) break;
    }
    return answer;
}