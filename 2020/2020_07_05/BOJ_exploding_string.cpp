#include <bits/stdc++.h>
using namespace std;
string inp, ex, answer ="";
int main(){
    cin >> inp >> ex;
    for(int i=0; i<inp.length(); i++){
        if(inp[i] == ex[ex.length()-1]){
            bool flag = true;
            for(int j=1; j<ex.length(); j++){
                if(answer[answer.length()-j] != ex[ex.length()-j-1]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                for(int j=1; j<ex.length(); j++) answer.pop_back();
                continue;
            }
        }
        answer += inp[i];
    }
    cout<< ((answer.length() == 0) ? "FRULA" : answer) <<endl;
    return 0;
}