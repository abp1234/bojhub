#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

struct E {
	int nd, tm, ct;
};

int dja(int n, int t, int m, vector<E>* g) {
	using P = pair<int, pair<int, int>>;
	priority_queue < P, vector<P>, greater<P>> pq;
	int** vis = new int* [n + 1];

	for (int i = 0; i <= n; i++) {
		vis[i] = new int[m + 1];
		memset(vis[i], 0x3f, sizeof(int) * (m + 1));
	}

	pq.push({ 0,{0,1} });
	vis[1][0] = 0;

	while (!pq.empty()) {
		int c = pq.top().first;
		int tm = pq.top().second.first;
		int nd = pq.top().second.second;
		pq.pop();

		if (vis[nd][c] < tm)continue;

		if (nd == n) {
			for (int i = 0; i <= n; i++) delete[] vis[i];
			delete[] vis;
			return c;
		}

		for (E e : g[nd]) {
			int nt = tm + e.tm;
			int nc = c + e.ct;
			if (nt > t || nc > m)continue;

			if (vis[e.nd][nc] > nt) {
				vis[e.nd][nc] = nt;
				pq.push({ nc,{nt,e.nd} });
			}
		}
	}
	for (int i = 0; i <= n; i++) delete[] vis[i];
	delete[] vis;

	return -1;

}

int main() {
	int n, t, m, l;
	cin >> n >> t >> m >> l;

	vector<E>* g = new vector<E>[n + 1];

	for (int i = 0; i < l; i++) {
		int a, b, tm, ct;
		cin >> a >> b >> tm >> ct;
		g[a].push_back({ b,tm,ct });
		g[b].push_back({ a,tm,ct });
	}

	cout << dja(n, t, m, g) << '\n';

	delete[] g;
	return 0;


}