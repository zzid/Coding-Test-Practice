#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> p;
int arr[20][20] = { 0, };
const int dy[4] = { 0,0,-1,1 }, dx[4] = { 1,-1,0,0 };
int n, m, y, x, k;

queue<int> q;

class cube {
public:
	int y, x;
	int value[7] = { 0, };
};

void move(cube* c) {
	while ((!q.empty())) {
		int a = q.front(); q.pop();
		int y = c->y + dy[a - 1];
		int x = c->x + dx[a - 1];
		if (y < n && y >= 0 && x < m && x >= 0) {
			c->y = y; c->x = x;

			if (a == 1) {
				int temp = c->value[1],
                    temp2 = c->value[3],
                    temp3 = c->value[6],
                    temp4 = c->value[4];
				c->value[4] = temp;
				c->value[1] = temp2;
				c->value[3] = temp3;
				c->value[6] = temp4;
			}
			else if (a == 2) {
				int temp = c->value[6],
                    temp2 = c->value[4],
                    temp3 = c->value[1],
                    temp4 = c->value[3];
				c->value[4] = temp;
				c->value[1] = temp2;
				c->value[3] = temp3;
				c->value[6] = temp4;
			}
			else if (a == 3) {
				int temp = c->value[6],
                    temp2 = c->value[2],
                    temp3 = c->value[1],
                    temp4 = c->value[5];
				c->value[2] = temp;
				c->value[1] = temp2;
				c->value[5] = temp3;
				c->value[6] = temp4;
			}
			else if (a == 4) {
				int temp = c->value[1],
                    temp2 = c->value[5],
                    temp3 = c->value[6],
                    temp4 = c->value[2];
				c->value[2] = temp;
				c->value[1] = temp2;
				c->value[5] = temp3;
				c->value[6] = temp4;
			}

			if (arr[y][x] == 0) {
				arr[y][x] = c->value[1];
			}
			else{
				c->value[1] = arr[y][x];
				arr[y][x] = 0;
			}
		}
		else continue;
		
		int i = c->value[6];
		cout << i << endl;
	}
}

int main() {
	cin >> n >> m >> y >> x >> k;
	cube* c = new cube;
	c->y = y; c->x = x;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < k; i++) {
		int t;
		cin >> t;
		q.push(t);
	}
	move(c);

	return 0;
}