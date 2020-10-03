
/*1
import re
def solution(new_id):
#     1단계 new_id의 모든 대문자를 대응되는 소문자로 치환합니다.
    new_id = new_id.lower()
# 2단계 new_id에서 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거합니다.
    new_id = re.sub('[^0-9a-z._-]','',new_id)
# 3단계 new_id에서 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환합니다.
    new_id = re.sub('[.]{2,}','.',new_id)
# 4단계 new_id에서 마침표(.)가 처음이나 끝에 위치한다면 제거합니다.
    new_id = re.sub('^\.','',new_id)
    new_id = re.sub('\.$','',new_id)
# 5단계 new_id가 빈 문자열이라면, new_id에 "a"를 대입합니다.
    if len(new_id) == 0:
        new_id = 'a'
        
# 6단계 new_id의 길이가 16자 이상이면, new_id의 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거합니다.
#      만약 제거 후 마침표(.)가 new_id의 끝에 위치한다면 끝에 위치한 마침표(.) 문자를 제거합니다.
    if len(new_id) >= 16:
        new_id = new_id[:15]
        new_id = re.sub('\.$','',new_id)
# 7단계 new_id의 길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙입니다.
    if len(new_id) <=2:
        lc = new_id[len(new_id)-1]
        while len(new_id) <3:
            new_id += lc
    
    return new_id
*/
/*2
#include <bits/stdc++.h>
using namespace std;

map<string, int> m;
map<int, int> cnts;
void pick(string og, string candi, int idx){
    if(og.size() <= idx){
        if(candi.size() !=0) m[candi] += 1;
        cnts[candi.size()] = cnts[candi.size()] > m[candi] ? cnts[candi.size()]: m[candi];
        return;
    }
    pick( og, candi+og[idx], idx+1);//select
    pick(og, candi,idx+1);// just next
}
vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    int os = orders.size();
    bool want[11];
    for(auto a : course){
        want[a] = 1;
    }
    
    for(int i=0; i<os; i++){
        sort(orders[i].begin(), orders[i].end());
        pick(orders[i],"",0);
    }
    for(auto n : course){
        // cnts[n] == max
        for(auto i : m){
            if(i.first.size() == n &&  i.second == cnts[n] && cnts[n] >1){
                answer.push_back(i.first);
            }

        }
    }
    sort(answer.begin(), answer.end());
    // for(auto i : answer){
    //     cout << i <<endl;
    // }
    return answer;
}
*/
/*
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll dp[51];
int nums[10] ={6,2,5,5,4,5,6,3,7,6};

ll dfs(int k, int pos){
    ll& ret = dp[k];
    if(ret != -1 || k==1) return ret;
    else if(k ==0) return 1;
    ret =0;
    for(int i=0; i<10; i++){
      if(pos == 0 && i==0) continue;
      if(nums[i] <= k) ret += dfs(k-nums[i],pos+1);
    }
    return ret;
}
int main(){
    memset(dp, -1, sizeof dp);
    dp[1] =0;
    cout << "result : " << dfs(11,0) <<endl;
    return 0;
}

*/