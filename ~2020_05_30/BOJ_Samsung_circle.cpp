#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> p;
int maps[51][51];
int n,m,t; // n circles, m numbers per circle
void rotate(int i, int d, int k){
    if(d == 0){ // clock wise >>>
        for(int x=0; x<k; x++){
            int temp = maps[i][m];
            for(int j=m; j>1; j--){
                maps[i][j] = maps[i][j-1];
            }
            maps[i][1] = temp;
        }
    }
    else{// counter clock wise <<<<
        for(int x=0; x<k; x++){
            int temp = maps[i][1];
            for(int j=1; j<m; j++){
                maps[i][j] = maps[i][j+1];
            }
            maps[i][m] = temp;
        }
    }
}

void calc(){
    vector<p> suc;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(maps[i][j] == 0 ) continue;
            if(maps[i][j] == maps[i][j-1] && j>1){
                suc.push_back({i,j});
                suc.push_back({i,j-1});
            }
            if(maps[i][j] == maps[i][j+1] && j<n){
                suc.push_back({i,j});
                suc.push_back({i,j+1});
            }
            if(maps[i][j] == maps[i-1][j] && i>1){
                suc.push_back({i,j});
                suc.push_back({i-1,j});
            }
            if(maps[i][j] == maps[i+1][j] && i<n){
                suc.push_back({i,j});
                suc.push_back({i+1,j});
            }
        }
        if(maps[i][1] == maps[i][m] && maps[i][1] != 0){
            suc.push_back({i,1});
            suc.push_back({i,m});
        }
    }
    // cout << "**** : " << suc.size() <<endl;
    if(suc.empty()){// average and calc
        int total=0, num =0;
        vector<p> non;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(maps[i][j] !=0){
                    non.push_back({i,j});
                    total += maps[i][j];
                    num++;
                }
            }
        }
        float avg = (float)total / (float)num;
        //cout << "********* : " <<  avg <<endl;
        for(auto a : non){
            if(maps[a.first][a.second] < avg)
                maps[a.first][a.second]++;
            else if(maps[a.first][a.second] > avg)
                maps[a.first][a.second]--;
        }
    }else{
        for(auto a : suc){
            maps[a.first][a.second] = 0;
        }
    }
}
int sum(){
    int ret=0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            ret += maps[i][j];
        }
    }
    return ret;
}
void pr(){
    cout << "------------" <<endl;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cout << maps[i][j] << " ";
        }
        cout <<endl;
    }
    cout<< "------------" <<endl;
}
int main(){

    scanf("%d %d %d", &n, &m, &t);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            scanf("%d", &maps[i][j]);
        }
    }
    for(int i=0; i<t; i++){
        int x, d, k;
        scanf("%d %d %d", &x, &d, &k);
        for(int a=1; a<=n; a++) if(a%x ==0) rotate(a,d,k);
        //pr();
        calc();
        //pr();

    }
    printf("%d\n", sum());
    return 0;
}
