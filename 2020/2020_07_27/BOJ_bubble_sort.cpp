#include <bits/stdc++.h>
using namespace std;
vector <pair<int,int>> arr(500000);
int main()
{
    int n;
    scanf("%d",&n);
    arr.resize(n);
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i].first);
        arr[i].second = i;
    }

    sort(arr.begin(),arr.end());

    int answer =0;
    for(int i=0; i<n; i++) answer = max(answer, arr[i].second - i);
    printf("%d",answer+1);
    return 0;
}
