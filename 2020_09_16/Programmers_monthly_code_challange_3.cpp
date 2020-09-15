#include <bits/stdc++.h>
using namespace std;
int l[1000000], r[1000000];
int solution(vector<int> a) {
    int n = a.size();
    int answer = n;
    int minv = INT_MAX;
    for(int i=0; i<n; i++){
        minv = min(minv,a[i]);
        l[i] = minv;
    }
    minv = INT_MAX;
    for(int i=n-1; i>=0; i--){
        minv = min(minv,a[i]);
        r[i] = minv;
    }
    
    for(int i=1; i<n-1; i++){
        if(l[i] < a[i] && r[i] < a[i]) answer--;
    }
    return answer;
}