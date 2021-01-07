#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
bool prime[1000001];
bool dvd[1000001];
ull minv, maxv;
int main(){
    cin >> minv >> maxv;
    int answer = maxv - minv +1;
    bool flag;
    vector<ull> primes;
    for(int i=2; i<(int)(sqrt(maxv))+1; i++){
        if(!prime[i]){
            for(int j = i*2; j<(int)(sqrt(maxv))+1; j+=i){
                prime[j] = true;
            }
        }
    }
    for(int i=2; i<(int)(sqrt(maxv))+1; i++){
        if(!prime[i]){
            primes.push_back(pow(i,2));
        }
    }

    for(auto j : primes){
        ull low_lim = minv / j;
        ull upp_lim = maxv / j;
        for(ull i = low_lim; i<=upp_lim; i++){
            if(i*j < minv) continue;
            dvd[(i*j)-minv] = true;
        }
    }
    int ret= 0;
    for(int i=0; i<answer; i++){
        if(dvd[i] == false) ret++;
    }
    cout << ret <<endl;
    return 0;
}
