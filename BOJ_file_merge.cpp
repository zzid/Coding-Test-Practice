#include <bits/stdc++.h>
using namespace std;
int answer =0;
int dp[500][500];
vector<int> pages;
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int k;
        scanf("%d", &k);
        pages.resize(k);
        for(int i=0; i<k; i++){
            int a;
            scanf("%d", &a);
            pages[i] = a;
        }
        for(int i=0; i<k; i++){
            for(int j=0; j<k; j++){
                dp[i][j] = pages[i] + pages[j];
                dp[i][j] = min(pages[i] + pages[j], dp[i][j]);
            }
        }
        printf("%d\n", answer);
    }
    return 0;
}
