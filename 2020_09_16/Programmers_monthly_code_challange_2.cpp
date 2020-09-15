#include <bits/stdc++.h>
using namespace std;
int arr[1000][1000]={0,};
vector<int> solution(int n) {
    vector<int> answer;
    int cnt =0;
    int row=0,col=0;
    arr[row++][col] = ++cnt;
    for(int i=1; i<n-1; i++) arr[row++][col] = ++cnt;
    for(int i=1; i<n; i++) arr[row][col++] = ++cnt;
    for(int i=1; i<n; i++) arr[row--][col--] = ++cnt;
    row++;col++;
    while(cnt < (n*(n+1)/2)){
        while(arr[++row][col] ==0) arr[row][col] = ++cnt;
        row--;
        while(arr[row][++col] ==0) arr[row][col] = ++cnt;
        col--;
        while(arr[--row][--col] ==0) arr[row][col] = ++cnt;
        row++;col++;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j] != 0) answer.push_back(arr[i][j]);
        }
    }
    
    return answer;
}