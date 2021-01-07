#include <bits/stdc++.h>
using namespace std;
int parent[(int)(2*(1e6+1))];
int howMany[(int)(2*(1e6+1))];
int find(int a){
    if(a == parent[a]) return a;
    return parent[a] = find(parent[a]);
}
void Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a==b){ printf("%d\n", howMany[a]); return;}
    howMany[a] += howMany[b];
    parent[b] = a;
    printf("%d\n", howMany[a]);
    // return howMany[a];
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        int f, num =1;
        scanf("%d",&f);
        map<string, int> m;
        m.clear();
        for(int x=1; x<=2*f; x++){ // init
            parent[x] =x;
            howMany[x] = 1;
        }
        for(int j =0; j<f; j++){
            // string a,b;
            // cin >> a >> b;
            char a[21],b[21];
            scanf("%s %s", a,b);
            if(m.find(a) == m.end()){
                m.insert({a,num});
                num++;
            }
            if(m.find(b) == m.end()){
                m.insert({b,num});
                num++;
            }
            // printf("%d\n", Union(m[a],m[b]));
            // cout<< Union(m[a],m[b])<<endl;
            // for(int a=1; a<=2*f; a++) cout << parent[a] <<" ";
            // cout <<endl;
        }
    }
    return 0;
}