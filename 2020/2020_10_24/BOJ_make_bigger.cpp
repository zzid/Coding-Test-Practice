#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    string answer ="", num;
    cin >> n >> k >> num;
    deque<char> dq;
    for (int i = 0; i < n; i++) {
        while(k && !dq.empty() && dq.back() < num[i]) {
            dq.pop_back();
            k--;
        }
        dq.push_back(num[i]);
    }

    for (int i = 0; i < dq.size()-k; i++) answer += dq[i];
    cout << answer <<endl;
    return 0;
}