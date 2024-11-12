#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <limits>

using namespace std;

struct P {
	int x, y;
};

int n, k, ans = 0;
int** dist;
vector<P>g;
int calc(P* c1, P* c2) {
	return (c1->x - c2->x) * (c1->x - c2->x) + (c1->y - c2->y) * (c1 -> y - c2->y);
}

bool bfs(int s, int cnt, int cost) {
	queue<pair<int, int>>q;
	vector<bool> v(n + 2, false);
	v[s] = true;
	q.push({ s,cnt });

	while (!q.empty()) {
		int idx = q.front().first;
		int c = q.front().second;
		q.pop();
		if (idx == n + 1)return true;
		if (c > k)continue;

		for (int i = 1; i < n + 2; i++) {
			if (c <= k && !v[i] && dist[idx][i] <= cost) {
				v[i] = true;
				q.push({ i,c + 1 });
			}
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;
	g.push_back({ 0,0 });
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		g.push_back({ x,y });
	}
	g.push_back({ 10000,10000 });

	dist = new int* [n + 2];
	for (int i = 0; i < n + 2; i++) {
		dist[i] = new int[n + 2];
		for (int j = 0; j < n + 2; j++) {
			if (i == j)
				dist[i][j] = numeric_limits<int>::max();
			else
				dist[i][j] = calc(&g[i], &g[j]);
		}
	}

	int pl = 1, pr = 1415;
	while (pl <= pr) {
		int m = (pl + pr) / 2;
		int cost = m * m * 100;
		if (bfs(0, 0, cost)) {
			pr = m - 1;
			ans = m;
		}
		else {
			pl = m + 1;
		}
	}

	cout << ans << '\n';

	for (int i = 0; i < n + 2; i++)delete[] dist[i];
	delete[] dist;
	return 0;
}