#include <bits/stdc++.h>

using namespace std;

int n;
//long long maxNum = LLONG_MIN, minNum = LLONG_MAX;
long long maxNum = -1000000000, minNum = 1000000000;
int nums[11] = { 0, };
int numOfop[4] = { 0, };
void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> numOfop[i];
	}
}
void recursive(long long value,int i, int a, int b, int c, int d) {
	//cout << value << endl;
	if (a == numOfop[0] && b == numOfop[1] && c == numOfop[2] && d == numOfop[3]) {
		if (value < minNum ) minNum = value;
		if (value > maxNum ) maxNum =value;
		return;
	}
	if(a > numOfop[0] || b > numOfop[1] || c > numOfop[2] || d > numOfop[3]){
		return;
	}
	recursive(value + nums[i + 1], i + 1, a+1, b,c,d);
	recursive(value - nums[i + 1], i + 1, a , b+1, c, d);
	recursive(value * nums[i + 1], i + 1, a , b, c+1, d);
	recursive(value / nums[i + 1], i + 1, a , b, c, d+1);
}
void solution() {
	recursive(nums[0], 0,0,0,0,0);
	cout << maxNum << endl;
	cout << minNum << endl;
}
int main() {
	input();
	solution();
	return 0;
}