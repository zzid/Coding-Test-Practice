// https://www.acmicpc.net/problem/2096
#include <bits/stdc++.h>
using namespace std;
int n;
int m[100000][3];
int b_dpn[3];
int dpn[3]; //min
int b_dpx[3];
int dpx[3]; //max
const int dx[3] = {-1,0,1};
int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d %d %d", &m[i][0],&m[i][1],&m[i][2]);
    }
    for(int i=0; i<3; i++){
        b_dpn[i] = m[0][i];
        dpn[i] = INT_MAX;
        b_dpx[i] = m[0][i];
        dpx[i] = -1;
    }

    for(int i=1; i<n; i++){
        for(int j=0; j<3; j++){
            for(int d=0; d<3; d++){
                int nx = j + dx[d];
                if(nx <0 || nx >2) continue;
                dpx[j] = max(b_dpx[nx] +m[i][j], dpx[j]);
                dpn[j] = min(b_dpn[nx] +m[i][j], dpn[j]);
            }
        }
        for(int j=0; j<3; j++){
            b_dpn[j] = dpn[j];
            dpn[j] = INT_MAX;
            b_dpx[j] = dpx[j];
            dpx[j] = -1;
        }
    }
    int t_max= INT_MIN, t_min = INT_MAX;
    for(int i=0; i<3; i++){
        t_max = t_max <= b_dpx[i] ? b_dpx[i] : t_max;
        t_min = t_min >= b_dpn[i] ? b_dpn[i] : t_min;
    }
    printf("%d %d", t_max,t_min);
    return 0;
}
