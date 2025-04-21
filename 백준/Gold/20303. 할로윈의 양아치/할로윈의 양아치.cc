#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Group {
	int parent;
	int friends;
	int candies;
};

int find(vector<Group>& groups, int a) {
	if (groups[a].parent != a) {
		groups[a].parent = find(groups, groups[a].parent);
	}

	return groups[a].parent;
}

void union_groups(vector < Group>& groups, int x, int y){
	x = find(groups, x);
	y = find(groups, y);

	if (x != y) {
		if (x < y)swap(x, y);
		groups[x].parent = y;
	}
}

void robbing(vector<Group>& groups, vector<int>& dp, int N, int K) {
	for (int i = 1; i <= N; ++i) {
		if (i != groups[i].parent) {
			continue;
		}

		for (int j = K - 1; j >= groups[i].friends; --j) {
			dp[j] = max(dp[j], dp[j - groups[i].friends] + groups[i].candies);
		}
	}
}

int main() {
	int N, M, K;
	cin >> N >> M >> K;

	vector<Group> groups(N + 1);

	for (int i = 1; i <= N; ++i) {
		int candy;
		cin >> candy;
		groups[i] = { i, 1, candy };
	}

	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		union_groups(groups, a, b);
	}

	for (int i = 1; i <= N; ++i) {
		int root = find(groups, i);
		if (root != i) {
			groups[root].candies += groups[i].candies;
			groups[root].friends += groups[i].friends;
		}
	}

	vector<int> dp(K, 0);

	robbing(groups, dp, N, K);

	cout << *max_element(dp.begin(), dp.end()) << '\n';

	return 0;

}