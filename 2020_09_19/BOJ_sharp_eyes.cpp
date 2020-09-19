#include <bits/stdc++.h>
using namespace std;
typedef struct{
    int from;
    int to;
    int interval;
} li;
typedef long long ll;
int n;
vector<li> v;

ll chk(int a){
    ll ret=0;
    for(int i=0; i<n; i++){
        if(a>=v[i].from){
            ret += ( min(v[i].to, a) - v[i].from ) / v[i].interval +1;
        }
    }
    return ret;
}
int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int a,c,b;
        scanf("%d %d %d", &a, &c, &b);
        v.push_back({a,c,b});
    }
    ll l= 1, r=INT_MAX;
    while(l<r){
        ll m = (l+r)/2;
        if(chk(m) %2 ==0) l = m+1;
        else r = m;
    }
    if(l == INT_MAX) printf("NOTHING");
    else cout<< l<< " " << chk(l)-chk(l-1);
    return 0;
}