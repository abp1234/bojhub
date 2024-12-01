#include <iostream>
#include <vector>
#include <queue>
#include <array>
#include <limits>

using namespace std;

struct Pos {
	int d, x, y;
	bool operator<(const Pos& p)const {
		return d > p.d;
	}
};

int dx[] = { 1,-1,0,0,2,2,-2,-2,1,-1,1,-1,3,-3,0,0 };
int dy[] = { 0,0,1,-1,1,-1,1,-1,2,2,-2,-2,0,0,3,-3 };


int f(int n, int t, vector<vector<int>>& g) {

	vector<vector<int>> dist(n, vector<int>(n, numeric_limits<int>::max()));
	dist[0][0] = 0;

	priority_queue<Pos> pq;
	pq.push({ 0,0,0 });

	while (!pq.empty()) {
		Pos p = pq.top();
		pq.pop();

		for (int k = 0; k < 16; ++k) {
			int nx = p.x + dx[k];
			int ny = p.y + dy[k];

			if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
				int nd = p.d + 3 * t + g[nx][ny];
				if (dist[nx][ny] > nd) {
					dist[nx][ny] = nd;
					pq.push({ nd,nx,ny });
				}
			}
		}
	}


	int res = dist[n - 1][n - 1];
	if (n > 1)res = min(res, dist[n - 2][n - 1] + t);
	if (n > 1)res = min(res, dist[n - 1][n - 2]);
	if (n > 2)res = min(res, dist[n - 3][n - 1] + 2 * t);
	if (n > 2)res = min(res, dist[n - 2][n - 2] + 2 * t);
	if (n > 2)res = min(res, dist[n - 2][n - 2] + 2 * t);
	if (n > 2)res = min(res, dist[n - 1][n - 3] + 2 * t);

	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, t;
	cin >> n >> t;

	vector<vector<int>>g(n, vector<int>(n));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> g[i][j];
		}
	}
	cout << f(n, t, g) << '\n';
	return 0;
}