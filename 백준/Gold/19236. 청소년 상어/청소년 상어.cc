#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

struct Cell {
    int num, dir;
};

int dx[8] = {-1, -1, 0, 1, 1,1,0, -1};
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};

int mx = 0;

using Board = vector<vector<Cell>>;

Board copyBoard(const Board &b) {
    Board nb(4, vector<Cell>(4));
    for (int i = 0; i <4;++i)
        for (int j = 0; j <4;++j)
            nb[i][j] = b[i][j];
    return nb;
}

void dfs(int sx, int sy, int sc,Board b) {
    sc += b[sx][sy].num;
    b[sx][sy].num = 0;
    mx = max(mx, sc);

    for (int f = 1; f<= 16;++f) {
        int fx = -1, fy = -1;
        for (int i = 0; i< 4 && fx == -1; ++i)
            for (int j = 0; j< 4; ++j)
                if (b[i][j].num == f) {
                    fx = i, fy = j;
                    break;
                }
        if (fx == -1) continue;

        int fd = b[fx][fy].dir;
        for (int i = 0; i < 8; ++i) {
            int nd = (fd + i) % 8;
            int nx = fx + dx[nd], ny =fy+dy[nd];
            if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4 || (nx==sx&&ny == sy)) continue;
            b[fx][fy].dir = nd;
            swap(b[fx][fy],b[nx][ny]);
            break;
        }
    }

    int sd = b[sx][sy].dir;
    for (int i = 1; i <= 4; ++i) {
        int nx = sx + dx[sd]* i;
        int ny = sy + dy[sd]* i;
        if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4) break;
        if (b[nx][ny].num == 0)continue;
        dfs(nx, ny, sc, copyBoard(b));
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Board bd(4, vector<Cell>(4));
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j) {
            int n, d;
            cin >> n >> d;
            bd[i][j] = {n, d - 1};
        }

    dfs(0, 0, 0, bd);
    cout << mx << '\n';
    return 0;
}
