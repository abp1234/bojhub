#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, l, r;
	cin >> n >> l >> r;

	vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>(n + 1, vector<long long>(n + 1, 0)));
	dp[1][1][1] = 1;

	for (int i = 1; i < n; ++i) {
		for (int j = 1; j <= i; ++j) {
			for (int k = 1; k <= i; ++k) {
				if (dp[i][j][k] == 0)continue;

				dp[i + 1][j + 1][k] = (dp[i + 1][j + 1][k] + dp[i][j][k]) % MOD;
				dp[i + 1][j][k + 1] = (dp[i + 1][j][k + 1] + dp[i][j][k]) % MOD;
				dp[i + 1][j][k] = (dp[i + 1][j][k] + dp[i][j][k] * (i - 1)) % MOD;

			}
		}
	}

	cout << dp[n][l][r] << '\n';
	return 0;
}