#include <string>
#include <vector>
#include <map>
using namespace std;

int n, m;
vector<string> board;
vector<vector<int>> RankCnt;  // 1: 접근 가능, 2: 접근 불가능, 0: 제거됨
map<char, vector<pair<int, int>>> Coldi;  // 각 알파벳별 컨테이너 좌표 저장

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

// 범위를 벗어나는지 확인하는 함수
bool isOut(int x, int y) {
    return (x < 0 || y < 0 || x >= n || y >= m);
}

// 현재 board 상태를 기준으로 (x, y) 컨테이너가 외부(경계 또는 빈 칸)와 맞닿아 있는지 판단
bool isAccessible(int x, int y) {
    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d], ny = y + dy[d];
        if (isOut(nx, ny)) return true;       // 외곽과 접촉
        if (board[nx][ny] == '.') return true;  // 인접 셀이 빈 칸이면 외부와 연결됨
    }
    return false;
}

// (x, y)에서 컨테이너가 제거된 후, 인접 셀(컨테이너)을 확인하여 접근성이 바뀌었으면 RankCnt를 갱신
void updateAdjacent(int x, int y) {
    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d], ny = y + dy[d];
        if (!isOut(nx, ny) && board[nx][ny] != '.') {
            // 인접 셀이 현재 빈 칸 또는 외곽과 인접해 있다면 접근 가능하게 업데이트
            if (isAccessible(nx, ny)) {
                RankCnt[nx][ny] = 1;
            }
        }
    }
}

int solution(vector<string> storage, vector<string> requests) {
    // 초기 설정: board, RankCnt, Coldi 구성
    n = storage.size();
    m = storage[0].size();
    board = storage;
    RankCnt.assign(n, vector<int>(m, 2));
    Coldi.clear();
    
    // 각 셀에 대해 컨테이너의 접근 가능 여부와 해당 알파벳의 좌표를 저장
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (board[i][j] != '.'){
                if (isAccessible(i, j))
                    RankCnt[i][j] = 1;  // 접근 가능
                else
                    RankCnt[i][j] = 2;  // 접근 불가능
                Coldi[ board[i][j] ].push_back({i, j});
            }
        }
    }
    
    // 요청 순서대로 처리
    for (const string &req : requests) {
        char target = req[0];
        if (req.size() == 1) {  // 지게차: 접근 가능한 컨테이너만 제거
            vector<pair<int, int>> remain;  // 제거하지 않은 좌표 저장
            for (auto &coord : Coldi[target]) {
                int x = coord.first, y = coord.second;
                // 아직 남아 있고, 접근 가능하면 제거
                if (board[x][y] == target && RankCnt[x][y] == 1) {
                    board[x][y] = '.';
                    RankCnt[x][y] = 0;
                    updateAdjacent(x, y);
                } else if (board[x][y] == target) {
                    remain.push_back({x, y});
                }
            }
            Coldi[target] = remain;
        } else {  // 크레인: 해당 알파벳 컨테이너 전부 제거
            for (auto &coord : Coldi[target]) {
                int x = coord.first, y = coord.second;
                if (board[x][y] == target) {
                    board[x][y] = '.';
                    RankCnt[x][y] = 0;
                    updateAdjacent(x, y);
                }
            }
            Coldi[target].clear();
        }
    }
    
    // 최종적으로 남은 컨테이너의 수를 세기
    int answer = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (board[i][j] != '.')
                answer++;
        
        }
    }

    return answer;
}
