#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include <climits>

using namespace std;

const int MAX_N = 1000;


int n, m;
vector<int> man(MAX_N);
vector<int> woman(MAX_N);
int dp[MAX_N + 1][MAX_N + 1];

void init(int N, int M, vector<int>& men, vector<int>& women) {
	n = N;
	m = M;
	man = men;
	woman = women;

	sort(man.begin(), man.begin() + n);
	sort(woman.begin(), woman.begin() + m);

	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= m; ++j) {
			dp[i][j] = 0;
		}
	}
	dp[0][0] = 0;
}

int cal() {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			dp[i][j] = dp[i - 1][j - 1] + abs(man[i - 1] - woman[j - 1]);
			if (i > j) {
				dp[i][j] = min(dp[i][j], dp[i - 1][j]);
			}
			else if (i < j) {
				dp[i][j] = min(dp[i][j], dp[i][j - 1]);
			}
		}
	}
	return dp[n][m];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;

	vector<int> men(N);
	vector<int> women(M);
	for (int i = 0; i < N; ++i)cin >> men[i];
	for (int i = 0; i < M; ++i)cin >> women[i];

	init(N, M, men, women);
	cout << cal() << '\n';
	return 0;
}