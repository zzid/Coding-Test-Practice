#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> q;
priority_queue<q, vector<q>, greater<q> > pq;
int arr[100][100] = { 0, };
int xMax, yMax;
int answer;

void R() {
	for (int i = 0; i < yMax; i++) {
		for (int j = 0; j < xMax; j++) {
			int cnt=1;
			if (arr[i][j] == 0) continue;
			for (int k = j + 1; k < xMax; k++) {
				if (arr[i][j] == arr[i][k]) {
					cnt++;
					arr[i][k] = 0;
				}
			}
			if (cnt != 0) {
				pq.push(make_pair(cnt, arr[i][j]));
			}
			arr[i][j] = 0;
		}
		int j = 0;
		while ((!pq.empty())) {
			auto a = pq.top(); pq.pop();
			auto cnt = a.first;
			auto num = a.second;
			arr[i][j] = num;
			j++;
			if (j > 100) break;
			arr[i][j] = cnt;
			j++;
			if (j > 100) break;
		}
		if (xMax < j) xMax = j;
	}
}
void C() {
	for (int i = 0; i < xMax; i++) {
		for (int j = 0; j < yMax; j++) {
			int cnt = 1;
			if (arr[j][i] == 0) continue;
			for (int k = j + 1; k < yMax; k++) {
				if (arr[j][i] == arr[k][i]) {
					cnt++;
					arr[k][i] = 0;
				}
			}
			if (cnt != 0) {
				pq.push(make_pair(cnt, arr[j][i]));
			}
			arr[j][i] = 0;
		}
		int j = 0;
		while ((!pq.empty())) {
			auto a = pq.top(); pq.pop();
			auto cnt = a.first;
			auto num = a.second;
			arr[j][i] = num;
			j++;
			if (j > 100) break;
			arr[j][i] = cnt;
			j++;
			if (j > 100) break;
		}
		if (yMax < j) yMax = j;
	}
}

void solution(int r, int c, int k) {
	while (arr[r][c] != k) {
		if (answer > 100) {
			answer = -1;
			return;
		}
		if (yMax >= xMax) {
			R();
			answer++;
		}
		else {
			C();
			answer++;
		}
	}
	cout << answer << endl;
}

int main() {
	int r, c, k;
	cin >> r >> c >> k;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];//y,x
		}
	}
	xMax = yMax = 3;
	solution(r-1, c-1, k);
	return 0;
}