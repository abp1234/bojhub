#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct Node { int rx, ry, bx, by, d; };

int N, M;
vector<string> board;
bool visited[10][10][10][10];

int dx[4] = { -1, 0, 1, 0 };   
int dy[4] = {  0, 1, 0,-1 };

void moveM(int& x, int& y, int dir,
           int ox, int oy, bool& out)
{
    while (true) {
        int nx = x + dx[dir], ny = y + dy[dir];
        if (board[nx][ny] == '#') break;
        if (nx == ox && ny == oy) break;
        x = nx; y = ny;
        if (board[nx][ny] == 'O') { out = true; break; }
    }
}

bool check(const Node& cur, int dir,
           Node& nxt, bool& rOut, bool& bOut)
{
    int rx = cur.rx, ry = cur.ry;
    int bx = cur.bx, by = cur.by;
    rOut = bOut = false;

    
    bool redF =
        (dir == 0 && rx < bx) ||   
        (dir == 1 && ry > by) ||  
        (dir == 2 && rx > bx) ||  
        (dir == 3 && ry < by);     

    if (redF) {                
        moveM(rx, ry, dir, bx, by, rOut);
        moveM(bx, by, dir,
              rOut ? -1 : rx, rOut ? -1 : ry,
              bOut);
    } else {                 
        moveM(bx, by, dir, rx, ry, bOut);
        moveM(rx, ry, dir,
              bOut ? -1 : bx, bOut ? -1 : by,
              rOut);
    }

    if (!rOut && !bOut && rx == bx && ry == by) return false;
    nxt = { rx, ry, bx, by, cur.d + 1 };
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    board.resize(N);
    for (auto& row : board) cin >> row;

    Node start{};
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j) {
            if (board[i][j] == 'R') { start.rx = i; start.ry = j; board[i][j] = '.'; }
            if (board[i][j] == 'B') { start.bx = i; start.by = j; board[i][j] = '.'; }
        }

    queue<Node> q; q.push(start);
    visited[start.rx][start.ry][start.bx][start.by] = true;

    while (!q.empty()) {
        Node cur = q.front(); q.pop();
        if (cur.d >= 10) continue;

        for (int d = 0; d < 4; ++d) {
            Node nxt; bool rOut, bOut;
            if (!check(cur, d, nxt, rOut, bOut)) continue;
            if (bOut) continue;      
            if (rOut) {               
                cout << 1 << '\n';
                return 0;
            }
            if (!visited[nxt.rx][nxt.ry][nxt.bx][nxt.by]) {
                visited[nxt.rx][nxt.ry][nxt.bx][nxt.by] = true;
                q.push(nxt);
            }
        }
    }
    cout << 0 << '\n';
    return 0;
}
