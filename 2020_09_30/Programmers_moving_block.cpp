#include <bits/stdc++.h>

using namespace std;
const int sec = 1000 -1;
typedef pair<int,int> p;
int solution(vector<string> lines) {
    int answer = 0;
    vector<p> nums;
    for(auto a : lines){
        string temp ="";
        int cnt=0;
        int hh = stoi(a.substr(11,2)),
            mm = stoi(a.substr(14,2)),
            ss = stoi(a.substr(17,2)),
            ms = stoi(a.substr(20,3));
        int temp_time = hh * 60 * 60 * 1000 + 
                        mm * 60 * 1000 +
                        ss * 1000 + ms;
        
        for(int i=23; i< a.length()-1; i++){
            if(a[i] != '.'){
                temp += a[i];
                cnt++;
            }
        }
        for(int i=0; i<=4-cnt; i++) temp +='0';
        nums.push_back({temp_time - stoi(temp) + 1, temp_time});
    }
    for(auto i : nums){
        int t_ans1 =0, t_ans2 =0;
        int pf = i.first, pl = i.second;
        for(auto j : nums){
            int tf = j.first, tl = j.second;
            if( pf <= tl && tl <= pf+sec) t_ans1++;
            else if( tf <= pf && pf+sec <= tl) t_ans1++;
            else if( pf<= tf && tf<=pf+sec) t_ans1++;
            else if( pf <= tf && tl <=pf+sec) t_ans1++;
            
            if( pl <= tl && tl <= pl+sec) t_ans2++;
            else if( tf <= pl && pl+sec <= tl) t_ans2++;
            else if( pl<= tf && tf<=pl+sec) t_ans2++;
            else if( pl <= tf && tl <=pl+sec) t_ans2++;
        }
        int t_ans = t_ans1 > t_ans2 ? t_ans1 : t_ans2;
        answer = answer ==0 || answer < t_ans ? t_ans : answer;
    }
    return answer;
}