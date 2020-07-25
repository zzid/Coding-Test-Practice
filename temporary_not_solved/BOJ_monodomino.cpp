#include <bits/stdc++.h>
using namespace std;
int n, score = 0;
int arr[10][10] = {0,};
// 0~3  | 4~5 | 6~9

int push_to_blue(int y){
    for(int x=4; x<10; x++){
        if(arr[y][x] == 0){
            return x;
        }
    }
}
int push_to_green(int x){
    for(int y=4; y<10; y++){
        if(arr[y][x]){
            return y;
        }
    }
}

void push(int y, int x, int cat){
    if(cat == 1){

    }else if(cat == 2){

    }else{

    }
    int temp_x = push_to_blue(y);
    arr[y][temp_x] = 1;
    int temp_y = push_to_green(x);
    arr[temp_y][x] = 1;
}

//Done
bool blue_arrange(){
    bool flag = false;
    for(int y=0; y<4; y++){
        int cnt =0;
        for(int x=4; x<10; x++){
            if(arr[y][x] == 1){
                cnt++;
                flag = true;
                arr[y][x] = 0;
            }
        }
        for(int x=9; x>9-cnt; x--){
            arr[y][x] = 1;
        }
    }
    return flag;
}
bool green_arrange(){
    bool flag = false;
    for(int x=0; x<4; x++){
        int cnt =0;
        for(int y=4; y<10; y++){
            if(arr[y][x] == 1){
                cnt++;
                flag = true;
                arr[y][x] = 0;
            }
        }
        for(int y=9; y>9-cnt; y--){
            arr[y][x] = 1;
        }
    }
    return flag;
}
void blue_check(){
    bool go = true;
    while(go){
        vector<int> candi;
        for(int x=9; x>=6; x--){
            bool flag = false;
            for(int y=0; y<4; y++){
                if(arr[y][x] == 0){
                    flag= true;
                    break;
                }
            }
            if(!flag) candi.push_back(x);
        }
        for(auto i : candi){
            score++;
            for(int y=0; y<4; y++){
                arr[y][i] = 0;
            }
        }
        go = blue_arrange();
    }
}
void green_check(){
    bool go = true;
    while(go){
        vector<int> candi;
        for(int y=9; y>=6; y--){
            bool flag = false;
            for(int x=0; x<4; x++){
                if(arr[y][x] == 0){
                    flag= true;
                    break;
                }
            }
            if(!flag) candi.push_back(y);
        }
        for(auto i : candi){
            score++;
            for(int x=0; x<4; x++){
                arr[i][x] = 0;
            }
        }
        go = green_arrange();
    }
}

void check(){
    blue_check();
    green_check();
}
//Done_end

int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        // 1. push till the end line
        // (opt) 2. delete the row or col  >> score++
        // >> push again
        // (opt) 2. 4~5 exist check
        // >> push again
        int a, y, x;
        scanf("%d %d %d", &a, &y, &x);
        push(y,x,a);
        check();
    }
    int cnt =0;
    for(int y=0; y<10; y++){
        for(int x=0; x<10; x++){
            if(arr[y][x]) cnt++;
        }
    }
    printf("%d\n%d", score, cnt);
    return 0;
}