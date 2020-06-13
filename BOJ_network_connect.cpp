// https://www.acmicpc.net/problem/1922
/**
 *  
 *  kruskal algorithm 
 * 
 **/
#include <bits/stdc++.h>
using namespace std;
int parent[1001];
int n,m;
int Find(int a){
    if(a == parent[a]) return a;
    return parent[a] = Find(parent[a]);
}
void Union(int a, int b){
    a = Find(a);
    b = Find(b);
    if(a < b) parent[b] = a;
    else parent[a] = b;
}
int main(){
    scanf("%d", &n);
    scanf("%d", &m);
    for(int i=0; i<m; i++){
        int a,b,c;
        scanf("%d %d %d", &a, &b, &c);
    }
    return 0;
}