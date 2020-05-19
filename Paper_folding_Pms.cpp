#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    answer.push_back(0); // init
    // each side : pow(2,n-1) - 1
    //steps
    //first push 0
    for(int i =0; i<n-1; i++){
        answer.push_back(0);
        int cur_size = answer.size();
        for(int a =cur_size-2; a>=0; a--){
            if(answer[a] == 0) answer.push_back(1);
            else answer.push_back(0);
        }
    }
    
    return answer;
}
// 0
// 0 0 1                           0 1 >> 2^1
// 0 0 1 0 0 1 1                   0 0 1 1 >> 2^2
// 0 0 1 0 0 1 1 0 0 0 1 1 0 1 1   0 0 0 1 1 0 1 1 >> 2^3

