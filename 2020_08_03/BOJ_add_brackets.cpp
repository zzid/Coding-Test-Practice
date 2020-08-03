#include <bits/stdc++.h>

using namespace std;

vector<int> num;
vector<char> oper;
int answer =INT_MIN;
int calc(int a, char op, int b){
    if(op == '+') return (a + b);
    else if(op == '*') return (a*b);
    else return (a - b);
}

void dfs(int idx,int temp){
    // cout << temp <<endl;
    if(idx >= oper.size()){
        answer = max(temp, answer); //temp > answer ? temp : answer;
        return;
    }

    dfs(idx+1, calc(temp, oper[idx], num[idx+1])); // 괄호 계산
    int later_calc = calc(num[idx+1], oper[idx+1], num[idx+2]);
    dfs(idx+2, calc(temp, oper[idx], later_calc)); // 다음 괄호로 계산
}
int main(){
    int length;
    cin >> length;
    string form;
    cin >> form;
    // int length = 5;
    // string form = "8*3+5"; //136

    for(int i=0; i<length; i++){
        if(isdigit(form[i])) num.push_back(form[i] -'0');
        else oper.push_back(form[i]);
    }

    dfs(0,num[0]);
    cout << answer <<endl;
    return 0;
}