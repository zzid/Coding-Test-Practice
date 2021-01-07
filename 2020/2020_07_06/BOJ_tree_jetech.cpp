#include <bits/stdc++.h>
using namespace std;
int farm[11][11], s2d2[11][11];
const int dy[8] = { -1,-1,0,1,1,1,0,-1 };
const int dx[8] = { 0,1,1,1,0,-1,-1,-1 };
int answer = 0, n, m, k;

deque<int> trees[10][10];

void SpringSummer() {
	deque<int>::iterator k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (k = trees[i][j].begin(); k < trees[i][j].end(); k++) {
				if (farm[i][j] >= (*k)) {
					farm[i][j] -= (*k);
					(*k)++;
				}
				else break;
			}
			/*			summer			*/
			int num = trees[i][j].end() - k;
			for (; k < trees[i][j].end(); k++) {
				farm[i][j] += (*k) / 2;
			}
			for (; num > 0; num--) {
				trees[i][j].pop_back();
			}
		}

	}
}

void fall() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (auto k = trees[i][j].begin(); k < trees[i][j].end(); k++) {
				if ((*k) % 5 == 0) {
					for (int a = 0; a < 8; a++) {
						if (i + dy[a] < n && i + dy[a] >= 0 && j + dx[a] < n && j + dx[a] >= 0) {
							trees[i + dy[a]][j + dx[a]].push_front(1);
						}
					}
				}
			}
		}
	}
}

void winter() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			farm[i][j] += s2d2[i][j];
		}
	}
}


void solution() {
    for (int i = 0; i < k; i++){
        SpringSummer();
        fall();
        winter();
    }

    for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			answer += trees[i][j].size();
		}
	}
    cout << answer << endl;
}

void init(){
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> s2d2[i][j]; //r : y | c : x start from 1
		}
	}
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		trees[a-1][b-1].push_front(c);
	}
    for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			farm[i][j] = 5;
		}
	}
}

int main() {
    init();
	solution();
	return 0;
}