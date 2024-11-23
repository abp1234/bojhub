#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

struct P {
	int x, y;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;

	vector<P> c(n);
	for (int i = 0; i < n; ++i) {
		cin >> c[i].x >> c[i].y;
		if (c[i].y < 0)c[i].y *= -1;
	}

	sort(c.begin(), c.end(), [](const P& a, const P& b) {
		return a.x < b.x;
		});

	c.insert(c.begin(), { INT_MIN / 2,INT_MIN / 2 });
	vector<int> dp(n + 1, INT_MAX);
	dp[0] = 0;

	for (int i = 1; i <= n; ++i) {
		dp[i] = dp[i - 1] + c[i].y * 2;
		int ym = c[i].y * 2;

		for (int j = i - 1; j > 0; --j) {
			ym = max(c[j].y * 2, ym);
			int ml = max(c[i].x - c[j].x, ym);
			dp[i] = min(dp[i], dp[j - 1] + ml);
		}
	}
	cout << dp[n] << '\n';
	return 0;
}