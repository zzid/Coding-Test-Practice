#include <bits/stdc++.h>
using namespace std;
int n,m,s,d;
const int MAX = 999999999;
typedef struct {
    int to; int w;
}info;
vector<vector<info>> vtx;
struct comp{
    bool operator()(info a, info b){
        return a.w > b.w;
    }
};
void dijkstra(int s, int d){
    priority_queue<info, vector<info>, comp> pq;
    pq.push({s,0});

    vector<int> dist(n+1, MAX);
    dist[s] = 0;

    for(int i=1; i<=n; i++){
        if(i!=s) pq.push({i,MAX});
    }
    while(!pq.empty()){
        auto t = pq.top(); pq.pop();
        int to = t.to, w = t.w;
        if(w > dist[to]) continue;
        for(auto i : vtx[to]){
            int to_ = i.to, w_ = i.w;
            if(dist[to_] > dist[to] + w_){
                dist[to_] = dist[to] + w_;
                pq.push({to_,dist[to_]});
            }
        }
    }

    cout<< dist[d] <<endl;
}
int main() {
    cin >> n >> m;
    vtx.resize(n+1);
    for(int i=0; i<m; i++){
        int from, to,w;
        scanf("%d %d %d", &from, &to, &w);
        vtx[from].push_back({to,w});
    }
    cin >> s >> d;
    dijkstra(s,d);
    return 0;
}