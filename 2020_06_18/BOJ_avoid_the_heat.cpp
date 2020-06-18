#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
const int dy[4] = {-1,1,0,0};
const int dx[4] = {0,0,-1,1};
int mod = 1000000007;
int answer =0;
p cur,home;
int t_lim, num;
map<p,int> obstacle;
map<p,int> dp;
int main(){
    scanf("%d %d", &cur.first, &cur.second);
    scanf("%d", &t_lim);
    scanf("%d %d", &home.first, &home.second);
    scanf("%d", &num);
    for(int i=0; i<num; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        obstacle[{a,b}] = 1;
    }
    queue<pair<p,int>> q;
    q.push({cur,0});
    dp[cur] = 1;
    while(!q.empty()){
        auto c = q.front(); q.pop();
        if(c.second +1 +abs(home.first - c.first.first) + abs(home.second - c.first.second) > t_lim){
            continue;
        }
        for(int d =0; d<4; d++){
            p idx ={ c.first.first + dx[d], c.first.second + dy[d] };
            pair<p, int> n = {idx, c.second+1};
            if(n.first.first == home.first && n.first.second == home.second){
                if( n.second < t_lim){
                    dp[{n.first.first, n.first.second}]
                    = (dp[{n.first.first, n.first.second}] + dp[{c.first.first, c.first.second}]) % mod;
                }
                continue;
            }
            if(n.second + abs(home.first - n.first.first) + abs(home.second - n.first.second) > t_lim){
                continue;
            }
            if(obstacle[{n.first.first, n.first.second}] == 1){
                continue;
            }
            else{
                dp[ {n.first.first, n.first.second} ]
                =(dp[{c.first.first, c.first.second}] + dp[ {n.first.first, n.first.second} ]) % mod;
                q.push(n);
            }
        }
    }
    printf("%d", dp[{home.first, home.second}]);
    return 0;
}
