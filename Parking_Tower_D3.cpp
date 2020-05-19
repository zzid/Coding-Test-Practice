#include <vector>
#include <deque>
#include <queue>
#include <iostream>
#include <map>
using namespace std;

int min_num = 0;
map<int, int> car;
deque<int> wait;
bool isAvail[100], isFull = false, status = true;
int n, m; // n : parking space || m : # of cars & weight of cars

int find_min_num(){
    for(int i=0; i<n; i++){
        if(isAvail[i]){
            return i;
        }
    }
    return -1;
}

// key point 는 random access 를 통한 빈공간중 가장 낮은 번호를 찾는것
// 그리고 -n  입력이 들어왔을때는 해당 번호를 가진 차량을 random access 해서 제거 해주고  
// 그 공간을 available 상태로 바꿔주는 작업이 필요

int main(){
    int t;
    cin >> t;
    for(int a=0; a<t; a++){
        long long result = 0;
        cin >> n >> m;
        int R[100], W[2000]; // parking tower size : maximum 100 >> 완탐
        for(int i=0; i<n; i++)  cin >> R[i];
        for(int i=0; i<m; i++)  cin >> W[i];
        
        for(int i=0; i<100; i++){
            isAvail[i] = true;
        }

        for(int i=0; i<2*m; i++){
            int id, idx=0, weight=0, fee=0;
            cin >> id;
            
            // to make "index"
            if(id > 0) status = true; // in
            else status = false; // out
            id = abs(id) - 1;

            if(status){ // if in
                wait.push_back(id);
                idx = find_min_num();

                if(idx >= 0){
                    id = wait.front(); wait.pop_front();
                    isAvail[idx] = false;
                    car.insert({id,idx});
                    weight = W[id];
                    fee = R[idx];
                    result += weight * fee;
                }
            }else{
                idx = car.find(id)->second;
                isAvail[idx] = true;
                car.erase(id);
                if(!wait.empty()){
                    id = wait.front(); wait.pop_front();
                    // idx = find_min_num();
                    isAvail[idx] = false;
                    car.insert({id,idx});
                    weight = W[id];
                    fee = R[idx];
                    result += weight * fee;
                }
            }
            // if( a >0 )    cout << "result : " << result << " W : " << weight << " id : " << id+1 << " F : " << fee <<endl;
            // cout << "Weight : " << weight << endl;
            // cout << "Fee : " << fee<< endl;
        }
        cout << "#" << a+1 << " " << result <<endl;
    }
    return 0;
}