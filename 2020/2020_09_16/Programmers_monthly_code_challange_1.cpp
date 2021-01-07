#include <bits/stdc++.h>
using namespace std;
set<int> s;
vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    for(int i=0; i<numbers.size(); i++){
        for(int j=i+1; j<numbers.size(); j++){
            s.insert(numbers[i] + numbers[j]);
        }
    }
    answer.assign(s.begin(), s.end());
    return answer;
}