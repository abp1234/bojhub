#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M, x1, y1, x2, y2;
	char temp;
	cin >> N >> M >> y1 >> x1 >> y2 >> x2;
	vector<vector<int>>arr(N, vector<int>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> temp;
			if (temp == '#') {
				arr[i][j] = 3;
			}
			else if (temp == '*') {
				arr[i][j] = 2;
			}
			else {
				arr[i][j] = temp-'0';
			}
		}
	} 
	
	int diry[] = { 0,0,-1,1 };
	int dirx[] = { -1,1,0,0 };
	queue<int> q;
	queue<int> next_q;
	int dy, dx, y, x,dir,turn;
	q.push((y1-1) * 1000 + (x1-1));
	turn = 1;
	int flag = 0;
	while (1) {
		while (!q.empty()) {
			dir = q.front();
			q.pop();
			y = dir / 1000;
			x = dir % 1000;
			for (int i = 0; i < 4; i++) {
				dy = diry[i] + y;
				dx = dirx[i] + x;
				if (dy < 0 || dx < 0 || dx >= M || dy >= N) continue;
				if (arr[dy][dx] == 3) {
					flag = 1;
					break;
				}
				else if (arr[dy][dx] == 1) {
					next_q.push(dy * 1000 + dx);
					arr[dy][dx] = 2;
				}
				else if (arr[dy][dx] == 0) {
					q.push(dy * 1000 + dx);
					arr[dy][dx] = 2;
				}
			}
			if (flag == 1) {
				break;
			}
		}
		if (flag == 1) {
			break;
		}
		turn++;
		q = next_q;
		next_q=queue<int>();
	}
	cout << turn;
	return 0;
}