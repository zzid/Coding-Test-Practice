#include <bits/stdc++.h>
using namespace std;

int n, l, r,answer = 0, temp =0, arr[51][51] = { 0, };
bool visited[50][50] = { 0, } ,any = false;
const int dy[4] = { -1,1,0,0 }, dx[4] = { 0,0,-1,1 };
typedef pair<int, int> p;
deque<p> q, visit;

bool fullvisit() {
	bool flag = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == 0) flag = false;
		}
	}
	return flag;
}
void visitedClear() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = false;
		}
	}
}
void input() {
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			visit.push_back(make_pair(i, j));
		}
	}
}
void makeUnion(int y, int x) {
	if (visited[y][x] == true) return;
	visited[y][x] = true;
	temp += arr[y][x];
	for (int i = 0; i < 4; i++) {
		if (y + dy[i] < n && y + dy[i] >= 0 && x + dx[i] < n && x+dx[i] >= 0) {
			if (abs(arr[y][x] - arr[y + dy[i]][x + dx[i]]) <= r && abs(arr[y][x] - arr[y + dy[i]][x + dx[i]]) >= l &&  visited[y + dy[i]][x + dx[i]]==false) {
				any = true;
				q.push_back(make_pair(y + dy[i], x + dx[i]));
				makeUnion(y + dy[i], x + dx[i]);
			}
		}
	}
}
void solution() {
	bool end_flag = true;
	while (1) {
		any = false;
		deque<p> li;
		li.assign(visit.begin(), visit.end());
		while ((!li.empty())) {
			temp = 0;
			end_flag = true;
			while ((!li.empty())) {
				auto a = li.front();
				if (visited[a.first][a.second] == false) {
					q.push_back(make_pair(a.first, a.second));
					li.pop_front();
					makeUnion(a.first, a.second);
					break;
				}
				else li.pop_front();
			}
			int cnt = q.size();
			if (cnt > 1) {
				//population move
				while ((!q.empty())) {
					auto a = q.front(); q.pop_front();
					arr[a.first][a.second] = temp / cnt;
					end_flag = false;
				}
			}
			q.clear();
		}
		visitedClear();
		if (any == false) break;
		answer++;
	}
	cout << answer << endl;
}
int main() {
	input();
	solution();
	return 0;
}