#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct Coin {
	int c;
	int n;
};

bool dp[500001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int t = 0; t < 3; ++t) {
		int total = 0;
		vector<Coin> coins;
		int k;
		cin >> k;

		for (int i = 0; i < k; ++i) {
			int c, n;
			cin >> c >> n;
			total += c * n;
			coins.push_back({ c,n });
		}

		if (total % 2 == 1) {
			cout << 0 << '\n';
			continue;
		}
		total /= 2;
		memset(dp, 0, sizeof(dp));
		dp[0] = true;

		bool found = false;

		for (const auto& coin : coins) {
			for (int j = total; j >= coin.c; --j) {
				if (dp[j - coin.c]) {
					for (int k = 0; k < coin.n && j + k * coin.c <= total; ++k) {
						dp[j + k * coin.c] = true;
					}
				}
			}
			if (dp[total]) {
				found = true;
				break;
			}
		}
		cout << (found ? 1 : 0) << '\n';
	}
	return 0;
}