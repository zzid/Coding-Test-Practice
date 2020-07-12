#include <bits/stdc++.h>
using namespace std;
int answer = 0;

class block {
public:
	int n;
	int arr[20][20];
	void printarr() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << arr[i][j] << " ";

			}
			cout << endl;
		}
		cout << endl;
	}
	int findMax() {
		int max = -1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (max < arr[i][j]) {
					max = arr[i][j];
				}
			}
		}
		return max;
	}
	void combine(int d) { // 4 direction //u,d,l,r

		if (d == 3) {// <<<<<<
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (arr[i][j] != 0) {
						for (int k = j + 1; k < n; k++) {
							if (arr[i][k] != 0) {
								if (arr[i][j] == arr[i][k]) {
									arr[i][j] += arr[i][k];
									arr[i][k] = 0;
								}
								break;
							}
						}
					}
				}
			}
		}
		else if (d == 1) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (arr[j][i] != 0) {
						for (int k = j + 1; k < n; k++) {
							if (arr[k][i] != 0) {
								if (arr[j][i] == arr[k][i]) {
									arr[j][i] += arr[k][i];
									arr[k][i] = 0;
								}
								break;
							}
						}
					}
				}
			}
		}
		else if (d == 2) {
			for (int i = n - 1; i >= 0; i--) {
				for (int j = n - 1; j >= 0; j--) {
					if (arr[j][i] != 0) {
						for (int k = j - 1; k >= 0; k--) {
							if (arr[k][i] != 0) {
								if (arr[j][i] == arr[k][i]) {
									arr[j][i] += arr[k][i];
									arr[k][i] = 0;
								}
								break;
							}
						}
					}
				}
			}
		}
		else if (d == 4) {
			for (int i = n - 1; i >= 0; i--) {
				for (int j = n - 1; j >= 0; j--) {
					if (arr[i][j] != 0) {
						for (int k = j - 1; k >= 0; k--) {
							if (arr[i][k] != 0) {
								if (arr[i][j] == arr[i][k]) {
									arr[i][j] += arr[i][k];
									arr[i][k] = 0;
								}
								break;
							}
						}
					}
				}
			}
		}

	}
	void movement(int d) {
		if (d == 3) {///<<<<<<<<<<<
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (arr[i][j] == 0) {
						for (int k = j + 1; k < n; k++) {
							if (arr[i][k] != 0) {
								arr[i][j] = arr[i][k];
								arr[i][k] = 0;
								break;
							}
						}

					}
				}
			}
		}
		else if (d == 1) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (arr[j][i] == 0) {
						for (int k = j + 1; k < n; k++) {
							if (arr[k][i] != 0) {
								arr[j][i] = arr[k][i];
								arr[k][i] = 0;
								break;
							}
						}

					}
				}
			}
		}
		else if (d == 2) {
			for (int i = n - 1; i >= 0; i--) {
				for (int j = n - 1; j >= 0; j--) {
					if (arr[j][i] == 0) {
						for (int k = j - 1; k >= 0; k--) {
							if (arr[k][i] != 0) {
								arr[j][i] = arr[k][i];
								arr[k][i] = 0;
								break;
							}
						}

					}
				}
			}
		}
		else if (d == 4) {
			for (int i = n - 1; i >= 0; i--) {
				for (int j = n - 1; j >= 0; j--) {
					if (arr[i][j] == 0) {
						for (int k = j - 1; k >= 0; k--) {
							if (arr[i][k] != 0) {
								arr[i][j] = arr[i][k];
								arr[i][k] = 0;
								break;
							}
						}

					}
				}
			}
		}
	}
	void one(int d) {
		combine(d);
		movement(d);
	}
};



void dfs(block b,int times) {
	if (times == 5) {
		int temp = b.findMax();
		if (temp > answer) answer = temp;
		return;
	}
	for (int i = 1; i <= 4; i++) {
		block n = b;
		n.one(i);
		dfs(n, times+1);
	}
}


int main() {
	int n;
	cin >> n;
	block b;
	b.n = n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> b.arr[i][j];
		}
	}
	dfs(b,0);
	cout << answer << endl;
	return 0;
}