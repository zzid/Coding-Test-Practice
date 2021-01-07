#include <bits/stdc++.h>

using namespace std;

int x[int(1e6+1)] ={0,};
int main(){
    int n;
    cin >> n;
    x[1] = 0;
    for(int i=2; i<=n; i++){
        x[i] = x[i-1] +1;
        if(i % 3 ==0) x[i] = min(x[i], x[i/3] +1);
        if(i % 2 ==0) x[i] = min(x[i], x[i/2] +1);
    }
    cout << x[n] <<endl;
    return 0;
}