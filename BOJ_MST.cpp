// https://www.acmicpc.net/problem/1197
#include <bits/stdc++.h>
using namespace std;
int v,e,answer = 0;
bool chk = false;
int parent[10001];

typedef struct kruskal{
    int from;
    int to;
    int cost;
}ks;
vector<ks> edges;
bool comp(ks a, ks b){return a.cost < b.cost;}
int Find(int a){
    if(a == parent[a] ) return a;
    return parent[a] = Find(parent[a]);
}
void Union(int a, int b){
    a = Find(a);
    b = Find(b);
    if(a  == b){ chk = false; return;}
    parent[b] = a;
    chk = true;
}
int main(){
    scanf("%d %d", &v, &e);
    for(int i=1; i<=v; i++) parent[i] = i;
    for(int i=0; i<e; i++){
        ks t;
        scanf("%d %d %d", &t.from, &t.to, &t.cost);
        edges.push_back(t);
    }
    sort(edges.begin(), edges.end(), comp);
    for(auto a : edges){
        Union(a.from, a.to);
        if(chk) answer += a.cost;
    }
    printf("%d" ,answer);
    return 0;
}
