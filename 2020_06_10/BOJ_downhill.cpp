// https://www.acmicpc.net/problem/1520
#include <bits/stdc++.h>
using namespace std;
int way[500][500]={0,};
int m[500][500];
const int dy[4] = {-1,1,0,0};
const int dx[4] = {0,0,-1,1};
int y,x;
int solution(int a, int b){
    if(a == y-1 && b == x-1) return 1;
    if(way[a][b] != -1) return way[a][b];
    way[a][b] = 0;
    for(int i=0; i<4; i++){
        int ny = a + dy[i], nx = b+ dx[i];
        if(ny>=y || ny <0 || nx >=x || nx <0) continue;
        if(m[a][b] > m[ny][nx]){
            way[a][b] += solution(ny,nx);
        }
    }
    return way[a][b];
}
int main(){
    scanf("%d %d", &y,&x);
    for(int i=0; i<y; i++)
        for(int j=0; j<x; j++){
            scanf("%d", &m[i][j]);
            way[i][j] = -1;
        }
    printf("%d",solution(0,0));
    return 0;
}
