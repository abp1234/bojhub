#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> seq(n);
	for (int i = 0; i < n; ++i) {
		cin >> seq[i];
	}

	bool** dp = new bool* [n];
	for (int i = 0; i < n; ++i) {
		dp[i] = new bool[n]();
	}

	for (int i = 0; i < n; ++i) {
		dp[i][i] = true;
	}
	for (int i = 0; i < n - 1; ++i) {
		if (seq[i] == seq[i + 1]) {
			dp[i][i + 1] = true;
		}
		else {
			dp[i][i + 1] = false;
		}
	}

	for (int cnt = 2; cnt < n; ++cnt) {
		for (int i = 0; i < n - cnt; ++i) {
			int j = i + cnt;
			if (seq[i] == seq[j] && dp[i + 1][j - 1]) {
				dp[i][j] = true;
			}
			else {
				dp[i][j] = false;
			}
		}
	}
	int m;
	cin >> m;

	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		cout << (dp[a - 1][b - 1] ? 1 : 0) << '\n';
	}

	for (int i = 0; i < n; ++i) {
		delete[] dp[i];
	}
	delete[] dp;

	return 0;
}