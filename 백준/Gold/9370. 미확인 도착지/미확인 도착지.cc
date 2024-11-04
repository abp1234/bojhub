#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;
const int INF = 1'000'000'000;
struct Edg {
	int nd, wt;
	Edg(int n, int w) : nd(n), wt(w) {};
};

vector<int> dj(int st, vector<vector<Edg*>>& gr, int n) {
	vector<int> dis(n + 1, INF);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
	pq.push({ 0,st });
	dis[st] = 0;
	while (!pq.empty()) {
		int dist = pq.top().first;
		int now = pq.top().second;
		pq.pop();
		if (dis[now] < dist)continue;
		for (auto e : gr[now]) {
			int cost = dist + e->wt;

			if (cost < dis[e->nd]) {
				dis[e->nd] = cost;
				pq.push({ cost, e->nd });
			}
		}
	}
	return dis;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n, m, t;
		cin >> n >> m >> t;
		int s, g, h;
		cin >> s >> g >> h;

		vector<vector<Edg*>>gr(n + 1);
		vector<int>en;

		for (int i = 0; i < m; i++) {
			int a, b, d;
			cin >> a >> b >> d;
			gr[a].push_back(new Edg(b, d));
			gr[b].push_back(new Edg(a, d));
		}

		for (int i = 0; i < t; i++) {
			int tmp;
			cin >> tmp;
			en.push_back(tmp);
		}

		vector<int> Ds = dj(s, gr, n);
		vector<int> Dg = dj(g, gr, n);
		vector<int> Dh = dj(h, gr, n);

		vector<int> res;
		for (int e : en) {
			if (Ds[g] != INF&& Dg[h] != INF && Dh[e] != INF && Ds[g] + Dg[h] + Dh[e] == Ds[e] || Ds[g] != INF && Dg[h] != INF && Dh[e] != INF && Ds[h] + Dh[g] + Dg[e] == Ds[e]) {
				res.push_back(e);
			}
		}
		sort(res.begin(), res.end());
		for (int r : res) {
			cout << r << " ";
		}
		cout << '\n';
	}
	return 0;
}