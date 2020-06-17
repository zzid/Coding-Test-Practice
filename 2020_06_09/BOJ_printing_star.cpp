// https://www.acmicpc.net/problem/2448
#include <bits/stdc++.h>
using namespace std;
#define max 6144
char m[max/2+1][max];
char star[3][5]=
{
    {' ',' ','*',' ',' '},
    {' ','*',' ','*',' '},
    {'*','*','*','*','*'}
};
void recur(int a, int b, int n){
    if(n == 1){
        for(int i=0; i<3; i++){
            for(int j=0; j<5; j++){
                m[a+i][b+j] = star[i][j];
            }
        }
        return;
    }
    recur(a + 3*n/2, b , n/2);
    recur(a + 3*n/2, b + 3*n , n/2);
    recur(a , b+ 3*n/2 , n/2);
}
int main(){
    int n;
    scanf("%d", &n); // 3 * (2^k)
    recur(0,0, n/3);
    for(int i=0; i<n; i++){
        for(int j=0; j<2*n-1; j++){
            if(m[i][j] == '*') printf("*");
            else printf(" ");

        }
        if(i != n-1) printf("\n");
    }
    return 0;
}