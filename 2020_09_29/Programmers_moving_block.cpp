#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> b;
int n , answer =0;
typedef pair<int, int> p;
const int dy[4] ={-1,1,0,0}, dx[4] ={0,0,-1,1};
const int ry[4] ={-1,-1,1,1}, rx[4] ={-1,1,1,-1};
bool visited[100][100][100][100];
class drone{
public:
    p idx1,idx2;
    int cnt; 
    void make(p a, p b, int cnt){
        this->idx1 = a;
        this->idx2 = b;
        this->cnt = cnt;
        visited[this->idx1.first][this->idx1.second][this->idx2.first][this->idx2.second] = true;
    }
    bool move(int dir){
        p np1 = {this->idx1.first + dy[dir], this->idx1.second + dx[dir]};
        p np2 = {this->idx2.first + dy[dir], this->idx2.second + dx[dir]};
        if(isAvail(dir,np1,np2)){
            this-> idx1 = np1;
            this-> idx2 = np2;
            visited[this->idx1.first][this->idx1.second][this->idx2.first][this->idx2.second] = true;
            return true;
        }
        return false;
    }
    bool rotate(int dir){
        int cat;
        p np1, np2;
        if(this->idx1.first == this->idx2.first){//가로
            cat = 0;
           if(this->idx1.second <  this->idx2.second){
               if(dir == 0){
                   np1 = this->idx1;
                   np2 = {this->idx2.first + ry[dir], this->idx2.second + rx[dir]};
               }
               else if(dir == 1){
                   np1 = {this->idx1.first + ry[dir], this->idx1.second + rx[dir]};
                   np2 = this->idx2;
               }
               else if(dir == 2){
                   np1 = {this->idx1.first + ry[dir], this->idx1.second + rx[dir]};
                   np2 = this->idx2;
               }
               else if(dir == 3){
                   np1 = this->idx1;
                   np2 = {this->idx2.first + ry[dir], this->idx2.second + rx[dir]};
               }
           }else{
              if(dir == 0){
                   np1 = this->idx2;
                   np2 = {this->idx1.first + ry[dir], this->idx1.second + rx[dir]};
               }
               else if(dir == 1){
                   np1 = {this->idx2.first + ry[dir], this->idx2.second + rx[dir]};
                   np2 = this->idx1;
               }
               else if(dir == 2){
                   np1 = {this->idx2.first + ry[dir], this->idx2.second + rx[dir]};
                   np2 = this->idx1;
               }
               else if(dir == 3){
                   np1 = this->idx2;
                   np2 = {this->idx1.first + ry[dir], this->idx1.second + rx[dir]};
               }
           }
        }else{ //세로
            cat =1;
            if(this->idx1.first <  this->idx2.first){
                if(dir ==0){
                    np1 = this->idx1;
                    np2 = {this->idx2.first + ry[dir], this->idx2.second + rx[dir]};
                }
                else if(dir == 1){
                    np1 = this->idx1;
                    np2 = {this->idx2.first + ry[dir], this->idx2.second + rx[dir]};                    
                }
                else if(dir == 2){
                    np1 = {this->idx1.first + ry[dir], this->idx1.second + rx[dir]};
                    np2 = this->idx2;
                }
                else if(dir == 3){
                    np1 = {this->idx1.first + ry[dir], this->idx1.second + rx[dir]};
                    np2 = this->idx2;
                }                
            }
            else{
                if(dir ==0){
                    np1 = this->idx2;
                    np2 = {this->idx1.first + ry[dir], this->idx1.second + rx[dir]};
                }
                else if(dir == 1){
                    np1 = this->idx2;
                    np2 = {this->idx1.first + ry[dir], this->idx1.second + rx[dir]};                    
                }
                else if(dir == 2){
                    np1 = {this->idx2.first + ry[dir], this->idx2.second + rx[dir]};
                    np2 = this->idx1;
                }
                else if(dir == 3){
                    np1 = {this->idx2.first + ry[dir], this->idx2.second + rx[dir]};
                    np2 = this->idx1;
                }                                
            }
        }
        if(canRotate(dir,np1,np2, cat)){
            this->idx1 = np1;
            this->idx2 = np2;
            visited[this->idx1.first][this->idx1.second][this->idx2.first][this->idx2.second] = true;
            return true;
        }
        return false;
    }
    bool canRotate(int dir, p np1, p np2, int cat){
        if(np1.first >= n || np1.first <0 || np1.second >= n || np1.second <0
            || np2.first >= n || np2.first <0 || np2.second >= n || np2.second <0){
                return false;
        }
        if(visited[np1.first][np1.second][np2.first][np2.second]) return false;        
        if(b[np1.first][np1.second] == 1 || b[np2.first][np2.second] == 1) return false;
        if(cat ==0){
            if(dir == 0 || dir == 3){
                if(b[np2.first][np2.second+1] == 1) return false;
            }else{
                if(b[np1.first][np1.second-1] == 1) return false;
            }
        }else if(cat == 1){
            if(dir == 0 || dir == 1){
                if(b[np2.first+1][np2.second] == 1) return false;
            }else{
                if(b[np1.first-1][np1.second] == 1) return false;
            }            
        }
        return true;
    }
    bool isAvail(int dir, p np1, p np2){
        if(np1.first >= n || np1.first <0 || np1.second >= n || np1.second <0
            || np2.first >= n || np2.first <0 || np2.second >= n || np2.second <0){
                return false;
        }
        if(visited[np1.first][np1.second][np2.first][np2.second]) return false;
        if(b[np1.first][np1.second] == 1 || b[np2.first][np2.second] == 1) return false;
        return true;
    }
    bool arrive(){
        if( (this->idx1.first == n-1 && this->idx1.second == n-1) ||
             (this->idx2.first == n-1 &&this->idx2.second == n-1)){
            return true;
        }
        return false;
    }
};
void draw(int a, int x,int c, int d){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if((i==a && j==x) || (i==c && j==d)){
            cout << "* ";
            }else if( b[i][j] == 1) cout << "1 ";
            else    cout << "0 ";
        }
        cout <<endl;
    }
}
void find(drone* d){
    queue<drone*> suc;
    suc.push(d);
    while(!suc.empty()){
        auto a = suc.front(); suc.pop();
        //cout << a->cnt <<endl;
        //draw(a->idx1.first,a->idx1.second,a->idx2.first,a->idx2.second);
        if(a->arrive()){
            answer = answer == 0 || answer > a->cnt ? a->cnt : answer;
            continue;
        }
        for(int i=0; i<4; i++){ // move
            drone* nd = new drone;
            nd->make(a->idx1, a->idx2, a->cnt +1);
            if(nd->move(i)) suc.push(nd);
        }
        for(int i=0; i<4; i++){ //rotate
            drone* nd = new drone;
            nd->make(a->idx1, a->idx2, a->cnt +1);
            if(nd->rotate(i)) suc.push(nd);
        }
    }
    
}
int solution(vector<vector<int>> board) {
    b = board; n = board.size();
    drone* d = new drone;
    d->make({0,0},{0,1},0);
    find(d);
    return answer;
}