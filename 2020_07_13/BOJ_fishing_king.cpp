#include <bits/stdc++.h>

using namespace std;

struct shark {
	int r,c,s,d,z;
};

int main() {
	
	map<pair<int, int>, int> mm;
	int answer = 0;
	int r, c, m;
	cin >> r >> c >> m;
	shark* sh = new shark[m];

	for (int i = 0; i < m; i++) {
		cin >> sh[i].r >> sh[i].c >> sh[i].s >> sh[i].d >> sh[i].z;
	}

	for (int i = 1; i <= c; i++) { ///phase 1
		int temp = r + 1;
		int tempAns = 0;
		int tempIdx = -1;
		//phase 2
		for (int j = 0; j < m; j++) {
			if (i == sh[j].c) {
				if (temp > sh[j].r) {
					temp = sh[j].r;
					tempAns = sh[j].z;
					tempIdx = j;
				}
			}
		}
		if (tempIdx != -1) {
			sh[tempIdx].c = sh[tempIdx].r = sh[tempIdx].d = -1;
			answer += tempAns;
		}

		//phase 3
		for (int j = 0; j < m; j++) {
			if (sh[j].d == 1) {
				int up = sh[j].r - 1;
				int down = r - sh[j].r;
				int mod = sh[j].s % (2 * (r - 1));
				//pivot == 2*(r-1)
				if (mod <= up) {
					sh[j].r -= mod;
				}
				else if (mod <= 2 * up) {
					sh[j].d = 2;
					sh[j].r -= (2 * up - mod);
				}
				else if (mod <= (2 * up) + down) {
					sh[j].d = 2;
					sh[j].r += mod - (2 * up);
				}
				else if (mod < (2 * up) + (2 * down)) {
					sh[j].r += (2 * up) + (2 * down) - mod;
				}
			}
			else if (sh[j].d == 2) {
				int up = sh[j].r - 1;
				int down = r - sh[j].r;
				int mod = sh[j].s % (2 * (r - 1));
				if (mod <= down) {
					sh[j].r += mod;
				}
				else if (mod <= 2 * down) {
					sh[j].d = 1;
					sh[j].r += (2 * down - mod);
				}
				else if (mod <= (2 * down) + up) {
					sh[j].d = 1;
					sh[j].r -= mod - (2 * down);
				}
				else if (mod < (2 * up) + (2 * down)) {
					sh[j].r -= (2 * up) + (2 * down) - mod;
				}
			}
			else if (sh[j].d == 3) {
				int up = sh[j].c - 1; //left
				int down = c - sh[j].c; //right
				int mod = sh[j].s % (2 * (c - 1));
				if (mod <= down) {
					sh[j].c += mod;
				}
				else if (mod <= 2 * down) {
					sh[j].d = 4;
					sh[j].c += (2 * down - mod);
				}
				else if (mod <= (2 * down) + up) {
					sh[j].d = 4;
					sh[j].c -= mod - (2 * down);
				}
				else if (mod < (2 * up) + (2 * down)) {
					sh[j].c -= (2 * up) + (2 * down) - mod;
				}
			}
			else if (sh[j].d == 4) {
				int up = sh[j].c - 1; //left
				int down = c - sh[j].c; //right
				int mod = sh[j].s % (2 * (c - 1));
				if (mod <= up) {
					sh[j].c -= mod;
				}
				else if (mod <= 2 * up) {
					sh[j].d = 3;
					sh[j].c -= (2 * up - mod);
				}
				else if (mod <= (2 * up) + down) {
					sh[j].d = 3;
					sh[j].c += mod - (2 * up);
				}
				else if (mod < (2 * up) + (2 * down)) {
					sh[j].c += (2 * up) + (2 * down) - mod;
				}
			}
            if (sh[j].r != -1 && sh[j].c != -1) {
				auto a = mm.find(make_pair(sh[j].r, sh[j].c));
				if (a == mm.end()) {
					mm.insert(make_pair(make_pair(sh[j].r, sh[j].c), j));
				}
				else {
					if (sh[a->second].z > sh[j].z) {
						sh[j].r = sh[j].c = sh[j].d = -1;
					}
					else {
						sh[a->second].r = sh[a->second].c = sh[a->second].d = -1;
						mm.erase(make_pair(sh[j].r, sh[j].c));
						mm.insert(make_pair(make_pair(sh[j].r, sh[j].c), j));
					}
				}
			}
		}
		mm.clear();
	}
	cout << answer << endl;
	delete[] sh;
	return 0;
}