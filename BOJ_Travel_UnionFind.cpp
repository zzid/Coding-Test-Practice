#include <bits/stdc++.h>

using namespace std;

int maps[201][201] ={0,};
int parent[1001] ={0,};
int find(int a){
    if(a == parent[a]) return a;
    return parent[a] = find(parent[a]);
}
void Union(int a, int b){
    a = find(a);
    b = find(b);

    if(a == b) return;

    parent[b] = a;
}
bool canTravel(int from, int to){
    int a =find(from), b = find(to);
    if(a == b) return true;
    else return false;
}
int main(){
    //          init
    for(int i=1; i<=1000; i++) parent[i] = i;
    int n,m;
    cin >> n >> m;
    // n =3, m=3;
    // int maps[3][3] = {{0,1,0},{1,0,1},{0,1,0}};
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> maps[i][j];
            if(j> i && maps[i][j] ==1){
                // cout << "Union " <<  i+1 << " " << j+1<<endl;
                Union(i+1,j+1);
                // for(int i=1; i<=n; i++) cout << i << "'s parent is " << parent[i] <<endl;
            }
        }
    }
    
    queue<int> plan;
    // plan.push(1),plan.push(2),plan.push(3);
    for(int i=0; i<m; i++){
        int temp;
        cin>> temp;
        plan.push(temp);
    }
    
    bool answer;
    while(plan.size() != 1){
        int from = plan.front(); plan.pop();
        int to = plan.front();
        answer = canTravel(from, to);
        if(!answer) break;
    }
    
    if(answer) cout <<"YES" <<endl;
    else cout << "NO" <<endl;
    return 0;
}