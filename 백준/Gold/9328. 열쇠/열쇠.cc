#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <queue>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	int h, w;
	cin >> T;
	while (T--) {
		cin >> h >> w;
		vector<vector<char>>arr(h, vector<char>(w));
		vector<int>visit(26);
		deque<int>q;
		int cnt = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> arr[i][j];
				if (arr[i][j] >= 'a' && arr[i][j] <= 'z') {
					visit[arr[i][j] - 'a'] = 1;
				}
			}
		}
		string ky;
		vector<int>key_real(26);
		cin >> ky;
		if (ky != "0") {
			for (auto i = 0; i < ky.size(); i++) {
				key_real[ky[i] - 'a'] = 1;
			}
		}
		vector<vector<int>>later(26);
		
		for (int i = 0; i < w; i++) {
			if (arr[0][i] >= 'a' && arr[0][i] <= 'z') {
				key_real[arr[0][i] - 'a'] = 1;
				q.push_back(i);
			}
			if (arr[h - 1][i] >= 'a' && arr[h - 1][i] <= 'z') {
				key_real[arr[h - 1][i] - 'a'] = 1;
				q.push_back((h - 1) * 1000 + i);
			}
		}
		for (int i = 0; i < h; i++) {
			if (arr[i][0] >= 'a' && arr[i][0] <= 'z') {
				key_real[arr[i][0] - 'a'] = 1;
				q.push_back(i * 1000);
			}
			if (arr[i][w - 1] >= 'a' && arr[i][w - 1] <= 'z') {
				key_real[arr[i][w - 1] - 'a'] = 1;
				q.push_back(i * 1000 + w - 1);
			}
		}
		for (int i = 0; i < h; i++) {
			if (arr[i][0] == '.') {
				q.push_back(i * 1000);
				arr[i][0] = '*';
			}
			else if (arr[i][0] >= 'A' && arr[i][0] <= 'Z') {
				if (key_real[arr[i][0] - 'A'] == 1) {
					q.push_back(i * 1000);
				}
				else {
					later[arr[i][0] - 'A'].push_back(i * 1000);
				}arr[i][0] = '*';
			}
			else if (arr[i][0] == '$') {
				cnt++;
				q.push_back(i * 1000);
				arr[i][0] = '*';
			}
			if (arr[i][w - 1] == '.') {
				q.push_back(i * 1000 + w - 1);
				arr[i][w - 1] = '*';
			}
			else if (arr[i][w - 1] >= 'A' && arr[i][w - 1] <= 'Z') {
				if (key_real[arr[i][w - 1] - 'A'] == 1) {
					q.push_back(i * 1000 + w - 1);
				}
				else {
					later[arr[i][w - 1] - 'A'].push_back(i * 1000 + w - 1);
				}arr[i][w - 1] = '*';
			}
			else if (arr[i][w - 1] == '$') {
				cnt++;
				q.push_back(i * 1000 + w - 1);
				arr[i][w - 1] = '*';
			}
		}

		for (int i = 0; i < w; i++) {
			if (arr[h - 1][i] == '.') {
				q.push_back((h - 1) * 1000 + i);
				arr[h - 1][i] = '*';
			}
			else if (arr[h - 1][i] >= 'A' && arr[h - 1][i] <= 'Z') {
				if (key_real[arr[h - 1][i] - 'A'] == 1) {
					q.push_back((h - 1) * 1000 + i);
				}
				else {
					later[arr[h - 1][i] - 'A'].push_back((h - 1) * 1000 + i);
				}arr[h - 1][i] = '*';
			}
			else if (arr[h - 1][i] == '$') {
				cnt++;
				q.push_back((h - 1) * 1000 + i);
				arr[h - 1][i] = '*';
			}
			if (arr[0][i] == '.') {
				q.push_back(i);
				arr[0][i] = '*';
			}
			else if (arr[0][i] >= 'A' && arr[0][i] <= 'Z') {
				if (key_real[arr[0][i] - 'A'] == 1) {
					q.push_back(i);
				}
				else {
					later[arr[0][i] - 'A'].push_back(i);
				}arr[0][i] = '*';
			}
			else if (arr[0][i] == '$') {
				cnt++;
				q.push_back(i);
				arr[0][i] = '*';
			}
		}
	
		
		int diry[] = { 0,0,-1,1 };
		int dirx[] = { -1,1,0,0 };
		while (!q.empty()) {
			int idx = q.front();
			q.pop_front();


			for (int i = 0; i < 4; i++) {
				int dy = diry[i] + idx / 1000;
				int dx = dirx[i] + idx % 1000;
				if (dx < 0 || dy < 0 || dx >= w || dy >= h)continue;
				if (arr[dy][dx] == '.') {
					arr[dy][dx] = '*';
					q.push_back(dy * 1000 + dx);
				}else if (arr[dy][dx] >= 'A' && arr[dy][dx] <= 'Z') {
					if (key_real[arr[dy][dx] - 'A'] == 1) {
						arr[dy][dx] = '*';
						q.push_back(dy * 1000 + dx);
					}
					else {
						if (visit[arr[dy][dx] - 'A'] == 1) {
							later[arr[dy][dx] - 'A'].push_back(dy * 1000 + dx);
						}
						arr[dy][dx] = '*';
					}

				}else if (arr[dy][dx] >= 'a' && arr[dy][dx] <= 'z') {
					key_real[arr[dy][dx] - 'a'] = 1;
					q.push_back(dy * 1000 + dx);
					if (!later[arr[dy][dx] - 'a'].empty()) {
						for (auto l = 0; l < later[arr[dy][dx] - 'a'].size(); l++) {
							q.push_back(later[arr[dy][dx] - 'a'][l]);
						}
						later[arr[dy][dx] - 'a'].clear();
					}
					arr[dy][dx] = '*';
				}else if (arr[dy][dx] == '$') {
					arr[dy][dx] = '*';
					q.push_back(dy * 1000 + dx);
					cnt++;
				}
			}
		}
		arr.clear();
		later.clear();
		q.clear();
		cout << cnt << "\n";
	}

	
	return 0;
}