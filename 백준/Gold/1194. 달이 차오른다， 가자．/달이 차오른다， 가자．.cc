#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

struct Pos {
	int x, y, steps, keys;
};

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

bool hasKey(int k, char door) {
	return k & (1 << (door - 'A'));
}

int bfs(int sx, int sy, vector<string>& grid, int N, int M) {
	queue<Pos> q;
	q.push({ sx,sy,0,0 });
	vector<vector<vector<bool>>> visited(N, vector<vector<bool>>(M, vector<bool>(1 << 6, false)));
	visited[sx][sy][0] = true;

	while (!q.empty()) {
		Pos cur = q.front(); q.pop();
		if (grid[cur.x][cur.y] == '1')return cur.steps;

		for (int i = 0; i < 4; ++i) {
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];
			int nkeys = cur.keys;

			if (nx >= 0 && nx < N && ny >= 0 && ny < M && !visited[nx][ny][nkeys]) {
				char cell = grid[nx][ny];
				if (cell == '1' || cell == '.') {
					visited[nx][ny][nkeys] = true;
					q.push({ nx,ny,cur.steps + 1,nkeys });
				}
				else if (cell >= 'a' && cell <= 'f') {
					int newKeys = nkeys | (1 << (cell - 'a'));
					visited[nx][ny][newKeys] = true;
					q.push({ nx,ny,cur.steps + 1,newKeys });
				}
				else if (cell >= 'A' && cell <= 'Z') {
					if (hasKey(nkeys, cell)) {
						visited[nx][ny][nkeys] = true;
						q.push({ nx,ny,cur.steps + 1,nkeys });
					}
				}
			}
		}
	};
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	vector<string> grid(N);
	int sx = 0, sy = 0;

	for (int i = 0; i < N; ++i) {
		cin >> grid[i];
		for (int j = 0; j < M; ++j) {
			if (grid[i][j] == '0') {
				sx = i;
				sy = j;
				grid[i][j] = '.';
			}
		}
	}
	cout << bfs(sx, sy, grid, N, M) << '\n';
	return 0;
}