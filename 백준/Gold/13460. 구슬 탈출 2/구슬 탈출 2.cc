#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Point {
	int x, y;
};

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<char>> grid(n, vector<char>(m));

	Point r_pos, b_pos;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> grid[i][j];
			if (grid[i][j] == 'R') {
				r_pos = { i,j };
			}
			else if (grid[i][j] == 'B') {
				b_pos = { i,j };
			}
		}
	}

	queue < pair<Point, Point>> q;
	q.push({ r_pos, b_pos });

	vector<vector<vector<vector<bool>>>> visited(n, vector<vector<vector<bool>>>(m, vector<vector<bool>>(n, vector<bool>(m, false))));

	visited[r_pos.x][r_pos.y][b_pos.x][b_pos.y] = true;

	int move_count = 0;

	while (!q.empty()) {
		int q_size = q.size();
		if (move_count > 10) {
			cout << -1 << '\n';
			return 0;
		}

		for (int i = 0; i < q_size; ++i) {
			Point r = q.front().first;
			Point b = q.front().second;
			q.pop();

			if (grid[r.x][r.y] == 'O' && grid[b.x][b.y] != 'O') {
				cout << move_count << '\n';
				return 0;
			}
			if (grid[b.x][b.y] == 'O') {
				cout << -1 << '\n';
				return 0;
			}
			for (int dir = 0; dir < 4; ++dir) {
				Point nr = r, nb = b;

				while (grid[nr.x + dx[dir]][nr.y + dy[dir]] != '#' && grid[nr.x][nr.y] != 'O') {
					nr.x += dx[dir];
					nr.y += dy[dir];
				}

				while (grid[nb.x + dx[dir]][nb.y + dy[dir]] != '#' && grid[nb.x][nb.y] != 'O') {
					nb.x += dx[dir];
					nb.y += dy[dir];
				}
				if (grid[nb.x][nb.y] == 'O')continue;

				if (nr.x == nb.x && nr.y == nb.y) {
					if (abs(nr.x - r.x) + abs(nr.y - r.y) > abs(nb.x - b.x) + abs(nb.y - b.y)) {
						nr.x -= dx[dir];
						nr.y -= dy[dir];
					}
					else {
						nb.x -= dx[dir];
						nb.y -= dy[dir];
					}
				}

				if (!visited[nr.x][nr.y][nb.x][nb.y]) {
					q.push({ nr,nb });
					visited[nr.x][nr.y][nb.x][nb.y] = true;
				}
			}
		}
		++move_count;
	}
	cout << -1 << '\n';
	return 0;
}