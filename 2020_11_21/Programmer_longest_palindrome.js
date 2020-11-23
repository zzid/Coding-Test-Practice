#include <bits/stdc++.h>

using namespace std;
int pal(string s, int len){
    bool flag;
    int a =0;
    while(a+len <= s.length()){
        //string temp = s.substr(a,len);
        flag = true;
        for(int i =0; i< ( len /2) ; i++){
            if(s[i+ a] != s[len + a -i-1]){
                flag =false;
                break;
            }
        }
        if(flag) return len;
        else a++;
    }
    return -1;
}
int solution(string s)
{
    int len = s.length();
    while(1){
        if(pal(s,len) >0) return len;
        len--;
        if(len==1) return len;
    }
    return 1;
}