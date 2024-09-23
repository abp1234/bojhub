#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MOD = 1000000000;
const int num_range = 10;
const int bit_range = 1 << num_range;

struct DPState
{
	long long dp[num_range][bit_range];
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<DPState*> DP(n + 1);
	for (int i = 0; i <= n; ++i) {
		DP[i] = new DPState();
		memset(DP[i]->dp, 0, sizeof(DP[i]->dp));
	}

	for (int k = 1; k < num_range; ++k) {
		DP[1]->dp[k][1 << k] = 1;
	}
	DP[1]->dp[0][1] = 1;

	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < num_range; ++j) {
			for (int b = 0; b < bit_range; ++b) {
				if (DP[i]->dp[j][b] == 0)continue;
				if (j < num_range - 1) {
					int next_bit = b | (1 << (j + 1));
					DP[i + 1]->dp[j + 1][next_bit] = (DP[i + 1]->dp[j + 1][next_bit] + DP[i]->dp[j][b]) % MOD;
				}
				if (j > 0) {
					int next_bit = b | (1 << (j - 1));
					DP[i + 1]->dp[j - 1][next_bit] = (DP[i + 1]->dp[j - 1][next_bit] + DP[i]->dp[j][b]) % MOD;
				}
			}
		}
	}

	long long total = 0;
	for (int k = 1; k < num_range; ++k) {
		total = (total + DP[n]->dp[k][bit_range - 1]) % MOD;
	}
	cout << total << '\n';
	for (int i = 0; i <= n; ++i) {
		delete DP[i];
	}
	return 0;
}