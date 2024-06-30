#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	vector<vector<char>>arr(N, vector<char>(M));
	vector<vector<int>>check(N, vector<int>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	int diry[] = { 0,0,-1,1 };
	int dirx[] = { -1,1,0,0 };
	int cnt = 1;
	int result = 0;
	deque<int>q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (check[i][j] == 0) {
				q.push_back(i * 10000 + j);
				//check[i][j] = cnt;
				while (!q.empty()) {
					int idx = q.front();
					q.pop_front();
					if (idx / 10000 < 0 || idx / 10000 >= N || idx % 10000 < 0 || idx % 10000 >= M)continue;
					if (check[idx / 10000][idx % 10000] == 0) {
						check[idx / 10000][idx % 10000] = cnt;
						if (arr[idx / 10000][idx % 10000] == 'D') {
							q.push_back((idx / 10000 + 1) * 10000 + idx % 10000);
						}
						else if (arr[idx / 10000][idx % 10000] == 'U') {
							q.push_back((idx / 10000 - 1) * 10000 + idx % 10000);
						}
						else if (arr[idx / 10000][idx % 10000] == 'L') {
							q.push_back((idx / 10000 ) * 10000 + idx % 10000-1);
						}
						else if (arr[idx / 10000][idx % 10000] == 'R') {
							q.push_back((idx / 10000 ) * 10000 + idx % 10000+1);
						}
					}
					else {
						if (check[idx / 10000][idx % 10000] == cnt) {
							result++;
						}
					}
				}
				cnt++;
			}
		}
	}

	cout << result;
	return 0;
}