#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct DP {
	int ***arr;
};

int n;
int** arr;
DP* dp;

int dfs(int now, int art, int cost) {
	if (dp->arr[now][art][cost] != 0) {
		return dp->arr[now][art][cost];
	}

	int cnt = 0;
	for (int i = 1; i < n; i++) {
		if (arr[art][i] >= cost && !(now & (1 << i))) {
			cnt = max(cnt, 1 + dfs(now | (1 << i), i, arr[art][i]));
		}
	}
	dp->arr[now][art][cost] = cnt;
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;

	arr = new int* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[n];
		string k;
		cin >> k;
		for (int j = 0; j < n; j++) {
			arr[i][j] = k[j] - '0';
		}
	}
	dp = new DP();
	dp->arr = new int** [1 << n];
	for (int i = 0; i < (1 << n); i++) {
		dp->arr[i] = new int* [n];
		for (int j = 0; j < n; j++) {
			dp->arr[i][j] = new int[10];
			fill(dp->arr[i][j], dp->arr[i][j] + 10, 0);
		}
	}
	cout << dfs(1, 0, 0) + 1 << '\n';

	for (int i = 0; i < (1<<n); i++) {
		for (int j = 0; j < n; j++) {
			delete[] dp->arr[i][j];
		}
		delete[] dp->arr[i];
	}
	delete[] dp->arr;
	delete dp;

	for (int i = 0; i < n; i++) {
		delete[] arr[i];
	}
	delete[] arr;

	return 0;

}