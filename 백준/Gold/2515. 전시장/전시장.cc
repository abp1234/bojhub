#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const int INF = INT_MAX;

struct Picture {
	int x, y;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, s;
	cin >> n >> s;
	vector<Picture> pictures(n + 1, { 0,0 });

	for (int i = 1; i <= n; ++i) {
		cin >> pictures[i].x >> pictures[i].y;
	}

	sort(pictures.begin() + 1, pictures.end(), [](const Picture& a, const Picture& b) {
		return a.x == b.x ? a.y > b.y : a.x < b.x;
		});

	vector<int> dp(n + 1, -INF);
	dp[0] = 0;
	int prev_max = 0, prev_idx = 0;

	for (int i = 1; i <= n; ++i) {
		for (int j = prev_idx; j < i; ++j) {
			if (pictures[i].x - pictures[j].x < s) {
				break;
			}
			prev_idx = j;
			prev_max = max(prev_max, dp[j]);
		}
		dp[i] = max(dp[i], prev_max + pictures[i].y);
	}

	int result = *max_element(dp.begin(), dp.end());
	cout << result << '\n';
	return 0;

}