#include <bits/stdc++.h>

using namespace std;

int n, answer = 0;//,t,p;
class task{
public:
	int ts, value;
};
class delivery {
public:
	int timestamp, ans;
};
task tasks[16];

void input() {
	int tt, pp;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> tt >> pp;
		task ta;
		ta.ts = tt;
		ta.value = pp;
		tasks[i] = ta;
	}
}
void D(delivery* d) {
	int timestamp = d->timestamp;
	d->timestamp += tasks[timestamp].ts;;
	if (d->timestamp <= n + 1){
		d->ans += tasks[timestamp].value;
	}
}
void skip(delivery* d) {
	d->timestamp++;
}
void DoOrNot(delivery* d) {
	if (d->timestamp < n+1 ) {
		delivery* d1 = new delivery;
		delivery* d2 = new delivery;
		d1->timestamp = d->timestamp; d1->ans = d->ans;
		d2->timestamp = d->timestamp; d2->ans = d->ans;
		D(d1);
		DoOrNot(d1);
		skip(d2);
		DoOrNot(d2);
	}
	else {
		if (d->ans > answer) {
			answer = d->ans;
		}
		return;
	}
}



int main() {
	input();
	delivery* de = new delivery;
	de->ans = 0; de->timestamp = 1;
	DoOrNot(de);
	cout << answer << endl;
	return 0;
}