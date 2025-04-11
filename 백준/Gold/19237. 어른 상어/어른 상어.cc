#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MX = 20;
int n, m, k;

struct Sm {
    int id, t;
};
Sm sm[MX][MX];

int bd[MX][MX];

struct Sh {
    int x, y, d;
    bool live;
};
Sh sh[401];

vector<int> prf[401][5];

int mv[5][2] = {
    {0, 0},
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}
};

int clv = 0;

int rd() {
    int x;
    cin >> x;
    return x;
}

int fx(int i, int j) {
    return sm[i][j].t > 0;
}

void us() {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (sm[i][j].t > 0) {
                if (--sm[i][j].t == 0)
                    sm[i][j].id = 0;
            }
    for (int i = 1; i <= m; ++i) {
        if (!sh[i].live) continue;
        int x = sh[i].x, y = sh[i].y;
        sm[x][y] = {i, k};
    }
}

void mvsh() {
    Sh tmp[401];
    for (int i = 1; i <= m; ++i) tmp[i] = sh[i];
    int vis[MX][MX];
    memset(vis, 0, sizeof(vis));

    for (int i = 1; i <= m; ++i) {
        if (!tmp[i].live) continue;
        int x = tmp[i].x, y = tmp[i].y, d = tmp[i].d;
        bool mvd = false;
        for (int nd : prf[i][d]) {
            int nx = x + mv[nd][0], ny = y + mv[nd][1];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (!sm[nx][ny].t) {
                if (!vis[nx][ny] || vis[nx][ny] > i) {
                    sh[i] = {nx, ny, nd, true};
                    vis[nx][ny] = i;
                } else {
                    sh[i].live = false;
                    clv++;
                }
                mvd = true;
                break;
            }
        }
        if (!mvd) {
            for (int nd : prf[i][d]) {
                int nx = x + mv[nd][0], ny = y + mv[nd][1];
                if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                if (sm[nx][ny].id == i) {
                    sh[i] = {nx, ny, nd, true};
                    break;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> k;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            int x;
            cin >> x;
            if (x) sh[x] = {i, j, 0, true};
            bd[i][j] = x;
        }

    for (int i = 1; i <= m; ++i) {
        cin >> sh[i].d;
    }

    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= 4; ++j)
            for (int l = 0; l < 4; ++l) {
                int x;
                cin >> x;
                prf[i][j].push_back(x);
            }

    for (int i = 1; i <= m; ++i) {
        int x = sh[i].x, y = sh[i].y;
        sm[x][y] = {i, k};
    }

    int t = 0;
    while (t <= 1000) {
        if (clv == m - 1) break;
        mvsh();
        us();
        ++t;
    }

    cout << (t > 1000 ? -1 : t) << '\n';
    return 0;
}
