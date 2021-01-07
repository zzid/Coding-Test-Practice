#include <bits/stdc++.h>
using namespace std;
int n, dest, cur_f, answer =0;
typedef pair<int, int> p;
vector<p> sta;
bool comp(p a, p b){
    return a.first < b.first;
}
int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int a,b;
        scanf("%d %d", &a, &b);
        sta.push_back({a,b});
    }
    scanf("%d %d", &dest, &cur_f);
    sort(sta.begin(), sta.end(), comp);
    sta.push_back({dest, 0});
    priority_queue<int, vector<int>, less<int>> oil;
    int i=0, cur = 0;
    while(1){
        if(i > n){
            printf("%d", answer);
            break;
        }
        if(sta[i].first - cur <= cur_f){
            cur_f -= sta[i].first-cur;
            cur = sta[i].first;
            oil.push(sta[i].second);
            i++;
        }else{
            if(oil.empty()){
                printf("%d", -1);
                break;
            }else{
                cur_f += oil.top(); oil.pop();
                answer++;
            }
        }
    }
    return 0;
}
