#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

struct DT {
	int** d, ** dp;
	int n, m;
	DT(int rows, int cols):n(rows),m(cols) {
		d = new int* [n];
		dp = new int* [n];
		for (int i = 0; i < n; ++i) {
			d[i] = new int[m];
			dp[i] = new int[m];
			memset(dp[i], 0, m * sizeof(int));
		}
	}
	~DT() {
		for (int i = 0; i < n; ++i) {
			delete[] d[i];
			delete[] dp[i];
		}
		delete[] d;
		delete[] dp;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	DT dt(n, m);
	
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> dt.d[i][j];
	dt.dp[0][0] = dt.d[0][0];
	for (int j = 1; j < m; ++j)
		dt.dp[0][j] = dt.dp[0][j - 1] + dt.d[0][j];

	for (int i = 1; i < n; ++i) {
		vector<int> l(m, 0), r(m, 0);

		l[0] = dt.dp[i - 1][0] + dt.d[i][0];
		for (int j = 1; j < m; ++j)
			l[j] = max(dt.dp[i - 1][j], l[j - 1]) + dt.d[i][j];

		r[m - 1] = dt.dp[i - 1][m - 1] + dt.d[i][m - 1];
		for (int j = m - 2; j >= 0; --j)
			r[j] = max(dt.dp[i - 1][j], r[j + 1]) + dt.d[i][j];

		for (int j = 0; j < m; ++j)
			dt.dp[i][j] = max(l[j], r[j]);
	}

	cout << dt.dp[n - 1][m - 1] << '\n';

	return 0;
}