#include <bits/stdc++.h>
using namespace std;

int arr[100][100] = { 0, }, sb[100][100] = { 0, };
const int dy[4] = { 0,1,0,-1 }, dx[4] = { 1,0,-1,0 };
int answer =0, fs = 0;
typedef pair <int, int> p;
queue<p> dq, tails;

class snake {
public:
	int hy=0, hx=0, ty=0, tx=0;//head tail;
	int length=1, direction=0;
};

void game(snake* s) {
	int a = s->direction;
	while (1) {
		int x = s->hx; int y = s->hy;
		if (!(dq.empty())) {
			if (dq.front().first == answer) {
				a += dq.front().second;//  dq.pop_front();
				if (a < 0) a = 3;
				a %= 4;
				dq.pop();
			}
		}
		if (sb[y + dy[a]][x + dx[a]] == 1) { answer++;  return; }
		if (y + dy[a] > fs - 1 || y + dy[a] <0 || x + dx[a] >fs - 1 || x + dx[a] < 0) { answer++; return; }
		else {
			s->hy = y + dy[a]; s->hx = x + dx[a]; // move head
			tails.push(make_pair(s->hy, s->hx));
			sb[s->hy][s->hx] = 1;
			if (arr[s->hy][s->hx] == 1) { //if meet apple
				arr[s->hy][s->hx] = 0;// stay the tail
				s->length++;
			}
			else {//nothing there
				sb[s->ty][s->tx] = 0;
				auto a = tails.front();  tails.pop();
				s->ty = a.first; s->tx = a.second;//sb[a.first][a.second]
			}
		}
		answer++;
	}
}

int main() {
	int n,k;
	cin >> n >> k;
	fs = n;
	snake* s = new snake;

	for (int i = 0; i < k; i++) {
		int y,x;
		cin >> y >> x;
		arr[y-1][x-1] = 1;
	}
	sb[s->hy][s->hx] = 1; sb[s->ty][s->tx] = 1;
	int l;
	cin >> l;
	
	for (int i = 0; i < l; i++) {
		int t;
		char c; // L, D(R)
		cin >> t >> c;
		if (c == 'L')	dq.push(make_pair(t,-1));
		else if(c == 'D')	dq.push(make_pair(t, 1));
		
	}
	game(s);
	cout << answer << endl;
	return 0;
}