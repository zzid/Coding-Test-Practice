#include <bits/stdc++.h>
using namespace std;
int n, answer = 0;
bool arr[101][101] = { 0, };
const int op[4] = { 2,3,0,1 }, rot[4] = { 3,0,1,2 },
        recty[4] = {0, 0,1,1 }, rectx[4] = {0,1,0,1 },
        dy[4] = { 0,-1,0,1 }, dx[4] = { 1,0,-1,0 };
typedef pair<int, int> p;
class dragon {
public:
	int y, x, d, g;
	deque<int> path;
	dragon(int a, int b, int c, int z) {
		x = a;
		y = b;
		d = c;
		g = z;
	}
};
deque<dragon*> ds;
void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y, di, g;
		cin >> x >> y >> di >> g;
		dragon* dr = new dragon(x,y,di,g);
		arr[dr->y][dr->x] = true;
		ds.push_back(dr);
	}
}
void init() { // 0th generation
	int s = ds.size();
	for (int i = 0; i < s; i++) {
		ds[i]->y += dy[ds[i]->d]; ds[i]->x += dx[ds[i]->d];
		arr[ds[i]->y][ds[i]->x] = true;
		ds[i]->path.push_back(op[ds[i]->d]);
	}
	
}
int findRect() { // end()-2 ~begin()
	int temp = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			bool isRect = true;
			for (int k = 0; k < 4; k++) {
				if (arr[i + recty[k]][j + rectx[k]] == 0) isRect = false;
			}
			if (isRect) temp++;
		}
	}
	return temp;
}
void solution() {
	init();
	while (!ds.empty()) {
		auto d = ds.front(); ds.pop_front(); //dragons list
		for (int g = 0; g < d->g; g++) {// generation time
			int a = d->path.size();
			queue<int> temp;
			for (int i = a - 1; i >= 0; i--) {
				int td = rot[d->path[i]]; // 90 rotete
				d->y += dy[td]; d->x += dx[td]; //move
				arr[d->y][d->x] = true;
				temp.push(op[td]); // push to path list
			}
			while (!temp.empty()) {
				d->path.push_back(temp.front());
				temp.pop();
			}
		}
	}
	cout << findRect() << endl;
}

int main() {
	input();
	solution();
	return 0;
}