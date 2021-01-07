#include <iostream>
#include <queue>
#include <deque>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int i=0; i<t; i++){ 
        int n,k, result=0;
        cin >> n >> k;
        deque<int> size;
        for(int a = 0; a<n; a++){
            int temp;
            cin >> temp;
            size.push_back(temp);
        }
        sort(size.begin(), size.end());

        // for(auto x = size.begin(); x != size.end(); x++){
        //     cout << "? : " << *x <<endl;
        // }
        for(auto x = size.begin(); x != size.end(); x++){
            int count =0;
            for(auto y = x; y != size.end(); y++){
                if(abs(*x - *y) <= k) count++;
                else break;
            }
            result = result < count ? count : result;
        }


        cout << "#" << i+1 << " " << result << endl;
    }
    return 0;
}