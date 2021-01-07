#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
map<ll, ll> parent;
ll Find(ll a){
    if(parent[a] == 0) {parent[a] = a+1; return a;}
    return parent[a] = Find(parent[a]);
}
vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    for(ll i: room_number){
        answer.push_back(Find(i));
    }
    return answer;
}