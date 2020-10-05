#include <bits/stdc++.h>
using namespace std;
int answer =0;
void dfs(int n, int cnt){
    if(n < 3 || n < pow(3,cnt/2)) return ;
    if(n<3) return;
    if(n ==3){
        if(cnt == 2) answer++;
        return;
    }else if( n> 3){
    if(n%3==0 && cnt >= 2) {dfs(n/3,cnt-2);}
    dfs(n-1,cnt+1);
    }
}
int solution(int num) {
    dfs(num,0);
    return answer;
}