#include <bits/stdc++.h>

using namespace std;
int homeD[100] = { 0, };
int n, m, homes;
int answer = 987654321;
typedef pair<int,int> p;
deque<p> chicken, home;
void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int temp;
			cin >> temp;
			if (temp == 2) chicken.push_back(make_pair(i, j));
			if (temp == 1) home.push_back(make_pair(i, j));
		}
	}
	homes = home.size();
	for (int i = 0; i < 100; i++) {
		homeD[i] = 987654321;
	}
}

int summation() {
	int temp = 0;
	for (int i = 0; i < homes; i++) {
		temp += homeD[i];
		homeD[i] = 987654321;
	}
	return temp;
}

void dist(queue<p> s) {
	while (!s.empty()) {
		auto a = s.front(); s.pop();
		int cy = a.first;
		int cx = a.second;
		for (int b = 0; b < homes; b++) {
			int hy = home[b].first;
			int hx = home[b].second;
			int distance = abs(hy - cy) + abs(hx - cx);
			homeD[b] = min(homeD[b], distance);
		}
	}
	int temp = summation();
	answer = min(answer, temp);
}
void solution(int idx, queue<p> q) {
	if (q.size() == m) {
		dist(q);
		return;
	}
	if (idx <= chicken.size() - 1) {
		queue<p> qq = q;
		queue<p> qn = q;
		qq.push(chicken[idx]);
		solution(idx + 1, qq);
		solution(idx + 1, qn);
	}
	else return;
}

int main() {
	queue<p> q;
	input();
	solution(0, q);
	cout << answer << endl;
	return 0;
}