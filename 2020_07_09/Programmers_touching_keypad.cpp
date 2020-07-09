#include <bits/stdc++.h>
using namespace std;
int nums[10][2] = {{3,1},
              {0,0}, {0,1}, {0,2},
              {1,0}, {1,1}, {1,2},  
              {2,0}, {2,1}, {2,2},
             };
// typedef pair<int, int> p;
string answer = "", h;
// p l = {3,0}, r ={3,2};
int ly = 3, lx = 0,
    ry = 3, rx = 2;
void mov(int i){
    int y = nums[i][0], x = nums[i][1];
    if(i == 1 || i == 4 || i == 7){
        ly = y, lx =x;
        answer +='L';
    }else if(i == 3 || i == 6 || i == 9){
        ry = y, rx = x;
        answer += 'R';
    }else{
        int dl = abs(ly - y) + abs(lx - x),
            dr = abs(ry - y) + abs(rx - x);
        if(dl == dr){
            if(h[0] == 'r'){
                ry = y, rx = x;
                answer += 'R';
            }else{
                ly = y, lx = x;
                answer += 'L';
            }
        }else if (dl < dr){
            ly = y, lx = x;
            answer += 'L';
        }else{
            ry = y, rx = x;
            answer += 'R';
        }
    }
}
string solution(vector<int> numbers, string hand) {
    h = hand;
    for(int i=0; i< numbers.size(); i++){
        mov(numbers[i]);
    }
    return answer;
}