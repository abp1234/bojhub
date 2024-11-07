#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm> 
using namespace std;

struct Cmp {
	int t;
	int c;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<vector<Cmp>> adj(n + 1);
	vector<vector<int>> req(n + 1, vector<int>(n + 1, 0));
	vector<int>deg(n + 1, 0);
	queue<int>q;

	int m;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[b].push_back({ a,c });
		deg[a]++;
	}

	for (int i = 1; i <= n; ++i) {
		if (deg[i] == 0)
			q.push(i);
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (auto& nxt : adj[cur]) {
			int nxt_num = nxt.t;
			int need = nxt.c;

			if (count(req[cur].begin(), req[cur].end(), 0) == n + 1) {
				req[nxt_num][cur] += need;
			}
			else {
				for (int i = 1; i <= n; ++i) {
					req[nxt_num][i] += req[cur][i] * need;
				}
			}

			deg[nxt_num]--;
			if (deg[nxt_num] == 0) {
				q.push(nxt_num);
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		if (req[n][i] > 0) {
			cout << i << " " << req[n][i] << '\n';
		}
	}
	return 0;
}