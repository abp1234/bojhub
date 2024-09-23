#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct PL {
	bool is_p;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;
	int L = s.length();

	vector<int> dp(L + 1, 2500);
	dp[0] = 0;

	vector<vector<PL>> is_p(L, vector<PL>(L, { false }));

	for (int i = 0; i < L; ++i) {
		is_p[i][i].is_p = true;
	}

	for (int i = 1; i < L; ++i) {
		if (s[i - 1] == s[i]) {
			is_p[i - 1][i].is_p = true;
		}
	}

	for (int len = 3; len <= L; ++len) {
		for (int start = 0; start + len <= L; ++start) {
			int end = start + len - 1;
			if (s[start] == s[end] && is_p[start + 1][end - 1].is_p) {
				is_p[start][end].is_p = true;
			}
		}
	}

	for (int end = 1; end <= L; ++end) {
		for (int start = 1; start <= end; ++start) {
			if (is_p[start - 1][end - 1].is_p) {
				dp[end] = min(dp[end], dp[start - 1] + 1);
			}
		}
	}

	cout << dp[L];

}