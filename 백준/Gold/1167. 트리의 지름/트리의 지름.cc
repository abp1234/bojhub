#include <iostream>
#include <vector>
#include <deque>
#include <cstring>

using namespace std;

struct Nd {
	int nxt, dist;
};


vector<Nd> tr[100001];
int vis[100001];

pair<int, int> bfs(int st) {
	deque<pair<int, int>>dq;
	dq.push_back({ st,0 });
	memset(vis, -1, sizeof(vis));
	vis[st] = 0;
	pair<int, int>res = { 0,0 };

	while (!dq.empty()) {
		int cur = dq.front().first;
		int curDist = dq.front().second;
		dq.pop_front();

		for (auto& nxt : tr[cur]) {
			if (vis[nxt.nxt] == -1) {
				int newDist = curDist + nxt.dist;
				dq.push_back({ nxt.nxt,newDist });
				vis[nxt.nxt] = newDist;
				if (res.second < newDist) {
					res.first = nxt.nxt;
					res.second = newDist;
				}
			}
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int V;
	cin >> V;

	for (int i = 0; i < V; i++) {
		int cnt, nxt, dist;
		cin >> cnt;
		while (true) {
			cin >> nxt;
			if (nxt == -1)break;
			cin >> dist;
			tr[cnt].push_back({ nxt,dist });
		}
	}
	pair<int, int> p1 = bfs(1);
	pair<int, int> p2 = bfs(p1.first);
	cout << p2.second << '\n';

	return 0;
}