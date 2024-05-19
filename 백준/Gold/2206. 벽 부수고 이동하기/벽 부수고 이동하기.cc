#include <iostream>
#include <vector>
#include<limits>
#include <queue>
#include <tuple>
#include <string>
using namespace std;
const int INF = numeric_limits<int>::max();
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M, temp;
	cin >> N >> M;
	vector<vector<int>>arr(N, vector<int>(M));
	vector<vector<int>>visit(N, vector<int>(M));
	vector<vector<int>>check(N, vector<int>(M, INF));
	for (int i = 0; i < N; i++) {
		string line;
		cin >> line;
		for (int j = 0; j < M; j++) {

			arr[i][j] = line[j] - '0';
		}
	}
	priority_queue<tuple<int, int,int>>q;
	q.push(make_tuple(0, 0,0));
	check[0][0] = 0;
	int diry[] = { 0,0,-1,1 };
	int dirx[] = { -1, 1, 0, 0 };
	int now, cost, use;
	while (!q.empty()) {
		tie(cost, now,use) = q.top();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int dy = diry[i] + now / 1000;
			int dx = dirx[i] + now % 1000;
			if (dy < 0 || dx < 0 || dy >= N || dx >= M)continue;
			if (arr[dy][dx] == 0) {
				if (check[dy][dx] > -cost + 1) {
					check[dy][dx] = -cost + 1;
					q.push(make_tuple(cost - 1, dy * 1000 + dx, use));
					
				}
				else if (use == 0 && visit[dy][dx]==0) {
					visit[dy][dx] = 1;
					q.push(make_tuple(cost - 1, dy * 1000 + dx, use));
				}
			}
			else if(use==0&& check[dy][dx] > -cost+ 1) {
				check[dy][dx] = -cost + 1;
				q.push(make_tuple(cost - 1, dy * 1000 + dx, 1));
			}
		}

	}
	if (check[N - 1][M - 1] == INF) {
		cout << -1;
		return 0;
	}
	cout << check[N - 1][M - 1]+1;


	return 0;
}
