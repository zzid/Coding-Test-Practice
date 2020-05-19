#include <bits/stdc++.h>

using namespace std;
//int dest[11] ={0,};
bool ladder[11][31] ={0,};
int n, m, h;

// void dfs(int org, int cur, int level){
//     if(level > h){ // end condition
//         dest[org] = cur;
//         return;
//     }

//     if(ladder[cur][level] ==1 && cur<n){
//         dfs(org, cur+1, level+1);
//     }else if(ladder[cur-1][level] == 1 && cur >1){
//         dfs(org, cur-1, level+1);
//     }else dfs(org, cur, level+1);
// }

bool destChk(){
    for(int i=1; i<=n; i++){
        int cur = i;
        for(int j=1; j<=h; j++){
            if(ladder[cur][j] == 1 && cur <n) cur++;
            else if(ladder[cur-1][j] == 1 && cur >1) cur--;
        }
        if(cur != i) return false;
    }
    return true;
}
bool isAvail(int a, int b){
    if(ladder[a][b] == 1) return false;
    if(a <n && ladder[a+1][b] ==1) return false;
    if(a >1 && ladder[a-1][b] ==1) return false;

    return true;
}
// bool destChk(){
//     // for(int i=1; i<=n; i++) dfs(i,i,1);
//     for(int i=1; i<=n; i++) makeDest();
//     for(int i=1; i<=n; i++){
//         if(dest[i] != i) return false;
//     }
//     return true;
// }
bool Add1(){
        /* add 1 */
    for(int i=1; i<=n; i++){
        for(int j=1; j<=h; j++){
            if(!isAvail(i,j)) continue;
            ladder[i][j] =1;
            if(destChk()) return true;
            ladder[i][j] = 0;
        }
    }
    return false;
}

bool Add2(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=h; j++){
            if(!isAvail(i,j)) continue;
            ladder[i][j] = 1;

            for(int a = i; a<=n; a++){
                for(int b= 1; b<=h; b++){
                    if(!isAvail(a,b)) continue;
                    ladder[a][b] = 1;
                    if(destChk()) return true;
                    ladder[a][b] = 0;
                }
            }
            ladder[i][j] = 0;
        }
    }
    return false;
}

bool Add3(){
    for(int x=1; x<=n; x++){
        for(int y=1; y<=h; y++){
            if(!isAvail(x,y)) continue;
            ladder[x][y] =1;

            for(int i=x; i<=n; i++){
                for(int j=1; j<=h; j++){
                    if(!isAvail(i,j)) continue;
                    ladder[i][j] = 1;

                    for(int a = i; a<=n; a++){
                        for(int b= 1; b<=h; b++){
                            if(!isAvail(a,b)) continue;
                            ladder[a][b] = 1;
                            if(destChk()) return true;
                            ladder[a][b] = 0;
//    cout << x << "," << y << " " << i << "," << j << " " <<  a << "," << b << endl;
                        }
                    }
                    ladder[i][j] = 0;
                }
            }
            ladder[x][y] = 0;
        }
    }
    return false;
}
int main(){
    scanf("%d %d %d", &n,&m,&h); // 가로 n, 세로 h, 주어지는사다리 m개
    //for(int i=1; i<=n; i++) dest[i] = i;
    for(int i=0; i<m; i++){
        int a, b;  // (a)th dot line, b & b+1 linked
        scanf("%d %d", &a, &b);
        ladder[b][a] = 1;
    }/* ladder[n][h] */

    //init
    if(destChk()){ printf("%d\n", 0); return 0; }


    if(Add1()){
        printf("%d\n", 1);
        return 0;
    }
    if(Add2()){
        printf("%d\n", 2);
        return 0;
    }
    if(Add3()){
        printf("%d\n", 3);
        return 0;
    }
    else{
        printf("%d\n", -1);
        return 0;
    }
    // printf("%d\n", -1);
    return 0;
}
