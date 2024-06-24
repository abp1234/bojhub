#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <tuple>
using namespace std;
//const int INF = numeric_limits<int>::max();
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	cin >> M >> N;
	int cnt = 0;
	int end_cnt = M * N;
	int max_day = 0;
	int diry[] = { 0,0,-1,1 };
	int dirx[] = { 1,-1,0,0 };
	deque<tuple<int,int>>q;
	
	vector<vector<int>>arr(N, vector<int>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				//arr[i][j] = INF;
				q.push_back(make_tuple(i * 10000 + j,0));
				cnt++;
			}
			else if (arr[i][j] == -1)cnt++;
		}
	}
	
	int idx, day;
	while (!q.empty()) {
		tie(idx,day) = q.front();
		q.pop_front();

		for (int i = 0; i < 4; i++) {
			int dy = diry[i] + idx/10000;
			int dx = dirx[i] + idx%10000;
			if (dy < 0 || dx < 0 || dy >= N || dx >= M)continue;
			if (arr[dy][dx] == 0) {
				arr[dy][dx] = 1;
				
				q.push_back(make_tuple(dy * 10000 + dx,day+1));
				max_day = max(day+1, max_day);
				cnt++;
			}
		}
	}
	if (end_cnt == cnt) {
		cout << max_day;
	}
	else {
		cout << -1;
	}
		
	return 0;
}