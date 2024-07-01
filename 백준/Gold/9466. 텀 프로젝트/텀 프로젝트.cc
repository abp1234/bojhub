#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int n, temp;
		cin >> n;
		vector<int>arr(n);
		for (int i = 0; i < n; i++) {
			cin >> temp;
			arr[i]=temp-1;
		}
		vector<int>check(n,-1);
		vector<int>visited(n, -1);
		int cnt = 0;
		int s_cnt = 0;
		deque<int>q;
		for (int i = 0; i < n; i++) {
			if (check[i] == -1) {
				q.push_back(i);
				check[i] = s_cnt;
				while (!q.empty()) {
					int idx=q.front();
					q.pop_front();
					if (check[arr[idx]] == -1) {
						check[arr[idx]] = s_cnt;
						q.push_back(arr[idx]);
					}
					else if (check[arr[idx]] == s_cnt && visited[arr[idx]]==-1) {
						visited[arr[idx]] = s_cnt;
						q.push_back(arr[idx]);
					}
				}
				s_cnt++;
			}
		}
		for (int i = 0; i < n; i++) {
			if (visited[i] == -1)cnt++;
		}
		cout << cnt << "\n";
	}


	return 0;
}