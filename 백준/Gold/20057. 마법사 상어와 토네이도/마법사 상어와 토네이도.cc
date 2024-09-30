#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Pos {
	int x, y, d;
};

int bfs(int x, int y, int d, int N, vector<vector<int>>& brd) {
    vector<pair<int, int>> dv = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} }; 

    vector<pair<int, int>> sv = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-2, 0}, {0, 2}, {2, 0}, {0, -2} };
    vector<int> sp = { 1, 1, 2, 2, 5, 7, 7, 10, 10, 0 }; 

    vector<vector<int>> s = {
        {5, 3, 11, 9, 8, 6, 2, 7, 1, 0},
        {7, 5, 8, 10, 9, 0, 4, 1, 3, 2},
        {7, 1, 9, 11, 10, 6, 2, 5, 3, 4},
        {1, 3, 8, 10, 11, 0, 4, 7, 5, 6}
    };

    vector<vector<int>> vis(N, vector<int>(N, 0));
    queue<Pos> q;
    q.push({ x,y,d });
    vis[x][y] = 1;

    int ans = 0;

    while (!q.empty()) {
        Pos cur = q.front(); q.pop();
        x = cur.x; y = cur.y; d = cur.d;

        int nd = (d + 3) % 4;

        int nx = x + dv[nd].first;
        int ny = y + dv[nd].second;

        if (nx >= 0 && nx < N && ny >= 0 && ny < N && vis[nx][ny] == 0) {
            vis[nx][ny] = 1;
            q.push({ nx,ny,nd });
        }
        else {
            nx = x + dv[d].first;
            ny = y + dv[d].second;
            if (nx >= 0 && nx < N && ny >= 0 && ny < N && vis[nx][ny] == 0) {
                vis[nx][ny] = 1;
                q.push({ nx,ny,d });
                nd = d;
            }
            else {
                continue;
            }
        }


        if (brd[nx][ny] == 0)continue;
        double per = brd[nx][ny] / 100.0;

        for (int i = 0; i < 10; ++i) {
            int sx = nx + sv[s[nd][i]].first;
            int sy = ny + sv[s[nd][i]].second;

            if (sx >= 0 && sx < N && sy >= 0 && sy < N) {
                if (sp[i] == 0) {
                    brd[sx][sy] += brd[nx][ny];
                    brd[nx][ny] = 0;
                    break;
                }
                brd[sx][sy] += int(per * sp[i]);
                brd[nx][ny] -= int(per * sp[i]);
            }
            else {
                if (sp[i] == 0) {
                    ans += brd[nx][ny];
                    brd[nx][ny] = 0;
                    break;
                }
                ans += int(per * sp[i]);
                brd[nx][ny] -= int(per * sp[i]);
            }
        }
    }

    return ans;
}

int main() {
    int N;
    cin >> N;
    vector<vector<int>> brd(N, vector<int>(N));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> brd[i][j];
        }
    }

    int x = N / 2, y = N / 2, d = 0;
    cout << bfs(x, y, d, N, brd) << '\n';

    return 0;
}