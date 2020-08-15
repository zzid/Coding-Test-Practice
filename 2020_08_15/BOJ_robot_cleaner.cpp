#include <bits/stdc++.h>
using namespace std;
int n, m,arr[50][50];
bool visited[50][50] = { 0, };
const int dy[4] = { -1,0,1,0 };
const int dx[4] = { 0,1,0,-1 };
//const int dy[4] = { -1,0,1,0 };
//const int dx[4] = { 0,-1,0,1 };
class robot {
public:
	int y, x, d;
	int cleaned = 0;
	int cnt=0;
	void prints() {
		cout << y << " " << x << endl;
		cout << "Direction : " << d << endl;
	}
};
robot r;
void input() {
	cin >> n >> m;
	cin >> r.y >> r.x >> r.d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
}
void printarr() {
	cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == r.y && j == r.x) {
				cout << "* ";
			}
			else if (visited[i][j] == true) {
				cout << "X ";
			}
			else {
				cout << arr[i][j] << " ";
			}
		}
		cout << endl;
	}
}
void solution() {
	//r.prints();
	//printarr();
	if (visited[r.y][r.x] == false) {
		r.cleaned++;
	}
	visited[r.y][r.x] = true;
	bool blocked = true;
	for (int i = 0; i < 4; i++) {
		if (arr[r.y + dy[i]][r.x + dx[i]] == 0 && visited[r.y + dy[i]][r.x + dx[i]] == false) {
			blocked = false;
		}
	}
	if(blocked){//if (r.cnt >= 4) { // c, d
		int td = r.d - 1;
		if (td < 0) td = 3;
		td--;
		if (td < 0) td = 3;
		if (arr[r.y + dy[td]][r.x + dx[td]] == 1) return;
		else r.y += dy[td]; r.x += dx[td];
		r.cnt = 0;
		solution();
	}
	else {
		/* look left */
		int td = r.d - 1;
		if (td < 0) td = 3;
		int ny = r.y + dy[td];
		int nx = r.x + dx[td];
		if (arr[ny][nx] != 1 && visited[ny][nx] == false) {
			r.y = ny; r.x = nx; r.d = td;
			r.cnt = 0;
			solution();
		}
		else if (visited[ny][nx] == true || arr[ny][nx] == 1) {
			r.d = td;
			r.cnt++;
			solution();
		}
	}
}
int main() {
	input();
	solution();
	cout << r.cleaned << endl;
	return 0;
}