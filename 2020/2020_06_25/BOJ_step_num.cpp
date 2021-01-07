#include <bits/stdc++.h>
using namespace std;
#define mod 1000000000
int n;
typedef long long ll;
ll dp[101][10][1<<10];
int solve(){
    for(int i=1; i<10; i++) dp[1][i][1<<i] = 1;
    for(int i=2; i<=n; i++){
        for(int j=0; j<10; j++){
            for(int k=0; k< (1<<10); k++){
                if(j == 0) dp[i][j][ k | (1<<j) ] = (dp[i][j][ k | (1<<j) ] + dp[i-1][j+1][k]) % mod;
                else if(j >= 1 && j<= 8){
                    dp[i][j][ k | (1<<j) ] = (dp[i-1][j-1][k] + dp[i][j][ k | (1<<j) ]) %mod;
                    dp[i][j][ k | (1<<j) ] = (dp[i-1][j+1][k] + dp[i][j][ k | (1<<j) ]) %mod;
                }
                else dp[i][j][ k | (1<<j) ] = (dp[i][j][ k | (1<<j) ] + dp[i-1][j-1][k]) % mod;
            }
        }
    }
    ll ret =0;
    for(int i=0; i<10; i++) ret  = (ret + dp[n][i][(1<<10)-1]) % mod;
    return ret % mod;
}
int main(){
    scanf("%d", &n);
    printf("%d", solve());
    return 0;
}