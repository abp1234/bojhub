#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
vector<vector<int>> tasks;
int visited[1 << 20];

int dfs(int row, int visit) {
	if (row == N) {
		return 0;
	}

	if (visited[visit] != -1) {
		return visited[visit];
	}

	int ret = 1000000000;
	for (int i = 0; i < N; ++i) {
		if ((visit & (1 << i)) != 0) {
			continue;
		}
		ret = min(ret, dfs(row + 1, visit | (1 << i)) + tasks[row][i]);
	}

	visited[visit] = ret;
	return visited[visit];
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	tasks.resize(N, vector<int>(N));

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> tasks[i][j];
		}
	}

	memset(visited, -1, sizeof(visited));
	cout << dfs(0, 0) << '\n';

	return 0;
}