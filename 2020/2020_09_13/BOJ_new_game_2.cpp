#include <bits/stdc++.h>
using namespace std;
const int dy[4] ={0,0,-1,1}, dx[4] ={1,-1,0,0};
const int op[4] ={1,0,3,2};
int arr[12][12];
int n;
class horse{
public:
    int y,x,dir,id;
    horse(int y_, int x_, int dir_, int id_){
        this->y = y_;
        this->x = x_;
        this->dir = dir_;
        this->id = id_;
    }
};
vector<deque<horse*>> hss(144);
vector<horse*> hs;
int solution(){
    int ret =0;
    for(auto i : hs){
        int idx = (i->y)*n + i->x;
        int ny = i->y+dy[i->dir],
            nx = i->x+dx[i->dir];
        if( ny < 0 || nx <0 || ny >= n || nx >=n|| arr[ny][nx] == 2){
            int ndir = op[i->dir];
            i->dir = ndir;
            ny = i->y+dy[i->dir];
            nx = i->x+dx[i->dir];
            if(ny < 0 || nx <0 || ny >= n || nx >=n || arr[ny][nx] == 2) continue;

            if(arr[ny][nx] == 0){//white
                auto x = hss[idx].begin();
                auto start = hss[idx].begin();
                bool flag = false;
                for( ;x != hss[idx].end(); x++){
                    if((*x)->id == i->id){
                        start = x;
                        flag =true;
                    }
                    if(flag){
                        (*x)->y = ny;
                        (*x)->x = nx;
                    }
                }
                hss[ny*n + nx].insert(hss[ny*n + nx].end(), start, hss[idx].end());
                while(start != hss[idx].end()){
                    hss[idx].pop_back();
                }
            }
            else if(arr[ny][nx] == 1){//red
                while(1){
                    auto temp = hss[idx].back(); hss[idx].pop_back();
                    temp->y = ny;
                    temp->x = nx;
                    hss[ny*n + nx].push_back(temp);
                    if(temp->id == i->id) break;
                }
            }
            ret = (int)hss[ny*n + nx].size() > ret ? (int)hss[ny*n + nx].size() : ret;
            if(ret >= 4) return ret;
            continue;
        }
        if(arr[ny][nx] == 0){//white
                auto x = hss[idx].begin();
                auto start = hss[idx].begin();
                bool flag = false;
                for(; x != hss[idx].end(); x++){
                    if((*x)->id == i->id){
                        start = x;
                        flag =true;
                    }
                    if(flag){
                        (*x)->y = ny;
                        (*x)->x = nx;
                    }
                }
                hss[ny*n + nx].insert(hss[ny*n + nx].end(), start, hss[idx].end());
                while(start != hss[idx].end()){
                    hss[idx].pop_back();
                }
        }
        else if(arr[ny][nx] == 1){//red
            while(1){
                auto temp = hss[idx].back(); hss[idx].pop_back();
                temp->y = ny;
                temp->x = nx;
                hss[ny*n + nx].push_back(temp);
                if(temp->id == i->id) break;
            }
        }

        ret = (int)hss[ny*n + nx].size() > ret ? (int)hss[ny*n + nx].size() : ret;
        if(ret >= 4) return ret;
        //pr();
    }
    return ret;
}

int main(){
    int n_, k;
    cin >> n_ >> k;
    n = n_;
    for(int i =0; i<n; i++){
        for(int j =0; j<n; j++){
            cin >> arr[i][j];
        }
    }
    for(int i=0; i<k; i++){
        int y, x,dir;
        cin>>y >> x >> dir;
        horse* h = new horse(y-1,x-1,dir-1,i+1);
        hss[((y-1)*n)+(x-1)].push_back(h);
        hs.push_back(h);
    }
    int answer =-1;
    for(int i=1; i<1001; i++){
        if(solution()>=4)
        {
            answer =i;
            break;
        }
    }
    cout << answer <<endl;

    return 0;
}
/*

void pr(){
    for(auto i : hs){
        cout << i-> id +1 << "] :" << i->y +1 << "," << i->x +1 << endl;
    }
    for(int i =0; i<(int)hss.size(); i++){
        if(hss[i].size() != 0){
            cout << " -----" <<  i /n  +1<< " " << i %n  +1<<endl;
            for(auto j : hss[i]){
                cout <<"id : " <<  j->id +1 <<endl;
            }
        }
    }
}
*/
