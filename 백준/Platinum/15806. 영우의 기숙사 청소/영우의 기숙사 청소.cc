#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX_N = 300;
const int INF = 10001;

int n, m, k, t;
int dx[8] = { -2,-2,-1,-1,1,1,2,2 };
int dy[8] = { -1,1,-2,2,-2,2,-1,1 };
int room[2][MAX_N + 1][MAX_N + 1];
vector<pair<int, int>> mold;
vector<pair<int, int>>checkArea;

void bfs() {
	queue<tuple<int, int, int>>q;

	for (const auto& pos : mold) {
		int x = pos.first, y = pos.second;
		q.push(make_tuple( x,y,0 ));
	}

	while (!q.empty()) {
		tuple<int,int,int> front = q.front();
		q.pop();

		int x = get<0>(front);
		int y = get<1>(front);
		int dis = get<2>(front);

		if (dis >= INF) continue;

		for (int dir = 0; dir < 8; ++dir) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx <= 0 || nx > n || ny <= 0 || ny > n)continue;

			if (room[(dis + 1) % 2][nx][ny] == INF) {
				room[(dis + 1) % 2][nx][ny] = dis + 1;
				q.push(make_tuple( nx,ny,dis + 1 ));
			}
		}
	}
}

bool checkClean() {
	for (auto& pos : checkArea) {
		int x = pos.first, y = pos.second;
		if (room[t % 2][x][y] <= t) {
			return true;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> k >> t;

	for (int i = 0; i <= 1; ++i) {
		for (int j = 0; j <= n; ++j) {
			fill(room[i][j], room[i][j] + n + 1, INF);
		}
	}

	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		mold.push_back(make_pair(x,y));
	}

	for (int i = 0; i < k; ++i) {
		int x, y;
		cin >> x >> y;
		checkArea.push_back(make_pair(x, y));
	}

	bfs();

	if (checkClean()) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}
	return 0;
}