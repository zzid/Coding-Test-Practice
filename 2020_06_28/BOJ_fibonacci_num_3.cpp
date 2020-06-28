#include <bits/stdc++.h>
#define mod 1000000
using namespace std;
typedef unsigned long long ull;
int main(){
    ull n;
    cin >> n;
    n %= 1500000;
    ull prev = 0, curr = 1, nex =0;
    if(n == 0 || n == 1){
        int ret;
        if(n ==0) ret = 0;
        else ret = 1;    
        cout << ret <<endl;
        return 0;
    }
    for(int i=1; i<n; i++){
        nex = (curr + prev) % mod;
        prev = curr;
        curr = nex;
    }
    cout << nex % mod <<endl;
    return 0;
}