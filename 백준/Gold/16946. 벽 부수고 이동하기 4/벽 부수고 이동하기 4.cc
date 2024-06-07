#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	vector<vector<int>>arr(N,vector<int>(M));
	vector<int>check(N * M);
	string ipt;
	for (int i = 0; i < N; i++) {
		cin >> ipt;
		for (int j = 0; j < M; j++) {
			arr[i][j]=ipt[j]-'0';
		}
	}
	int diry[] = { 0,0,-1,1 };
	int dirx[] = { -1,1,0,0 };
	deque<int>q;
	int cnt = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j]==0) {
				
				cnt++;
				arr[i][j] = cnt;
				check[cnt] = 1;
				q.push_back(i * 1000 + j);
				int idx;
				while (!q.empty()) {
					idx=q.front();
					q.pop_front();
					for (int l = 0; l < 4; l++) {
						int dy = diry[l] + idx / 1000;
						int dx = dirx[l] + idx % 1000;
						if (dy < 0 || dx < 0 || dy >= N || dx >= M)continue;
						if (arr[dy][dx] == 0) {
							
							arr[dy][dx] = cnt;
							check[cnt]++;
							q.push_back(dy * 1000 + dx);
						}
					}

				}
			}
		}
	}
	vector<vector<int>>answer(N, vector<int>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 1) {
				vector<int>duplication;
				answer[i][j]++;
				for (int l = 0; l < 4; l++) {
					int dy = diry[l] + i;
					int dx = dirx[l] + j;
					if (dy < 0 || dx < 0 || dy >= N || dx >= M)continue;
					int flag = 0;
					for (auto k : duplication) {
						if (k == arr[dy][dx]) {
							flag = 1;
							break;
						}
					}
					if (flag == 1)continue;
					duplication.push_back(arr[dy][dx]);
					answer[i][j] +=check[arr[dy][dx]];
				}
			}
			cout << answer[i][j]%10;
		}
		cout << '\n';
	}
	return 0;
}