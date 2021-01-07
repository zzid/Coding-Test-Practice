#include <bits/stdc++.h>


using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0, max = 0, min =12345;
    for(int i : stones){
        max = i > max ? i : max;
        min = i < min ? i : min;
    }
    int left = min, right =max, mid;
    
    while(right >= left){
        mid = (left + right) / 2;
        int in_a_raw=0;
        for(int i=0; i<stones.size(); i++){
            if(stones[i] <= mid){
                in_a_raw++;
                if(in_a_raw >= k) break;   
            }
            else in_a_raw =0;
            
        }
        // cout<< mid << " " <<  m_inaraw <<endl;
        if(in_a_raw >= k){
            answer = mid;
            right = mid -1;
        }
        else left = mid+ 1;
    }
    return answer;
}