#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> cookie) {
    int answer = 0;
    int cz = cookie.size();
    
    for(int m=0; m<cz-1; m++){
        int i = m, r =m+1;
        int left = cookie[i], right = cookie[r];
        while(1){
               if(left > right){
                   r++;
                   if(r >= cz) break;
                   right += cookie[r];
               }else if(left < right){
                   i--;
                   if(i < 0) break;
                   left += cookie[i];
               }else if(left == right){
                   answer = left > answer ? left : answer;
                   //break;
                   i--;
                   if(i < 0) break;
                   left += cookie[i];
               }
        }
    }
    return answer;
}