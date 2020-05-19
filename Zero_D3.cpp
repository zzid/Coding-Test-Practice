#include <iostream>
#include <deque>
#include <queue>
using namespace std;

deque<int> numbers;

int main(){
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        int k;
        long long result =0;
        cin >> k;
        for(int a =0; a<k; a++ ){
            int temp;
            cin >> temp;
            if(temp != 0) numbers.push_back(temp);
            else numbers.pop_back();
        }

        while(!numbers.empty()){
            int x = numbers.front();
            numbers.pop_front();
            result += x;
        }

        cout << "#" << i+1 << " " << result << endl;
    }

    return 0;
}