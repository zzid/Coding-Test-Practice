#include <bits/stdc++.h>

using namespace std;
int n, s[20][20] = { 0, }, answer = 987654321;


deque<int> h;
void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> s[i][j];
		}
	}
}
void printq(deque<int> q) {
	for (auto i : q) {
		cout << i << " ";
	}
	cout << endl;
}

void solution(deque<int> q) {
	int startS = 0, linkS = 0;
	deque<int> another;
	for (int j = 0; j < n; j++) {
		bool exist = false;
		for (auto i : q) {
			if (i == j) exist = true;
		}
		if (exist == false) {
			another.push_back(j);
		}
	}
	for (int j = 0; j < (int)q.size(); j++) {
		for (int k = j + 1; k < (int)q.size(); k++) {
			startS += s[q[j]][q[k]] + s[q[k]][q[j]];
		}
	}

	for (int j = 0; j < (int)another.size(); j++) {
		for (int k = j + 1; k < (int)another.size(); k++) {
			linkS += s[another[j]][another[k]] + s[another[k]][another[j]];
		}
	}

	int temp = abs(startS - linkS);
	if (temp < answer) answer = temp;

}
void half(deque<int> q, int index) {
	if (q.size() == n / 2) {
		solution(q);
		return;
	}
	if (index >= n) return;
	deque<int> qq;
	qq = q;
	qq.push_back(index);
	deque<int> qn;
	qn = q;
	half(qq, index + 1);
	half(qn, index + 1);
}
int main() {
	deque<int> q;
	input();
	half(q,0);
	cout << answer << endl;
	return 0;
}