#include <bits/stdc++.h>
using namespace std;

const int dy[4] = { 0,0,-1,1 },  dx[4] = { 1,-1,0,0 };
int n, a, b, c;
long long answer = 0;
typedef pair <int, int> p;
queue<int> q;

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		q.push(a);
	}
	cin >> b >> c;
}

void solution() {
	while ((!q.empty())) {
		int a = q.front(); q.pop();
		
		if (a > b) { 
			a -= b;
			answer++;
		}
		else {
			answer++;
			continue;
		}

		if (a > c) {
			int temp = a / c;
			if (temp > 0) {
				answer += temp;
				int temp2 = a % c;
				if (temp2 > 0) {
					answer++;
				}
			}
		}
		else {
			answer++;
		}
	}
	cout << answer << endl;
}


int main() {
	input();
	solution();
	return 0;
}