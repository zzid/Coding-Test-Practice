#include <bits/stdc++.h>

using namespace std;

int arr[50][50] = { 0, }, contarr[50][50] = { 0, };
const int dirx[4] = { 1,0,-1,0 }, diry[4] = { 0,1,0,-1 };
struct info {
	int x,y,value;
	info(int x, int y, int value) {
		this->x = x;
		this->y = y;
		this->value = value;
	}
};
vector<info> vec;
void wind(int r, int c, int a1, int a2) {//fresh the air
	for (int i = a1; i >= 1; i--) {
		if (arr[i][0] != -1) {
			arr[i][0] = arr[i - 1][0];
		}
	}// ||
	for (int i = a2; i < r-1; i++) {
		if (arr[i][0] != -1) {
			arr[i][0] = arr[i + 1][0];
		}
	}
	////////////////||||
	for (int i = 0; i <c-1; i++) {
		arr[0][i] = arr[0][i+1];
		arr[r-1][i] = arr[r-1][i + 1];
	}
	/////////////---------------
	for (int i = 0; i <a1; i++) {
		arr[i][c - 1] = arr[i + 1][c - 1];
	}
	for (int i = r-1; i >a2; i--) {
		arr[i][c - 1] = arr[i-1][c - 1];
	}
	///////////||||||
	for (int i = c - 1; i > 0; i--) {
		if (arr[a1][i-1] != -1) arr[a1][i] = arr[a1][i-1];
		else  arr[a1][i] = 0;
        
		if (arr[a2][i - 1] != -1) arr[a2][i] = arr[a2][i - 1];
		else arr[a2][i] = 0;
	}
}

void redraw() {
	for (auto i : vec) {
		arr[i.x][i.y] += i.value;
	}
	vec.clear();
}
void conta(int i, int j, int r, int c, int a1, int a2) {
	int a = 4;
	for (int k = 0; k < 4; k++) {
		if (i + dirx[k] <0 || i + dirx[k] >r - 1) { a--; }
		else if (j + diry[k] <0 || j + diry[k] > c - 1) { a--; }
		else if (i + dirx[k] ==a1 &&j + diry[k] ==0){ a--; }
		else if (i + dirx[k] == a2 && j + diry[k] == 0) { a--; }
		else{
			info* in = new info(i + dirx[k], j + diry[k], (arr[i][j] / 5));
			vec.push_back(*in);
		}
	}
	int b = arr[i][j] - (arr[i][j] / 5) * a;
	info* in = new info(i, j, b);
	vec.push_back(*in);
	arr[i][j] = 0;
}

int main() {
	int r, c, t;
	cin >> r >> c >> t;
	int air1 = 0;
	int air2 = 0;
	int answer = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == -1) {
				if (air1 == 0) air1 = i;
				else air2 = i;//x
			}
		}
	}
	for (int k = 0; k < t; k++) {
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (arr[i][j] != 0) conta(i, j, r, c, air1, air2);
			}
		}
		redraw();
		wind(r, c, air1, air2);

	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			answer += arr[i][j];
		}
	}
	cout << answer+2 << endl;

}
