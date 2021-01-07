#include <bits/stdc++.h>
using namespace std;
#define mod 1000000000
int n;
typedef long long ll;
ll dp[101][10];
int solve(){
    for(int i=1; i<10; i++) dp[1][i] = 1;
    for(int i=2; i<=n; i++){
        for(int j=0; j<10; j++){
            if(j == 0) dp[i][j] = dp[i-1][j+1];
            else if(j >= 1 && j<= 8) dp[i][j] = (dp[i-1][j-1] +dp[i-1][j+1]) % mod;
            else dp[i][j] = dp[i-1][j-1];
        }
    }
    ll ret =0;
    for(int i=0; i<10; i++) ret  = (ret + dp[n][i]) % mod;
    return ret % mod;
}
int main(){
    scanf("%d", &n);
    printf("%d", solve());
    return 0;
}