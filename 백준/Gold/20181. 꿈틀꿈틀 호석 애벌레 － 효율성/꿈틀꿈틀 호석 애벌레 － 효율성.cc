#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct St {
	int dp;
	int lmax;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i)cin >> arr[i];

	vector<St> dp(n, { 0,0 });
	int lm = 0, ans = 0;
	int tmp = 0;
	int l = 0, r = 0;

	while (true) {
		if (tmp >= k) {
			lm = (l == 0) ? 0 : max(lm, dp[l - 1].dp);
			dp[r - 1].dp = max(dp[r - 1].dp, lm + tmp - k);
			tmp -= arr[l];
			l += 1;
		}
		else if (r == n)break;
		else {
			tmp += arr[r];
			r += 1;
		}
	}

	for (int i = 0; i < n; ++i) {
		ans = max(ans, dp[i].dp);
	}

	cout << ans << '\n';
	return 0;


}