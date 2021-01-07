#include <bits/stdc++.h>

using namespace std;
set<int> s;
bool visited[8]={0,};
void dfs(vector<string> u, vector<string> b,int idx, int mask){
    if(idx == b.size()){
        s.insert(mask);
        return;
    }
    
    for(int i =0; i<u.size();i++){
        bool same = true;
        if(visited[i]) continue;
        if(u[i].length() == b[idx].length()){
            for(int j=0; j<b[idx].length(); j++){
                if(b[idx][j] =='*') continue;
                else if(u[i][j] != b[idx][j]){
                    same = false;
                    break;
                }
            }
            if(same){
                visited[i] = true;
                dfs(u,b,idx+1,mask | (1<<i));
                visited[i] = false;
            }
        }else continue;
    }    
}
int solution(vector<string> u, vector<string> b) {
    dfs(u,b,0,0);
    return s.size();
}