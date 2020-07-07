#include <bits/stdc++.h>
using namespace std;
vector<int> order;
int dp[100000][5][5];

int chk(int from, int to){
    if(from == 0) return 2;
    if(from == to) return 1;
    if(abs(from - to) == 2) return 4;
    return 3;
}

int solve(int y, int x, int step){
    if(step == order.size()) return 0;
    if(dp[step][y][x] != -1) return dp[step][y][x];

    int left = solve(order[step], x, step + 1) +chk(y, order[step]),
        right = solve(y, order[step], step + 1) + chk(x, order[step]);

    return dp[step][y][x] = min(left,right);
}
int main(){
    while(1){
        int a;
        cin >> a;
        if(a == 0) break;
        order.push_back(a);
    }
    memset(dp, -1, sizeof(dp));
    cout << solve(0, 0, 0) << endl;
    return 0;
}
