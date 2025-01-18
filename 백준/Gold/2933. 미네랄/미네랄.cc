#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

struct Pt {
	int x, y;
};

int r, c, n;
vector<vector<char>> g;

void dm(int y, int t) {
	if (t % 2 == 1) {
		for (int i = c - 1; i >= 0; --i) {
			if (g[y][i] == 'x') {
				g[y][i] = '.';
				break;
			}
		}
	}
	else {
		for (int i = 0; i < c; ++i) {
			if (g[y][i] == 'x') {
				g[y][i] = '.';
				break;
			}
		}
	}
}

pair<vector<Pt>, vector<vector<bool>>> fc() {
	vector<vector<bool>> v(r, vector<bool>(c, false));
	queue<Pt> q;

	for (int i = 0; i < c; ++i) {
		if (g[r - 1][i] == 'x') {
			q.push({ r - 1,i });
			v[r - 1][i] = true;
		}
	}

	while (!q.empty()) {
		Pt p = q.front();
		q.pop();
		int dx[] = { -1,1,0,0 };
		int dy[] = { 0,0,-1,1 };
		for (int d = 0; d < 4; ++d) {
			int nx = p.x + dx[d], ny = p.y + dy[d];
			if (nx >= 0 && nx < r && ny >= 0 && ny < c && !v[nx][ny] && g[nx][ny] == 'x') {
				v[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}

	vector<Pt> cl;
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			if (g[i][j] == 'x' && !v[i][j]) {
				cl.push_back({ i,j });
			}
		}
	}
	return { cl, v };
}

void mc(vector<Pt> cl, vector<vector<bool>> v) {
	int dm = 1e9;
	for (const auto& p : cl) {
		int d = 0;
		for (int i = p.x + 1; i < r; ++i) {
			if (g[i][p.y] == '.') {
				++d;
			}
			else if (v[i][p.y]) {
				break;
			}
			else {
				d = 1e9;
				break;
			}
		}
		dm = min(dm, d);
	}

	for (const auto& p : cl) {
		g[p.x][p.y] = '.';
	}
	for (const auto& p : cl) {
		g[p.x + dm][p.y] = 'x';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> r >> c;
	g.resize(r, vector<char>(c));
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			cin >> g[i][j];
		}
	}

	cin >> n;
	vector<int> h(n);
	for (int i = 0; i < n; ++i) {
		cin >> h[i];
	}

	for (int i = 0; i < n; ++i) {
		dm(r - h[i], i);
		//auto [cl, v] = fc();

		pair<vector<Pt>, vector<vector<bool>>>res = fc();
		vector<Pt> cl = res.first;
		vector<vector<bool>> v = res.second;
		if (!cl.empty()) {
			mc(cl, v);
		}
	}

	for (const auto& row : g) {
		for (const auto& ch : row) {
			cout << ch;
		}
		cout << '\n';
	}
	return 0;

}