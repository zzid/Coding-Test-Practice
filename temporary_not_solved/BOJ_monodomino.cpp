#include <bits/stdc++.h>
using namespace std;
int n, score = 0;
int arr[10][10] = {0,};
// 0~3  | 4~5 | 6~9

int push_to_blue(int y){
    for(int x=4; x<10; x++){
        if(arr[y][x]){
            return x-1;
        }
    }
    return 9;
}
int push_to_green(int x){
    for(int y=4; y<10; y++){
        if(arr[y][x]){
            return y-1;
        }
    }
    return 9;
}

void push(int y, int x, int cat){
    if(cat == 1){
        int temp_x = push_to_blue(y);
        arr[y][temp_x] = 1;
        int temp_y = push_to_green(x);
        arr[temp_y][x] = 1;
    }else if(cat == 2){
        int temp_x = push_to_blue(y);
        arr[y][temp_x] = arr[y][temp_x-1] = 1; // need to check
        int temp_y = min(push_to_green(x), push_to_green(x+1));
        arr[temp_y][x] = arr[temp_y][x+1] = 1;
        
    }else{
        int temp_x = min(push_to_blue(y),push_to_blue(y+1));
        arr[y][temp_x] = arr[y+1][temp_x] = 1;
        int temp_y = push_to_green(x);
        arr[temp_y][x] = arr[temp_y-1][x] = 1;
    }

}

// Need to modify (arrange)
// >> block based
void blue_arrange(int size, int minv){
    for(int x=minv; x>=4-size; x--){
        for(int y=0; y<4; y++){
            arr[y][x] = arr[y][x-minv];
        }
    }
    for(int y=0; y<4; y++){
        int cnt =0;
        for(int x=9; x>=6; x--){
            if(arr[y][x] == 1){

                break;
            }
            cnt++;
        }
        if(cnt){
            int mvcnt=0;
            for(int x=9-cnt; x>=6; x--){
                if(arr[y][x] == 1){
                    if(arr[y+1][x] == 1 || arr[y-1][x] == 1){
                        break;
                    }
                    mvcnt++;
                }
            }
            if(mvcnt){
                for(int x=9; x>6-mvcnt; x--){
                    arr[y][x] = arr[y][x-mvcnt];
                }
            }
        }
    }
}

void green_arrange(int size, int minv){
    for(int y=minv; y>=4-size; y--){
        for(int x=0; x<4; x++){
            arr[y][x] = arr[y-minv][x];
        }
    }
    for(int x=0; x<4; x++){
        int cnt =0;
        for(int y=9; y>=6; y--){
            if(arr[y][x] == 1){

                break;
            }
            cnt++;
        }
        if(cnt){
            int mvcnt=0;
            for(int y=9-cnt; y>=6; y--){
                if(arr[y][x] == 1){
                    if(arr[y][x+1] == 1 || arr[y][x-1] == 1){
                        break;
                    }
                    mvcnt++;
                }
            }
            if(mvcnt){
                for(int y=9; y>6-mvcnt; y--){
                    arr[y][x] = arr[y-mvcnt][x];
                }
            }
        }
    }
}

void blue_check(){
    bool go = true;
    int isChange = 0;

    for(int x=5; x>=4; x--){
        for(int y=0; y<4; y++){
            if(arr[y][x] != 0){
                // erase
                isChange++;
                for(int ny=0; ny<4; ny++){
                    arr[ny][x+4] = 0;
                }
                break;
            }
        }
    }
    while(isChange--){
        for(int y=0; y<4; y++){
            for(int x =9; x>=4; x--){
                arr[y][x] = arr[y][x-1];
            }
        }
    }

    while(go){
        go = 0;
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
        int min_v = 50;
        for(auto i : candi){
            min_v = min(i,min_v);
            go = 1;
            score++;
            for(int y=0; y<4; y++){
                arr[y][i] = 0;
            }
        }
        if(go) blue_arrange(candi.size(), min_v);
    }
}
void green_check(){
    bool go = true;
    int isChange =0;
    for(int y=5; y>=4; y--){
        for(int x=0; x<4; x++){
            if(arr[y][x] != 0){
                // erase
                isChange++;
                for(int nx=0; nx<4; nx++){
                    arr[y+4][nx] = 0;
                }
                break;
            }
        }
    }
    while(isChange--){
        for(int x=0; x<4; x++){
            for(int y =9; y>=4; y--){
                arr[y][x] = arr[y-1][x];
            }
        }
    }
    while(go){
        go =0;
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
            go = 1;
            score++;
            for(int x=0; x<4; x++){
                arr[i][x] = 0;
            }
        }
        if(go) green_arrange();
    }
}

void check(){
    blue_check();
    green_check();
}
//Done_end

void prt(){
    cout <<endl;
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            cout << arr[i][j] << ' ';
        }
        cout <<endl;
    }
}
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
        // prt();
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