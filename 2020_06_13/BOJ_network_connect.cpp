// https://www.acmicpc.net/problem/1922
/**
 *
 *  kruskal algorithm (MST)
 *
 **/
#include <bits/stdc++.h>
using namespace std;
int parent[1001];
int n,m,answer=0;
bool chk;
typedef struct kruskal{
    int from;
    int to;
    int cost;
}ks;
vector<ks> edge;
bool comp(ks a, ks b){
    return a.cost < b.cost;
}
int Find(int a){
    if(a == parent[a]) return a;
    return parent[a] = Find(parent[a]);
}
void Union(int a, int b){
    chk = false;
    a = Find(a);
    b = Find(b);
    if(a == b) return;
    parent[a] = b;
    chk = true;
}
int main(){
    scanf("%d", &n);
    scanf("%d", &m);
    for(int i=1; i<=n; i++) parent[i] = i;
    for(int i=0; i<m; i++){
        // int a,b,c;
        ks kr;
        scanf("%d %d %d", &kr.from, &kr.to, &kr.cost);
        edge.push_back(kr);
    }
    sort(edge.begin(), edge.end(), comp);
    for(auto i : edge){
        Union(i.from, i.to);
        if(chk) answer += i.cost;
    }
    printf("%d", answer);

    return 0;
}
