#include <bits/stdc++.h>
using namespace std;
int s[1001];
int parent[1001];
int answer = 0;
int Find(int a){
    if(a == parent[a]) return a;
    else return a = Find(parent[a]);
}
void Union(int a, int b){
    a = Find(a);
    b = Find(b);
    if (a == b) return;
    parent[b] = a;
}
int main(){
    int t;
    scanf("%d", &t);
    for(int i=0; i<t; i++){
        int n,k;
        scanf("%d %d", &n, &k);
        for(int j=1; j<=n; j++){
            parent[j] = j;
            scanf("%d", &s[j]);
        }
        for(int j=0; j<n; j++){
            int a,b;
            scanf("%d %d", &a, &b);
            Union(a,b);
        }
        int x;
        scanf("%d", &x);
        cout << "parent : ";
        for(int a=1; a<=n; a++){
            cout << parent[a] << " ";
        }
    }

    //printf("answer : %d", answer);
    return 0;
}
