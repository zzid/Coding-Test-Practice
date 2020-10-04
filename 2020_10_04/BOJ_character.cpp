#include <bits/stdc++.h>
using namespace std;
string makeString(int time){
    string hh = to_string(time / 60),
           mm = to_string(time % 60);
    if(hh.length() == 1) hh = '0'+ hh;
    if(mm.length() == 1) mm = '0'+ mm;
    return hh +':' +mm;
}
string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    int wait = timetable.size();
    vector<int> waits, bus_time;
    int time = 9 * 60;
    for(int i=0; i<n; i++)  bus_time.push_back(time + ( i* t ));
    for(int i =0; i<wait; i++){
        int a = stoi(timetable[i].substr(0,2)),
            b = stoi(timetable[i].substr(3,2)),
            temp_time = a * 60 + b;
        waits.push_back(temp_time);
    }
    sort(waits.begin(), waits.end());
    int x=0;
    for(int i=0; i<n; i++){
        int cap = m * (n-i);
        for(int j=x; j<wait; j++){
            if(bus_time[i] >= waits[j]){
                cap--;
                if(cap <=0) return makeString(waits[j]-1);
                else if(m * (n-i) - cap >m){
                    x =j;
                    break;
                }
            }else{ 
                x =j; 
                break;
            }
        }
        //if(!flag) x =0;
    }
    return makeString(bus_time[bus_time.size()-1]);
}