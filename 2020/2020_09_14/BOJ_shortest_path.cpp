#include <bits/stdc++.h>
using namespace std;

typedef struct{
    int to;
    int w;
}info;
struct comp {
    bool operator()(info a, info b){
        return a.w > b.w; // descending order
    }
};
int v,e,s;
vector<vector<info>> vertex;
const int MAX = 999999999;
void dijkstra(int s){
    priority_queue<info, vector<info>, comp> pq;
    vector<int> dist(v+1, MAX);
    dist[s] = 0;
    pq.push({s,0});
    for(int i=1; i<=v; i++){
        if(i!=s) pq.push({i,MAX});
    }
    while(!pq.empty()){
        auto temp = pq.top(); pq.pop();
        int to = temp.to, w = temp.w;
        if(w >dist[to]) continue;
        for(auto i : vertex[to]){
            int to_ = i.to, w_ = i.w;
            if(dist[to_] > dist[to] + w_){
                dist[to_] = dist[to] + w_;
                pq.push({to_,dist[to_]});
            }
        }
    }
    for(int i=1; i<=v; i++){
        printf(dist[i] == MAX? "INF\n":"%d\n", dist[i]);
    }
}
int main(){
    scanf("%d %d %d", &v, &e, &s);
    vertex.resize(v+1);
    for(int i=0; i<e; i++){
        int a,b,c;
        scanf("%d %d %d", &a,&b,&c);
        vertex[a].push_back({b,c});
    }
    dijkstra(s);
}
