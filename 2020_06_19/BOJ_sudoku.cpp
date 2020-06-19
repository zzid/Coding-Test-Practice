#include <bits/stdc++.h>
using namespace std;
int sudoku[9][9];
typedef pair<int, int> p;
vector<p> space;
bool isFilled(){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if(sudoku[i][j] == 0) return false;
        }
    }
    return true;
}
bool verChk(int a, int n){
    for(int i=0; i<9; i++){
        if(sudoku[a][i] == n) return false;
    }
    return true;
}
bool horChk(int b, int n){
    for(int i=0; i<9; i++){
        if(sudoku[i][b] == n) return false;
    }
    return true;
}
bool rectChk(int a, int b, int n){
    a /= 3; b/= 3;
    a *= 3; b *=3;
    for(int i=a; i<a+3; i++){
        for(int j=b; j<b+3; j++){
            if(sudoku[i][j] == n) return false;
        }
    }
    return true;
}
void prt(){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cout << sudoku[i][j] << " ";
        }
        cout <<endl;
    }
}
void dfs(int idx){
    if(idx == space.size()){prt(); exit(0);}
    for(int i=1; i<=9; i++){
        int a = space[idx].first, b = space[idx].second;
        if(verChk(a,i) && horChk(b,i) && rectChk(a,b,i)){
            sudoku[a][b] = i;
            dfs(idx+1);
            sudoku[a][b] = 0;
        }
    }
}
int main(){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cin >> sudoku[i][j];
            if(sudoku[i][j] == 0) space.push_back({i,j});
        }
    }
    dfs(0);
    return 0;
}
