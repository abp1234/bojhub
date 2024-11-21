#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <tuple>
#include <limits>

using namespace std;

constexpr int INF = numeric_limits<int>::max();

struct E {
	int c, x, y;
};

int n, m;
vector<vector<vector<E>>>g;

int djk(int sx, int sy) {
	vector<vector<int>> d(n + 1, vector<int>(m + 1, INF));
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>>pq;
	pq.emplace(0, sx, sy);
	d[sy][sx] = 0;

	while (!pq.empty()) {
		auto current = pq.top(); pq.pop();
		int c = get<0>(current);
		int x = get<1>(current);
		int y = get<2>(current);
		if (d[y][x] < c)continue;

		for (const auto& edge : g[y][x]) {
			int nc = edge.c;
			int nx = edge.x;
			int ny = edge.y;
			int tmp = c + nc;
			if (d[ny][nx] > tmp) {
				d[ny][nx] = tmp;
				pq.emplace(tmp, nx, ny);
			}
		}
	}
	return d[n][m] < INF ? d[n][m] : -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	g.resize(n + 1, vector<vector<E>>(m + 1));

	for (int i = 0; i < n; ++i) {
		string ln;
		cin >> ln;
		for (int j = 0; j < m; ++j) {
			if (ln[j] == '/') {
				g[i][j + 1].push_back({ 0,j,i + 1 });
				g[i + 1][j].push_back({ 0,j + 1,i });
				g[i][j].push_back({ 1,j + 1,i + 1 });
				g[i + 1][j + 1].push_back({ 1,j,i });
			}
			else {
				g[i][j].push_back({ 0,j + 1,i + 1 });
				g[i + 1][j + 1].push_back({ 0,j,i });
				g[i][j + 1].push_back({ 1,j,i + 1 });
				g[i + 1][j].push_back({ 1,j + 1,i });
			}
		}
	}
	int res = djk(0, 0);
	if (res == -1)cout << "NO SOLUTION\n";
	else cout << res << '\n';

	return 0;
}