#include <bits/stdc++.h>
using namespace std;
const int dy[4] = { 0,0,-1,1 };
const int dx[4] = { 1,-1,0,0 };
char arr[10][10];
class ball {
public:
	int ry, rx, by, bx, count;
};
queue<ball> q;
ball b;

int bfs() {
	int visited[10][10][10][10] = { 0, };
	visited[b.ry][b.rx][b.by][b.bx] = 1;
	b.count = 0;
	q.push(b);
	int answer = -1;
	while (!(q.empty())) {
		ball a = q.front(); q.pop();
		if (a.count > 10) break;
		if (arr[a.ry][a.rx] == 'O' && arr[a.by][a.bx] != 'O') {
			answer = a.count;
			break;
		}


		for (int i = 0; i < 4; i++) {
			int n_ry = a.ry; int n_rx = a.rx;
			int n_by = a.by; int n_bx = a.bx;

			while (1) {
				if (arr[n_ry][n_rx] != '#' && arr[n_ry][n_rx] != 'O') {
					n_ry += dy[i]; n_rx += dx[i];
				}
				else {
					if (arr[n_ry][n_rx] == '#') {
						n_ry -= dy[i]; n_rx -= dx[i];
					}
					break;
				}
			}
			while (1) {
				if (arr[n_by][n_bx] != '#' && arr[n_by][n_bx] != 'O') {
					n_by += dy[i]; n_bx += dx[i];
				}
				else {
					if (arr[n_by][n_bx] == '#') {
						n_by -= dy[i]; n_bx -= dx[i];
					}
					break;
				}
			}
			if (n_rx == n_bx && n_ry == n_by) {
				if (arr[n_ry][n_rx] != 'O') {
					int rd = abs(a.rx - n_rx) + abs(a.ry - n_ry);
					int bd = abs(a.bx - n_bx) + abs(a.by - n_by);
					if (rd > bd) {
						n_ry -= dy[i]; n_rx -= dx[i];
					}
					else {
						n_by -= dy[i]; n_bx -= dx[i];
					}
				}
			}
			if (visited[n_ry][n_rx][n_by][n_bx] != 1) {
				visited[n_ry][n_rx][n_by][n_bx] = 1;
				ball n;
				n.ry = n_ry; n.rx = n_rx;
				n.by = n_by; n.bx = n_bx;
				n.count = a.count + 1;
				q.push(n);
			}

		}
	}
	return answer;
}


int main() {
	int n, m;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'R') {
				b.rx = j; b.ry = i;
			}
			else if (arr[i][j] == 'B') {
				b.bx = j; b.by = i;
			}
		}
	}

	int answer = bfs();
	cout << answer << endl;
	return 0;
}