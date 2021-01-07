#include <bits/stdc++.h>
using namespace std;
priority_queue<int> max_heap;
priority_queue<int, vector<int>, greater<int>> min_heap;
int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int t;
        scanf("%d", &t);
        if(max_heap.size() > min_heap.size()) min_heap.push(t);
        else max_heap.push(t);
        
        if(!max_heap.empty() && !min_heap.empty() &&
            max_heap.top() > min_heap.top()){
            
            int temp1 = max_heap.top(),
                temp2 = min_heap.top();
            max_heap.pop(); min_heap.pop();
            min_heap.push(temp1); max_heap.push(temp2);
        }
        printf("%d\n", max_heap.top());
    }
    return 0;
}